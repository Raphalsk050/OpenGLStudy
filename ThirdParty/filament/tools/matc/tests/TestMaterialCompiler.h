
#ifndef TNT_TESTMATERIALCOMPILER_H
#define TNT_TESTMATERIALCOMPILER_H

#include <stddef.h>

#include <matc/MaterialCompiler.h>

class TestMaterialCompiler {
public:
    explicit TestMaterialCompiler(const matc::MaterialCompiler& materialCompiler) :
            mMaterialCompiler(materialCompiler) {}

    bool parseMaterial(const char* buffer, size_t size, filamat::MaterialBuilder& builder)
    const noexcept{
        return mMaterialCompiler.parseMaterial(buffer, size, builder);
    }

    bool parseMaterialAsJSON(const char* buffer, size_t size, filamat::MaterialBuilder& builder)
    const noexcept{
        return mMaterialCompiler.parseMaterialAsJSON(buffer, size, builder);
    }

private:
    const matc::MaterialCompiler& mMaterialCompiler;
};

#endif //TNT_TESTMATERIALCOMPILER_H
