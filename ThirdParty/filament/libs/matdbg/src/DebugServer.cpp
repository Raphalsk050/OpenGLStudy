
#include <matdbg/DebugServer.h>

#include "ApiHandler.h"

#include <CivetServer.h>

#include "third_party/filament/libs/utils/include/utils/FixedCapacityVector.h"
#include "third_party/filament/libs/utils/include/utils/Hash.h"
#include "third_party/filament/libs/utils/include/utils/Log.h"

#include <spirv_glsl.hpp>
#include <spirv-tools/libspirv.h>

#include <matdbg/JsonWriter.h>
#include <matdbg/ShaderExtractor.h>
#include <matdbg/ShaderInfo.h>
#include <matdbg/ShaderReplacer.h>

#include <filaflat/ChunkContainer.h>

#include "robin_map/include/tsl/robin_set.h"

#include <backend/DriverEnums.h>

#include "sca/GLSLTools.h"

#include <sstream>
#include <string>
#include <string_view>

using utils::FixedCapacityVector;

// If set to 0, this serves HTML from a resgen resource. Use 1 only during local development, which
// serves files directly from the source code tree.
#define SERVE_FROM_SOURCE_TREE 0

#if SERVE_FROM_SOURCE_TREE

namespace {
std::string const BASE_URL = "libs/matdbg/web";
} // anonymous

#else

#include "third_party/filament/libs/generated/resources/matdbg_resources.h"
#include <unordered_map>

namespace {

struct Asset {
    std::string_view mime;
    std::string_view data;
};
std::unordered_map<std::string_view, Asset> ASSET_MAP;

} // anonymous

#endif // SERVE_FROM_SOURCE_TREE

