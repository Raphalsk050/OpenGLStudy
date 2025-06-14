
#ifndef TNT_SCAHELPERS_H_H
#define TNT_SCAHELPERS_H_H

#include <string>
#include <vector>
#include "glslang/Include/intermediate.h"

class TIntermNode;

namespace ASTHelpers {

class NodeToString : public glslang::TIntermTraverser {
    void pad();
public:
    using TVisit = glslang::TVisit;
    bool visitBinary(TVisit, glslang::TIntermBinary* node) override;
    bool visitUnary(TVisit, glslang::TIntermUnary* node) override;
    bool visitAggregate(TVisit, glslang::TIntermAggregate* node) override;
    bool visitSelection(TVisit, glslang::TIntermSelection*) override;
    void visitConstantUnion(glslang::TIntermConstantUnion*) override;
    void visitSymbol(glslang::TIntermSymbol* node) override;
    bool visitLoop(TVisit, glslang::TIntermLoop*) override;
    bool visitBranch(TVisit, glslang::TIntermBranch*) override;
    bool visitSwitch(TVisit, glslang::TIntermSwitch*) override;
};

// Extract the name of a function from its glslang mangled signature. e.g: Returns prepareMaterial
// for input "prepareMaterial(struct-MaterialInputs-vf4-f1-f1-f1-f1-vf41;".
std::string_view getFunctionName(std::string_view functionSignature) noexcept;

// Traverse the AST root, looking for function definition. Returns the Function definition node
// matching the provided glslang mangled signature. Example of signature inputs:
// prepareMaterial(struct-MaterialInputs-vf4-f1-f1-f1-f1-vf41;
// main(
glslang::TIntermAggregate* getFunctionBySignature(std::string_view functionSignature,
        TIntermNode& root) noexcept;

// Traverse the AST root, looking for function definition. Returns the Function definition node
// matching the provided function name. Example of signature inputs:
// prepareMaterial
// main
// This function is useful when looking for a function with variable signature. e.g: prepareMaterial
// and material functions take a struct which can vary in size depending on the property of the
// material processed.
glslang::TIntermAggregate* getFunctionByNameOnly(std::string_view functionName,
        TIntermNode& root) noexcept;

// Recursively traverse the AST function node provided, looking for a call to the specified
// function. Traverse all function calls found in each function.
bool isFunctionCalled(std::string_view functionName, TIntermNode& functionNode,
        TIntermNode& rootNode) noexcept;

struct FunctionParameter {
    enum Qualifier { IN, OUT, INOUT, CONST };
    std::string name;
    std::string type;
    Qualifier qualifier;
};

// Traverse function definition node, looking for parameters and populate params vector.
void getFunctionParameters(glslang::TIntermAggregate* func,
        std::vector<FunctionParameter>& output) noexcept;

std::string to_string(glslang::TOperator op);

std::string getIndexDirectStructString(const glslang::TIntermBinary& node);

} // namespace ASTutils
#endif //TNT_SCAHELPERS_H_H
