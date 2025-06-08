
#ifndef TNT_FILAMENT_BACKEND_VULKANSPIRVUTILS_H
#define TNT_FILAMENT_BACKEND_VULKANSPIRVUTILS_H

#include <backend/Program.h>

#include "third_party/filament/libs/utils/include/utils/FixedCapacityVector.h"

#include <tuple>
#include <vector>

namespace filament::backend {

using SpecConstantValue = Program::SpecializationConstant::Type;

// For certain drivers, using spec constant can lead to compile errors [1] or undesirable behaviors
// [2]. In those instances, we simply change the spirv and set them to constants.
//
// (Implemenation note: we cannot write to the blob because spirv-validator does not properly handle
//  the Nop (no-op) instruction, and swiftshader validates the shader before compilation. So we need
//  to skip those instructions instead).
//
// [1]: QC driver cannot use spec constant to size fields
//      (https://github.com/google/filament/issues/6444).
// [2]: An internal driver does not DCE a block guarded by a spec-const boolean set to false
//      (b/310603393).
void workaroundSpecConstant(Program::ShaderBlob const& blob,
        utils::FixedCapacityVector<Program::SpecializationConstant> const& specConstants,
        std::vector<uint32_t>& output);

// bindings for UBO, samplers, input attachment
std::tuple<uint32_t, uint32_t, uint32_t> getProgramBindings(Program::ShaderBlob const& blob);

} // namespace filament::backend

#endif // TNT_FILAMENT_BACKEND_VULKANSPIRVUTILS_H
