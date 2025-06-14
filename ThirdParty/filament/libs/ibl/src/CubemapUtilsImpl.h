
#ifndef IBL_CUBEMAPUTILSIMPL_H
#define IBL_CUBEMAPUTILSIMPL_H

#include <ibl/CubemapUtils.h>

#include "third_party/filament/libs/utils/include/utils/compiler.h"
#include "third_party/filament/libs/utils/include/utils/JobSystem.h"

namespace filament {
namespace ibl {

template<typename STATE>
void CubemapUtils::process(
        Cubemap& cm,
        utils::JobSystem& js,
        CubemapUtils::ScanlineProc<STATE> proc,
        ReduceProc<STATE> reduce,
        const STATE& prototype) {
    using namespace utils;

    const size_t dim = cm.getDimensions();

    STATE states[6];
    for (STATE& s : states) {
        s = prototype;
    }

    JobSystem::Job* parent = js.createJob();
    for (size_t faceIndex = 0; faceIndex < 6; faceIndex++) {

        auto perFaceJob = [faceIndex, &states, &cm, dim, &proc]
                (utils::JobSystem& js, utils::JobSystem::Job* parent) {
            STATE& s = states[faceIndex];
            Image& image(cm.getImageForFace((Cubemap::Face)faceIndex));

            // here we must limit how much we capture so we can use this closure
            // by value.
            auto parallelJobTask = [&s, &image, &proc, dim = uint16_t(dim),
                                    faceIndex = uint8_t(faceIndex)](size_t y0, size_t c) {
                for (size_t y = y0; y < y0 + c; y++) {
                    Cubemap::Texel* data =
                            static_cast<Cubemap::Texel*>(image.getPixelRef(0, y));
                    proc(s, y, (Cubemap::Face)faceIndex, data, dim);
                }
            };

            constexpr bool isStateLess = std::is_same<STATE, CubemapUtils::EmptyState>::value;
            if (UTILS_LIKELY(isStateLess)) {
                // create the job, copying it by value
                auto job = jobs::parallel_for(js, parent, 0, uint32_t(dim),
                        parallelJobTask, jobs::CountSplitter<64, 8>());
                // not need to signal here, since we're just scheduling work
                js.run(job);
            } else {
                // if we have a per-thread STATE, we can't parallel_for()
                parallelJobTask(0, dim);
            }
        };

        // not need to signal here, since we're just scheduling work
        js.run(jobs::createJob(js, parent, perFaceJob, std::ref(js), parent));
    }

    // wait for all our threads to finish
    js.runAndWait(parent);

    for (STATE& s : states) {
        reduce(s);
    }
}

template<typename STATE>
void CubemapUtils::processSingleThreaded(
        Cubemap& cm,
        utils::JobSystem& js,
        CubemapUtils::ScanlineProc<STATE> proc,
        ReduceProc<STATE> reduce,
        const STATE& prototype) {
    using namespace utils;

    const size_t dim = cm.getDimensions();

    STATE s;
    s = prototype;

    for (size_t faceIndex = 0; faceIndex < 6; faceIndex++) {
        const Cubemap::Face f = (Cubemap::Face)faceIndex;
        Image& image(cm.getImageForFace(f));
        for (size_t y = 0; y < dim; y++) {
            Cubemap::Texel* data = static_cast<Cubemap::Texel*>(image.getPixelRef(0, y));
            proc(s, y, f, data, dim);
        }
    }
    reduce(s);
}


} // namespace ibl
} // namespace filament

#endif // IBL_CUBEMAPUTILSIMPL_H
