
#include "JsonishParser.h"

#include <stdlib.h>

#include <iostream>

#include <string.h>

#include "third_party/filament/libs/utils/include/utils/string.h"

namespace matc {

static std::string resolveEscapes(const std::string& s) {
    std::string out;
    out.reserve(s.length());

    bool inEscape = false;
    for (char c : s) {
        if (inEscape) {
            switch (c) {
                case '\\':
                    out += '\\';
                    break;
                case '/':
                    out += '\u002F';
                    break;
                case 't':
                    out += '\t';
                    break;
                case 'r':
                    out += '\r';
                    break;
                case 'n':
                    out += '\n';
                    break;
                case 'f':
                    out += '\f';
                    break;
                case 'b':
                    out += '\b';
                    break;
                case '"':
                    out += '"';
                    break;
                case 'u':
                    // TODO: implement unicode escape sequences
                    std::cerr << "Unicode escape sequences currently not supported." << std::endl;
                    break;
                default:
                    std::cerr << "Invalid escape sequence \\" << c << "." << std::endl;
                    return out;
            }
            inEscape = false;
        } else {
            if (c == '\\') {
                inEscape = true;
                continue;
            } else {
                out += c;
            }
        }
    }

    if (inEscape) {
        std::cerr << "Incomplete escape sequence." << std::endl;
    }

    return out;
}

JsonishString::JsonishString(const std::string& string) : JsonishValue(STRING) {
    mString = resolveEscapes(string);
}

std::unique_ptr<JsonishObject> JsonishParser::parse() noexcept {
    std::unique_ptr<JsonishObject> p(parseObject());
    return p;
}

JsonishObject* JsonishParser::parseObject() noexcept {
    // Read the {
    if (!consumeLexeme(JsonType::BLOCK_START)) {
        reportError("expected token '{'");
        return nullptr;
    }

    // Empty blocks are allowed.
    if (consumeLexeme(BLOCK_END)) {
        return new JsonishObject();
    }

    // Read members.
    JsonishObject* object = parseMembers();

    // Read the }
    if (!consumeLexeme(JsonType::BLOCK_END)) {
        reportError("expected token '}'");
        delete object;
        return nullptr;
    }

    return object;
}

JsonishArray* JsonishParser::parseArray() noexcept {
    // Read the [
    if (!consumeLexeme(JsonType::ARRAY_START)) {
        reportError("expected token '['");
        return nullptr;
    }

    // Empty arrays are allowed.
    if (consumeLexeme(ARRAY_END))  {
        return new JsonishArray();
    }

    // Read elements.
    JsonishArray* array = parseElements();

    // Read the ]
    if (!consumeLexeme(JsonType::ARRAY_END)) {
        reportError("expected token ']'");
        delete array;
        return nullptr;
    }

    return array;
}

JsonishPair JsonishParser::parsePair() noexcept {
    JsonishPair pair {"" , nullptr};
    // Read key string.
    const JsonLexeme* keyLexeme = consumeLexeme(JsonType::STRING);
    if (!keyLexeme) {
        return pair;
    }

    // Read the :
    if (!consumeLexeme(JsonType::COLUMN)) {
        return pair;
    }

    // Read the value.
    JsonishValue* value = parseValue();
    if (!value) {
        return pair;
    }

    pair = {keyLexeme->getStringValue(), value};
    return pair;
}

const JsonLexeme* JsonishParser::consumeLexeme(JsonType type) noexcept {
    if (mCursor >= mLexemes.size()) {
        return nullptr;
    }
    const JsonLexeme* lexeme = &mLexemes[mCursor];

    if (lexeme->getType() == type) {
        mCursor++;
        return lexeme;
    } else {
        return nullptr;
    }
}

const JsonLexeme* JsonishParser::peekNextLexemeType() const noexcept {
    if (mCursor >= mLexemes.size()) {
        return nullptr;
    }
    return &mLexemes[mCursor];
}

const JsonLexeme* JsonishParser::peekCurrentLexemeType() const noexcept {
    if (mCursor <= 0) {
        return nullptr;
    }
    return &mLexemes[mCursor - 1];
}

JsonishObject* JsonishParser::parseMembers() noexcept {
    JsonishObject* object = new JsonishObject();
    while (true) {
        JsonishPair pair = parsePair();
        if (!pair.value) {
            // Accept a comma after the last element
            const JsonLexeme* lexeme = peekNextLexemeType();
            if (lexeme && lexeme->getType() == BLOCK_END) {
                break;
            }

            reportError("unable to parse pair");

            delete object;
            return nullptr;
        }

        object->addPair(pair);

        // Is there a comma and more pairs?
        if (!consumeLexeme(COMMA)) {
            break;
        }
    }
    return object;
}

JsonishArray* JsonishParser::parseElements() noexcept {
    JsonishArray* array = new JsonishArray();

    while (true) {
        JsonishValue* value = parseValue();
        if (!value) {
            reportError("unable to read value");
            delete array;
            return nullptr;
        }
        array->addValue(value);

        // Is there a comma and more pairs?
        if (!consumeLexeme(COMMA)) {
            break;
        }
    }

    return array;
}

// Strings optionally have an array suffix, as in: "float[9]". To handle this we parse the array
// value (which might be multidimensional), discard the parsed value, and append it to the string.
JsonishValue* JsonishParser::parseString() noexcept {
    std::string tmp;
    const JsonLexeme* strLexeme = consumeLexeme(STRING);
    const JsonLexeme* arrLexeme = peekNextLexemeType();
    JsonishValue* arrValue;
    if (arrLexeme && arrLexeme->getType() == ARRAY_START && (arrValue = parseArray())) {
        delete arrValue;

        const JsonLexeme* next = peekNextLexemeType();
        if (!next) {
            return nullptr;
        }

        size_t length = next->getStart() - strLexeme->getStart();
        tmp = std::string(strLexeme->getStart(), length);
    } else {
        tmp = std::string(strLexeme->getStart(), strLexeme->getSize());
    }
    return new JsonishString(tmp);
}

JsonishValue* JsonishParser::parseValue() noexcept {
    const JsonLexeme* next = peekNextLexemeType();
    if (next == nullptr) {
        return nullptr;
    }

    switch (next->getType()) {
        case STRING:
            return parseString();
        case NUMBER:
            consumeLexeme(NUMBER);
            return new JsonishNumber(utils::strtof_c(next->getStart(), nullptr));
        case BLOCK_START:
            return parseObject();
        case ARRAY_START:
            return parseArray();
        case BOOLEAN:
            consumeLexeme(BOOLEAN);
            return new JsonishBool(!strncmp(next->getStart(), "true", next->getSize()));
        case NUll:
            consumeLexeme(NUll);
            return new JsonishNull();
        default:
            reportError("unexpected token");
            return nullptr;
    }
}

void JsonishParser::reportError(const char* message) noexcept {
    if (mErrorReported) {
        return;
    }

    std::cerr << "Syntax error, " << message;

    const JsonLexeme* lexeme = peekNextLexemeType();
    if (lexeme == nullptr) {
        lexeme = peekCurrentLexemeType();
    }

    if (lexeme != nullptr) {
        std::cerr << " at line:" << lexeme->getLine()
               << " position:" << lexeme->getLinePosition() << std::endl
               << "  got lexeme type: "
               << JsonLexeme::getTypeString(lexeme->getType()) << std::endl
               << "  got lexeme value: " << lexeme->getStringValue() << std::endl;
    } else {
        std::cerr << " but reached end of file instead." << std::endl;
    }

    mErrorReported = true;
}

} // namespace matc
