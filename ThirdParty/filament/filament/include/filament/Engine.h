
#ifndef TNT_FILAMENT_ENGINE_H
#define TNT_FILAMENT_ENGINE_H

#include <filament/FilamentAPI.h>

#include <backend/DriverEnums.h>
#include <backend/Platform.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/Invocable.h"

#include <stdint.h>
#include <stddef.h>

namespace utils {
class Entity;
class EntityManager;
class JobSystem;
} // namespace utils

namespace filament {

class BufferObject;
class Camera;
class ColorGrading;
class DebugRegistry;
class Fence;
class IndexBuffer;
class SkinningBuffer;
class IndirectLight;
class Material;
class MaterialInstance;
class MorphTargetBuffer;
class Renderer;
class RenderTarget;
class Scene;
class Skybox;
class Stream;
class SwapChain;
class Texture;
class VertexBuffer;
class View;
class InstanceBuffer;

class LightManager;
class RenderableManager;
class TransformManager;

#ifndef FILAMENT_PER_RENDER_PASS_ARENA_SIZE_IN_MB
#    define FILAMENT_PER_RENDER_PASS_ARENA_SIZE_IN_MB 3
#endif

#ifndef FILAMENT_PER_FRAME_COMMANDS_SIZE_IN_MB
#    define FILAMENT_PER_FRAME_COMMANDS_SIZE_IN_MB 2
#endif

#ifndef FILAMENT_MIN_COMMAND_BUFFERS_SIZE_IN_MB
#    define FILAMENT_MIN_COMMAND_BUFFERS_SIZE_IN_MB 1
#endif

#ifndef FILAMENT_COMMAND_BUFFER_SIZE_IN_MB
#    define FILAMENT_COMMAND_BUFFER_SIZE_IN_MB (FILAMENT_MIN_COMMAND_BUFFERS_SIZE_IN_MB * 3)
#endif

class UTILS_PUBLIC Engine {
    struct BuilderDetails;
public:
    using Platform = backend::Platform;
    using Backend = backend::Backend;
    using DriverConfig = backend::Platform::DriverConfig;
    using FeatureLevel = backend::FeatureLevel;
    using StereoscopicType = backend::StereoscopicType;

    struct Config {
        uint32_t commandBufferSizeMB = FILAMENT_COMMAND_BUFFER_SIZE_IN_MB;


        uint32_t perRenderPassArenaSizeMB = FILAMENT_PER_RENDER_PASS_ARENA_SIZE_IN_MB;


        uint32_t driverHandleArenaSizeMB = 0;


        uint32_t minCommandBufferSizeMB = FILAMENT_MIN_COMMAND_BUFFERS_SIZE_IN_MB;


        uint32_t perFrameCommandsSizeMB = FILAMENT_PER_FRAME_COMMANDS_SIZE_IN_MB;

        uint32_t jobSystemThreadCount = 0;

        size_t textureUseAfterFreePoolSize = 0;

        size_t metalUploadBufferSizeBytes = 512 * 1024;

        bool disableParallelShaderCompile = false;

        StereoscopicType stereoscopicType = StereoscopicType::NONE;

        uint8_t stereoscopicEyeCount = 2;

        uint32_t resourceAllocatorCacheSizeMB = 64;

        uint32_t resourceAllocatorCacheMaxAge = 2;

        bool disableHandleUseAfterFreeCheck = false;

        enum class ShaderLanguage {
            DEFAULT = 0,
            MSL = 1,
            METAL_LIBRARY = 2,
        };
        ShaderLanguage preferredShaderLanguage = ShaderLanguage::DEFAULT;

        bool forceGLES2Context = false;
    };


#if UTILS_HAS_THREADING
    using CreateCallback = void(void* UTILS_NULLABLE user, void* UTILS_NONNULL token);
#endif

    class Builder : public BuilderBase<BuilderDetails> {
        friend struct BuilderDetails;
        friend class FEngine;
    public:
        Builder() noexcept;
        Builder(Builder const& rhs) noexcept;
        Builder(Builder&& rhs) noexcept;
        ~Builder() noexcept;
        Builder& operator=(Builder const& rhs) noexcept;
        Builder& operator=(Builder&& rhs) noexcept;

