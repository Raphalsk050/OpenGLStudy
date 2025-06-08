
#ifndef TNT_FILAMAT_UIBGENERATOR_H
#define TNT_FILAMAT_UIBGENERATOR_H

namespace filament {

class BufferInterfaceBlock;

class UibGenerator {
public:
    static BufferInterfaceBlock const& getPerViewUib() noexcept;
    static BufferInterfaceBlock const& getPerRenderableUib() noexcept;
    static BufferInterfaceBlock const& getLightsUib() noexcept;
    static BufferInterfaceBlock const& getShadowUib() noexcept;
    static BufferInterfaceBlock const& getPerRenderableBonesUib() noexcept;
    static BufferInterfaceBlock const& getPerRenderableMorphingUib() noexcept;
    static BufferInterfaceBlock const& getFroxelRecordUib() noexcept;
    static BufferInterfaceBlock const& getFroxelsUib() noexcept;
    // When adding an UBO here, make sure to also update
    //      MaterialBuilder::writeCommonChunks() if needed
};

} // namespace filament

#endif // TNT_FILAMAT_UIBGENERATOR_H
