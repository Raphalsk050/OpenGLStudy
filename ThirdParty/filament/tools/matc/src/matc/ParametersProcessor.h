
#ifndef TNT_PARAMETERSPROCESSOR_H
#define TNT_PARAMETERSPROCESSOR_H

#include <unordered_map>
#include <string>
#include <variant>

#include "JsonishLexeme.h"
#include "JsonishParser.h"

#include <filamat/MaterialBuilder.h>

namespace matc {

class ParametersProcessor {

public:
    ParametersProcessor();
    ~ParametersProcessor() = default;
    bool process(filamat::MaterialBuilder& builder, const JsonishObject& jsonObject);
    bool process(filamat::MaterialBuilder& builder, const std::string& key, const std::string& value);

private:

    using Callback = bool (*)(filamat::MaterialBuilder& builder, const JsonishValue& value);

    struct ParameterInfo {
        Callback callback;
        JsonishValue::Type rootAssert;
    };

    std::unordered_map<std::string, ParameterInfo> mParameters;
};

} // namespace matc

#endif //TNT_PARAMETERSPROCESSOR_H
