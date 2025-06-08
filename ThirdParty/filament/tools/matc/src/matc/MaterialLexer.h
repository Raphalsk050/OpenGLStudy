
#ifndef TNT_MATERIALLEXER_H
#define TNT_MATERIALLEXER_H

#include "Lexer.h"
#include "MaterialLexeme.h"

namespace matc {

class MaterialLexer final: public Lexer<MaterialLexeme> {
public:
private:

    virtual bool readLexeme() noexcept override;

    bool peek(MaterialType* type) const noexcept;

    bool readBlock() noexcept;
    void readIdentifier() noexcept;
    void readUnknown() noexcept;
};

}

#endif //TNT_MATERIALLEXER_H
