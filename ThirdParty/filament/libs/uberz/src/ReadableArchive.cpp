
#include <uberz/ReadableArchive.h>

#include "third_party/filament/libs/utils/include/utils/debug.h"

using namespace filament;
using namespace utils;

namespace filament::uberz {

static_assert(sizeof(ReadableArchive) == 4 + 4 + 8 + 8);
static_assert(sizeof(ArchiveSpec) == 1 + 1 + 2 + 4 + 8 + 8);
static_assert(sizeof(ArchiveFlag) == 8 + 8);

void convertOffsetsToPointers(ReadableArchive* archive) {
    constexpr size_t wordSize = sizeof(uint64_t);
    assert_invariant(archive->specsOffset % wordSize == 0);
    uint64_t* basePointer = (uint64_t*) archive;
    archive->specs = (ArchiveSpec*) (basePointer + archive->specsOffset / wordSize);
    for (uint64_t i = 0; i < archive->specsCount; ++i) {
        ArchiveSpec& spec = archive->specs[i];
        assert_invariant(spec.flagsOffset % wordSize == 0);
        spec.flags = (ArchiveFlag*) (basePointer + (spec.flagsOffset / wordSize));
        spec.package = ((uint8_t*) basePointer) + spec.packageOffset;
        for (uint64_t j = 0; j < spec.flagsCount; ++j) {
            ArchiveFlag& flag = spec.flags[j];
            flag.name = ((const char*) basePointer) + flag.nameOffset;
        }
    }
}

} // namespace filament::uberz
