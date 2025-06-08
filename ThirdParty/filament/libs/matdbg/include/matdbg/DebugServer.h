
#ifndef MATDBG_DEBUGSERVER_H
#define MATDBG_DEBUGSERVER_H

#include "third_party/filament/libs/utils/include/utils/CString.h"

#include <backend/DriverEnums.h>

#include <private/filament/Variant.h>

#include "robin_map/include/tsl/robin_map.h"
#include "third_party/filament/libs/utils/include/utils/Mutex.h"

class CivetServer;

namespace filament::matdbg {

using MaterialKey = uint32_t;

struct MaterialRecord {
    void* userdata;
    const uint8_t* package;
    size_t packageSize;
    utils::CString name;
    MaterialKey key;
    VariantList activeVariants;
};

class DebugServer {
public:
    static std::string_view const kSuccessHeader;
    static std::string_view const kErrorHeader;

    DebugServer(backend::Backend backend, int port);
    ~DebugServer();

    MaterialKey addMaterial(const utils::CString& name, const void* data, size_t size,
            void* userdata = nullptr);

    void removeMaterial(MaterialKey key);

    using EditCallback = void(*)(void* userdata, const utils::CString& name, const void*, size_t);
    using QueryCallback = void(*)(void* userdata, VariantList* variants);

    void setEditCallback(EditCallback callback) { mEditCallback = callback; }

    void setQueryCallback(QueryCallback callback) { mQueryCallback = callback; }

    bool isReady() const { return mServer; }

private:
    MaterialRecord const* getRecord(const MaterialKey& key) const;

    void updateActiveVariants();

    bool handleEditCommand(const MaterialKey& mat, backend::Backend api, int shaderIndex,
            const char* newShaderContent, size_t newShaderLength);

    const backend::Backend mBackend;

    CivetServer* mServer;

    tsl::robin_map<MaterialKey, MaterialRecord> mMaterialRecords;
    mutable utils::Mutex mMaterialRecordsMutex;

    utils::CString mHtml;
    utils::CString mJavascript;
    utils::CString mCss;

    utils::CString mChunkedMessage;
    size_t mChunkedMessageRemaining = 0;

    EditCallback mEditCallback = nullptr;
    QueryCallback mQueryCallback = nullptr;

    class FileRequestHandler* mFileHandler = nullptr;
    class ApiHandler* mApiHandler = nullptr;

    friend class FileRequestHandler;
    friend class ApiHandler;
};

} // namespace filament::matdbg

#endif  // MATDBG_DEBUGSERVER_H
