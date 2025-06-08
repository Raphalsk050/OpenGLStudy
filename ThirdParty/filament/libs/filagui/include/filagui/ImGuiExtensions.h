
#ifndef FILAGUI_IMGUIEXTENSIONS_H
#define FILAGUI_IMGUIEXTENSIONS_H

#include "third_party/filament/libs/utils/include/utils/compiler.h"

struct ImVec2;

namespace ImGuiExt {
    UTILS_PUBLIC
    bool DirectionWidget(const char* label, float v[3]);

    UTILS_PUBLIC
    void PlotLinesSeries(const char* label, int series_count,
            void (*series_start)(int series),
            float (*values_getter)(int series, void* data, int idx),
            void (*series_end)(int series),
            void* data, int values_count, int values_offset, const char* overlay_text,
            float scale_min, float scale_max, ImVec2 graph_size);
}

#endif // FILAGUI_IMGUIEXTENSIONS_H