namespace filament::matdbg {

using namespace utils;
using namespace filament::backend;

using filaflat::ChunkContainer;
using filamat::ChunkType;

std::string_view const DebugServer::kSuccessHeader =
        "HTTP/1.1 200 OK\r\nContent-Type: %s\r\n"
        "Connection: close\r\n\r\n";

std::string_view const DebugServer::kErrorHeader =
        "HTTP/1.1 404 Not Found\r\nContent-Type: %s\r\n"
        "Connection: close\r\n\r\n";

class FileRequestHandler : public CivetHandler {
public:
    FileRequestHandler(DebugServer* server) : mServer(server) {}
    bool handleGet(CivetServer *server, struct mg_connection *conn) {
        auto const& kSuccessHeader = DebugServer::kSuccessHeader;
        struct mg_request_info const* request = mg_get_request_info(conn);
        std::string uri(request->request_uri);
        if (uri == "/") {
            uri = "/index.html";
        }

#if SERVE_FROM_SOURCE_TREE
        if (uri == "/index.html" || uri == "/app.js" || uri == "/api.js") {
            mg_send_file(conn, (BASE_URL + uri).c_str());
            return true;
        }
#else
        auto const& asset_itr = ASSET_MAP.find(uri);
        if (asset_itr != ASSET_MAP.end()) {
            auto const& mime = asset_itr->second.mime;
            auto const& data = asset_itr->second.data;
            mg_printf(conn, kSuccessHeader.data(), mime.data());
            mg_write(conn, data.data(), data.size());
            return true;
        }
#endif
        slog.e << "DebugServer: bad request at line " <<  __LINE__ << ": " << uri << io::endl;
        return false;
    }
private:
    DebugServer* mServer;
};

DebugServer::DebugServer(Backend backend, int port) : mBackend(backend) {

    #if !SERVE_FROM_SOURCE_TREE
    ASSET_MAP["/index.html"] = {
        .mime = "text/html",
        .data = {(char const*) MATDBG_RESOURCES_INDEX_DATA},
    };
    ASSET_MAP["/app.js"] = {
        .mime = "text/javascript",
        .data = {(char const*) MATDBG_RESOURCES_APP_DATA},
    };
    ASSET_MAP["/api.js"] = {
        .mime = "text/javascript",
        .data = {(char const*) MATDBG_RESOURCES_API_DATA},
    };
    #endif

    // By default the server spawns 50 threads so we override this to 10. According to the civetweb
    // documentation, "it is recommended to use num_threads of at least 5, since browsers often
    /// establish multiple connections to load a single web page, including all linked documents
    // (CSS, JavaScript, images, ...)."  If this count is too small, the web app basically hangs.
    const char* kServerOptions[] = {
        "listening_ports", "8080",
        "num_threads", "10",
        "error_log_file", "civetweb.txt",
        nullptr
    };
    std::string portString = std::to_string(port);
    kServerOptions[1] = portString.c_str();

    mServer = new CivetServer(kServerOptions);
    if (!mServer->getContext()) {
        delete mServer;
        mServer = nullptr;
        slog.e << "Unable to start DebugServer, see civetweb.txt for details." << io::endl;
        return;
    }

    mFileHandler = new FileRequestHandler(this);
    mApiHandler = new ApiHandler(this);

    mServer->addHandler("/api", mApiHandler);
    mServer->addHandler("", mFileHandler);

    slog.i << "DebugServer listening at http://localhost:" << port << io::endl;
    filamat::GLSLTools::init();
}

DebugServer::~DebugServer() {
    filamat::GLSLTools::shutdown();

    mServer->close();

    delete mFileHandler;
    delete mApiHandler;
    delete mServer;

    std::unique_lock<utils::Mutex> lock(mMaterialRecordsMutex);
    for (auto& pair : mMaterialRecords) {
        delete [] pair.second.package;
    }
}

MaterialKey
DebugServer::addMaterial(const CString& name, const void* data, size_t size, void* userdata) {
    filaflat::ChunkContainer* container = new filaflat::ChunkContainer(data, size);
    if (!container->parse()) {
        slog.e << "DebugServer: unable to parse material package: " << name.c_str() << io::endl;
        return {};
    }

    const uint32_t seed = 42;
    const MaterialKey key = utils::hash::murmurSlow((const uint8_t*) data, size, seed);

    // Retain a copy of the package to permit queries after the client application has
    // freed up the original material package.
    uint8_t* package = new uint8_t[size];
    memcpy(package, data, size);

    std::unique_lock<utils::Mutex> lock(mMaterialRecordsMutex);
    MaterialRecord info = {userdata, package, size, name, key};
    mMaterialRecords.insert({key, info});
    mApiHandler->addMaterial(&info);
    return key;
}

void DebugServer::removeMaterial(MaterialKey key) {
    std::unique_lock<utils::Mutex> lock(mMaterialRecordsMutex);
    mMaterialRecords.erase(key);
}

const MaterialRecord* DebugServer::getRecord(const MaterialKey& key) const {
    std::unique_lock<utils::Mutex> lock(mMaterialRecordsMutex);
    const auto& iter = mMaterialRecords.find(key);
    return iter == mMaterialRecords.end() ? nullptr : &iter->second;
}

void DebugServer::updateActiveVariants() {
    if (mQueryCallback) {
        std::unique_lock<utils::Mutex> lock(mMaterialRecordsMutex);
        auto curr = mMaterialRecords.begin();
        auto end = mMaterialRecords.end();
        while (curr != end) {
            auto& value = curr.value();
            VariantList& result = value.activeVariants;
            mQueryCallback(value.userdata, &result);
            ++curr;
        }
    }
}

bool DebugServer::handleEditCommand(const MaterialKey& key, backend::Backend api, int shaderIndex,
            const char* source, size_t size) {
    const auto error = [](int line) {
        slog.e << "DebugServer: Unable to apply shader edit at line " << line << io::endl;
        return false;
    };

    std::unique_lock<utils::Mutex> lock(mMaterialRecordsMutex);
    if (mMaterialRecords.find(key) == mMaterialRecords.end()) {
        return error(__LINE__);
    }
    MaterialRecord& material = mMaterialRecords[key];
    filaflat::ChunkContainer package(material.package, material.packageSize);
    if (!package.parse()) {
        return error(__LINE__);
    }

    FixedCapacityVector<ShaderInfo> infos;
    size_t shaderCount;
    switch (api) {
        case backend::Backend::OPENGL: {
            shaderCount = getShaderCount(package, ChunkType::MaterialGlsl);
            infos.reserve(shaderCount);
            infos.resize(shaderCount);
            if (!getShaderInfo(package, infos.data(), ChunkType::MaterialGlsl)) {
                return error(__LINE__);
            }
            break;
        }
        case backend::Backend::VULKAN: {
            shaderCount = getShaderCount(package, ChunkType::MaterialSpirv);
            infos.reserve(shaderCount);
            infos.resize(shaderCount);
            if (!getShaderInfo(package, infos.data(), ChunkType::MaterialSpirv)) {
                return error(__LINE__);
            }
            break;
        }
        case backend::Backend::METAL: {
            shaderCount = getShaderCount(package, ChunkType::MaterialMetal);
            infos.reserve(shaderCount);
            infos.resize(shaderCount);
            if (!getShaderInfo(package, infos.data(), ChunkType::MaterialMetal)) {
                return error(__LINE__);
            }
            break;
        }
        default:
            error(__LINE__);
    }

    if (shaderIndex < 0 || shaderIndex >= shaderCount) {
        return error(__LINE__);
    }

    const ShaderInfo info = infos[shaderIndex];
    ShaderReplacer editor(api, package.getData(), package.getSize());
    if (!editor.replaceShaderSource(info.shaderModel, info.variant, info.pipelineStage, source, size)) {
        return error(__LINE__);
    }

    delete [] material.package;

    material.package = editor.getEditedPackage();
    material.packageSize = editor.getEditedSize();

    if (mEditCallback) {
        mEditCallback(material.userdata, material.name, material.package, material.packageSize);
    }

    return true;
}

} // namespace filament::matdbg
