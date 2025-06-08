
#include "MaterialVariants.h"

#include <private/filament/EngineEnums.h>

namespace filamat {

std::vector<Variant> determineSurfaceVariants(
        filament::UserVariantFilterMask userVariantFilter, bool isLit, bool shadowMultiplier) {
    std::vector<Variant> variants;
    for (size_t k = 0; k < filament::VARIANT_COUNT; k++) {
        filament::Variant const variant(k);
        if (filament::Variant::isReserved(variant)) {
            continue;
        }

        filament::Variant filteredVariant =
                filament::Variant::filterUserVariant(variant, userVariantFilter);

        // Remove variants for unlit materials
        filteredVariant = filament::Variant::filterVariant(
                filteredVariant, isLit || shadowMultiplier);

        if (filament::Variant::filterVariantVertex(filteredVariant) == variant) {
            variants.emplace_back(variant, filament::backend::ShaderStage::VERTEX);
        }

        if (filament::Variant::filterVariantFragment(filteredVariant) == variant) {
            variants.emplace_back(variant, filament::backend::ShaderStage::FRAGMENT);
        }
    }
    return variants;
}

std::vector<Variant> determinePostProcessVariants() {
    std::vector<Variant> variants;
    // TODO: add a way to filter out post-process variants (e.g., the transparent variant if only
    // opaque is needed)
    for (filament::Variant::type_t k = 0; k < filament::POST_PROCESS_VARIANT_COUNT; k++) {
        filament::Variant const variant(k);
        variants.emplace_back(variant, filament::backend::ShaderStage::VERTEX);
        variants.emplace_back(variant, filament::backend::ShaderStage::FRAGMENT);
    }
    return variants;
}

std::vector<Variant> determineComputeVariants() {
    // TODO: should we have variants for compute shaders?
    std::vector<Variant> variants;
    filament::Variant variant(0);
    variants.emplace_back(variant, filament::backend::ShaderStage::COMPUTE);
    return variants;
}

} // namespace filamat
