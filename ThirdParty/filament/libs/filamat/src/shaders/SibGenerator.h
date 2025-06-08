
#ifndef TNT_FILABRIDGE_SIBGENERATOR_H
#define TNT_FILABRIDGE_SIBGENERATOR_H

#include "private/filament/Variant.h"

#include <stdint.h>
#include <stddef.h>
#include "private/filament/EngineEnums.h"

namespace filament {

class SamplerInterfaceBlock;

class SibGenerator {
public:
    static SamplerInterfaceBlock const& getPerViewSib(Variant variant) noexcept;
    static SamplerInterfaceBlock const& getPerRenderPrimitiveMorphingSib(Variant variant) noexcept;
    static SamplerInterfaceBlock const& getPerRenderPrimitiveBonesSib(Variant variant) noexcept;
    static SamplerInterfaceBlock const* getSib(filament::SamplerBindingPoints bindingPoint, Variant variant) noexcept;
    // When adding a sampler block here, make sure to also update
    //      FMaterial::getSurfaceProgramSlow and FMaterial::getPostProcessProgramSlow if needed
};

} // namespace filament

#endif // TNT_FILABRIDGE_SIBGENERATOR_H
