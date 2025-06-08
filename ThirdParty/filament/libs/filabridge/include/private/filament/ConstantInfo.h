
#ifndef TNT_FILAMENT_CONSTANTINFO_H
#define TNT_FILAMENT_CONSTANTINFO_H

#include <backend/DriverEnums.h>

#include "third_party/filament/libs/utils/include/utils/CString.h"

namespace filament {

struct MaterialConstant {
    using ConstantType = backend::ConstantType;

    utils::CString name;
    ConstantType type;

    MaterialConstant() = default;
    MaterialConstant(const char* name, ConstantType type) : name(name), type(type)  {}
};

}

#endif  // TNT_FILAMENT_CONSTANTINFO_H