        Builder& backend(Backend backend) noexcept;

        Builder& platform(Platform* UTILS_NULLABLE platform) noexcept;

        Builder& config(const Config* UTILS_NULLABLE config) noexcept;

        Builder& sharedContext(void* UTILS_NULLABLE sharedContext) noexcept;

        Builder& featureLevel(FeatureLevel featureLevel) noexcept;

        Builder& paused(bool paused) noexcept;

#if UTILS_HAS_THREADING
        void build(utils::Invocable<void(void* UTILS_NONNULL token)>&& callback) const;
#endif

        Engine* UTILS_NULLABLE build() const;
    };

    static inline Engine* UTILS_NULLABLE create(Backend backend = Backend::DEFAULT,
            Platform* UTILS_NULLABLE platform = nullptr,
            void* UTILS_NULLABLE sharedContext = nullptr,
            const Config* UTILS_NULLABLE config = nullptr) {
        return Engine::Builder()
                .backend(backend)
                .platform(platform)
                .sharedContext(sharedContext)
                .config(config)
                .build();
    }


#if UTILS_HAS_THREADING
    static inline void createAsync(CreateCallback callback,
            void* UTILS_NULLABLE user,
            Backend backend = Backend::DEFAULT,
            Platform* UTILS_NULLABLE platform = nullptr,
            void* UTILS_NULLABLE sharedContext = nullptr,
            const Config* UTILS_NULLABLE config = nullptr) {
        Engine::Builder()
                .backend(backend)
                .platform(platform)
                .sharedContext(sharedContext)
                .config(config)
                .build([callback, user](void* UTILS_NONNULL token) {
                    callback(user, token);
                });
    }

    static Engine* UTILS_NULLABLE getEngine(void* UTILS_NONNULL token);
#endif


    static void destroy(Engine* UTILS_NULLABLE* UTILS_NULLABLE engine);

    static void destroy(Engine* UTILS_NULLABLE engine);

    FeatureLevel getSupportedFeatureLevel() const noexcept;

    FeatureLevel setActiveFeatureLevel(FeatureLevel featureLevel);

    FeatureLevel getActiveFeatureLevel() const noexcept;

    size_t getMaxAutomaticInstances() const noexcept;

    bool isStereoSupported(StereoscopicType stereoscopicType) const noexcept;

    const Config& getConfig() const noexcept;

    static size_t getMaxStereoscopicEyes() noexcept;

    utils::EntityManager& getEntityManager() noexcept;

    RenderableManager& getRenderableManager() noexcept;

    LightManager& getLightManager() noexcept;

    TransformManager& getTransformManager() noexcept;

    void enableAccurateTranslations() noexcept;

    void setAutomaticInstancingEnabled(bool enable) noexcept;

    bool isAutomaticInstancingEnabled() const noexcept;

    SwapChain* UTILS_NONNULL createSwapChain(void* UTILS_NULLABLE nativeWindow, uint64_t flags = 0) noexcept;


    SwapChain* UTILS_NONNULL createSwapChain(uint32_t width, uint32_t height, uint64_t flags = 0) noexcept;

    Renderer* UTILS_NONNULL createRenderer() noexcept;

    View* UTILS_NONNULL createView() noexcept;

    Scene* UTILS_NONNULL createScene() noexcept;

    Camera* UTILS_NONNULL createCamera(utils::Entity entity) noexcept;

    Camera* UTILS_NULLABLE getCameraComponent(utils::Entity entity) noexcept;

    void destroyCameraComponent(utils::Entity entity) noexcept;

    Fence* UTILS_NONNULL createFence() noexcept;

