
#ifndef GLTFIO_ANIMATOR_H
#define GLTFIO_ANIMATOR_H

#include <gltfio/FilamentAsset.h>
#include <gltfio/FilamentInstance.h>

namespace filament::gltfio {

struct FFilamentAsset;
struct FFilamentInstance;
struct AnimatorImpl;

class UTILS_PUBLIC Animator {
public:
    void applyAnimation(size_t animationIndex, float time) const;

    void updateBoneMatrices();

    void applyCrossFade(size_t previousAnimIndex, float previousAnimTime, float alpha);

    void resetBoneMatrices();

    float getAnimationDuration(size_t animationIndex) const;

    const char* getAnimationName(size_t animationIndex) const;

    // For internal use only.
    void addInstance(FFilamentInstance* instance);

private:


    // If "instance" is null, then this is the primary animator.
    Animator(FFilamentAsset const* asset, FFilamentInstance* instance);
    ~Animator();

    Animator(const Animator& animator) = delete;
    Animator(Animator&& animator) = delete;
    Animator& operator=(const Animator&) = delete;

    AnimatorImpl* mImpl;
};

} // namespace filament::gltfio

#endif // GLTFIO_ANIMATOR_H
