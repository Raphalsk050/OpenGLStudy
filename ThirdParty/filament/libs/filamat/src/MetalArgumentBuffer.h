
#ifndef TNT_METALARGUMENTBUFFER_H
#define TNT_METALARGUMENTBUFFER_H

#include <iostream>
#include <string>
#include <variant>
#include <vector>

#include <backend/DriverEnums.h>

namespace filamat {

class MetalArgumentBuffer {
public:

    class Builder {
    public:

        Builder& name(const std::string& name) noexcept;

        Builder& texture(size_t index, const std::string& name,
                filament::backend::SamplerType type,
                filament::backend::SamplerFormat format,
                bool multisample) noexcept;

        Builder& sampler(size_t index, const std::string& name) noexcept;

        MetalArgumentBuffer* build();

        friend class MetalArgumentBuffer;

    private:
        std::string mName;

        struct TextureArgument {
            std::string name;
            size_t index;
            filament::backend::SamplerType type;
            filament::backend::SamplerFormat format;
            bool multisample;

            std::ostream& write(std::ostream& os) const;
        };

        struct SamplerArgument {
            std::string name;
            size_t index;

            std::ostream& write(std::ostream& os) const;
        };

        using ArgumentType = std::variant<TextureArgument, SamplerArgument>;
        std::vector<ArgumentType> mArguments;
    };

    static void destroy(MetalArgumentBuffer** argumentBuffer);

    const std::string& getName() const noexcept { return mName; }

    const std::string& getMsl() const noexcept { return mShaderText; }

    static bool replaceInShader(std::string& shader, const std::string& targetArgBufferName,
            const std::string& replacement) noexcept;
private:

    MetalArgumentBuffer(Builder& builder);
    ~MetalArgumentBuffer() = default;

    std::string mName;
    std::string mShaderText;
};

} // namespace filamat

#endif  // TNT_METALARGUMENTBUFFER_H