    bool destroy(const BufferObject* UTILS_NULLABLE p);         //!< Destroys a BufferObject object.
    bool destroy(const VertexBuffer* UTILS_NULLABLE p);         //!< Destroys an VertexBuffer object.
    bool destroy(const Fence* UTILS_NULLABLE p);                //!< Destroys a Fence object.
    bool destroy(const IndexBuffer* UTILS_NULLABLE p);          //!< Destroys an IndexBuffer object.
    bool destroy(const SkinningBuffer* UTILS_NULLABLE p);       //!< Destroys a SkinningBuffer object.
    bool destroy(const MorphTargetBuffer* UTILS_NULLABLE p);    //!< Destroys a MorphTargetBuffer object.
    bool destroy(const IndirectLight* UTILS_NULLABLE p);        //!< Destroys an IndirectLight object.

    bool destroy(const Material* UTILS_NULLABLE p);
    bool destroy(const MaterialInstance* UTILS_NULLABLE p); //!< Destroys a MaterialInstance object.
    bool destroy(const Renderer* UTILS_NULLABLE p);         //!< Destroys a Renderer object.
    bool destroy(const Scene* UTILS_NULLABLE p);            //!< Destroys a Scene object.
    bool destroy(const Skybox* UTILS_NULLABLE p);           //!< Destroys a SkyBox object.
    bool destroy(const ColorGrading* UTILS_NULLABLE p);     //!< Destroys a ColorGrading object.
    bool destroy(const SwapChain* UTILS_NULLABLE p);        //!< Destroys a SwapChain object.
    bool destroy(const Stream* UTILS_NULLABLE p);           //!< Destroys a Stream object.
    bool destroy(const Texture* UTILS_NULLABLE p);          //!< Destroys a Texture object.
    bool destroy(const RenderTarget* UTILS_NULLABLE p);     //!< Destroys a RenderTarget object.
    bool destroy(const View* UTILS_NULLABLE p);             //!< Destroys a View object.
    bool destroy(const InstanceBuffer* UTILS_NULLABLE p);   //!< Destroys an InstanceBuffer object.
    void destroy(utils::Entity e);    //!< Destroys all filament-known components from this entity

    bool isValid(const VertexBuffer* UTILS_NULLABLE p) const;
    bool isValid(const IndexBuffer* UTILS_NULLABLE p) const;
    bool isValid(const MorphTargetBuffer* UTILS_NULLABLE p) const;
    bool isValid(const Material* UTILS_NULLABLE p) const;
    bool isValid(const Material* UTILS_NONNULL m, const MaterialInstance* UTILS_NULLABLE p) const;
    bool isValidExpensive(const MaterialInstance* UTILS_NULLABLE p) const;
    bool isValid(const Scene* UTILS_NULLABLE p) const;
    bool isValid(const ColorGrading* UTILS_NULLABLE p) const;
    bool isValid(const Stream* UTILS_NULLABLE p) const;
    bool isValid(const RenderTarget* UTILS_NULLABLE p) const;
    bool isValid(const InstanceBuffer* UTILS_NULLABLE p) const;

    void flushAndWait();

    void flush();

    bool isPaused() const noexcept;

    void setPaused(bool paused);

    void pumpMessageQueues();

    void unprotected() noexcept;

    Material const* UTILS_NONNULL getDefaultMaterial() const noexcept;

    Backend getBackend() const noexcept;

    Platform* UTILS_NULLABLE getPlatform() const noexcept;

    void* UTILS_NULLABLE streamAlloc(size_t size, size_t alignment = alignof(double)) noexcept;

    void execute();

    utils::JobSystem& getJobSystem() noexcept;

#if defined(__EMSCRIPTEN__)
    void resetBackendState() noexcept;
#endif

    static uint64_t getSteadyClockTimeNano() noexcept;


    DebugRegistry& getDebugRegistry() noexcept;

protected:
    //! \privatesection
    Engine() noexcept = default;
    ~Engine() = default;

public:
    //! \privatesection
    Engine(Engine const&) = delete;
    Engine(Engine&&) = delete;
    Engine& operator=(Engine const&) = delete;
    Engine& operator=(Engine&&) = delete;
};

} // namespace filament

#endif // TNT_FILAMENT_ENGINE_H
