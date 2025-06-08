
#include "LineDictionary.h"

namespace filamat {

std::string_view LineDictionary::getString(size_t index) const noexcept {
    return *mStrings[index];
}

size_t LineDictionary::getLineCount() const {
    return mStrings.size();
}

size_t LineDictionary::getIndex(std::string_view s) const noexcept {
    if (auto iter = mLineIndices.find(s); iter != mLineIndices.end()) {
        return iter->second;
    }
    return SIZE_MAX;
}

void LineDictionary::addText(const std::string& line) noexcept {
    const char* s = line.c_str();

    size_t cur = 0;
    size_t pos = 0;
    size_t len = 0;

    while (s[cur] != '\0') {
        pos = cur;
        len = 0;
        while (s[cur] != '\n') {
            cur++;
            len++;
        }
        std::string newLine(s + pos, len);
        addLine(std::move(newLine));
        cur++;
    }
}

void LineDictionary::addLine(const std::string&& line) noexcept {
    // Never add a line twice.
    if (mLineIndices.find(line) != mLineIndices.end()) {
        return;
    }
    mStrings.emplace_back(std::make_unique<std::string>(line));
    mLineIndices.emplace(*mStrings.back(), mStrings.size() - 1);
}

} // namespace filamat
