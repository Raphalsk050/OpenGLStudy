
#include <backend/Platform.h>

namespace filament::backend {

Platform::Platform() noexcept = default;

// this generates the vtable in this translation unit
Platform::~Platform() noexcept = default;

bool Platform::pumpEvents() noexcept {
    return false;
}

void Platform::setBlobFunc(InsertBlobFunc&& insertBlob, RetrieveBlobFunc&& retrieveBlob) noexcept {
    mInsertBlob = std::move(insertBlob);
    mRetrieveBlob = std::move(retrieveBlob);
}

bool Platform::hasInsertBlobFunc() const noexcept {
    return bool(mInsertBlob);
}

bool Platform::hasRetrieveBlobFunc() const noexcept {
    return bool(mRetrieveBlob);
}

void Platform::insertBlob(void const* key, size_t keySize, void const* value, size_t valueSize) {
    if (mInsertBlob) {
        mInsertBlob(key, keySize, value, valueSize);
    }
}

size_t Platform::retrieveBlob(void const* key, size_t keySize, void* value, size_t valueSize) {
    if (mRetrieveBlob) {
        return mRetrieveBlob(key, keySize, value, valueSize);
    }
    return 0;
}

void Platform::setDebugUpdateStatFunc(DebugUpdateStatFunc&& debugUpdateStat) noexcept {
    mDebugUpdateStat = std::move(debugUpdateStat);
}

bool Platform::hasDebugUpdateStatFunc() const noexcept {
    return bool(mDebugUpdateStat);
}

void Platform::debugUpdateStat(const char* key, uint64_t value) {
    if (mDebugUpdateStat) {
        mDebugUpdateStat(key, value);
    }
}

} // namespace filament::backend
