#pragma once
#include "scene.h"

namespace Assimp {
class Importer {
public:
    const aiScene* ReadFile(const char* path, unsigned int flags);
};
}


