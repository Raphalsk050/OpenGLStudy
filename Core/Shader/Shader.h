#pragma once
#include <string>

#include "glad/glad.h"

namespace GLStudy
{
    class Shader
    {
    public:
        // Function to create a shader program from vertex and fragment file paths
        static unsigned int CreateShaderProgram(const std::string& vertex_shader_path, const std::string& fragment_shader_path);

    private:
        // function that gets a shader path and read all it's data
        static std::string ReadFile(const std::string& filePath);

        // Compile a given shader text into binary code
        static unsigned int CompileShader(const std::string& source, GLenum shader_type);
    };
} // GLStudy
