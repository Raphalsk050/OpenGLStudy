
#ifndef TNT_FILAMENT_BACKEND_PRIVATE_BACKENDUTILS_H
#define TNT_FILAMENT_BACKEND_PRIVATE_BACKENDUTILS_H

#include <backend/DriverEnums.h>

#include <backend/PixelBufferDescriptor.h>

#include <string_view>

#include <stddef.h>

namespace filament::backend {

bool requestsGoogleLineDirectivesExtension(std::string_view source) noexcept;

void removeGoogleLineDirectives(char* shader, size_t length) noexcept;

size_t getFormatSize(TextureFormat format) noexcept;

size_t getFormatComponentCount(TextureFormat format) noexcept;

size_t getBlockWidth(TextureFormat format) noexcept;

size_t getBlockHeight(TextureFormat format) noexcept;

bool reshape(const PixelBufferDescriptor& data, PixelBufferDescriptor& reshaped);

} // namespace filament

#endif // TNT_FILAMENT_BACKEND_PRIVATE_BACKENDUTILS_H
