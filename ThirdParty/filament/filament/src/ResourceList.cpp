
#include "ResourceList.h"

#include "third_party/filament/libs/utils/include/utils/Log.h"

#include <algorithm>

namespace filament {

ResourceListBase::ResourceListBase(const char* typeName)
#ifndef NDEBUG
        : mTypeName(typeName)
#endif
{
}

ResourceListBase::~ResourceListBase() noexcept {
#ifndef NDEBUG
    if (!mList.empty()) {
        utils::slog.d << "leaked " << mList.size() << " " << mTypeName << utils::io::endl;
    }
#endif
}

void ResourceListBase::insert(void* item) {
    mList.insert(item);
}

bool ResourceListBase::remove(void const* item) {
    return mList.erase(const_cast<void*>(item)) > 0;
}

auto ResourceListBase::find(void const* item) -> iterator {
    return mList.find(const_cast<void*>(item));
}

void ResourceListBase::clear() noexcept {
    mList.clear();
}

// this is not inlined, so we don't pay the code-size cost of iterating the list
void ResourceListBase::forEach(void (* f)(void*, void*), void* user) const noexcept {
    std::for_each(mList.begin(), mList.end(), [=](void* p) {
        f(user, p);
    });
}

} // namespace filament
