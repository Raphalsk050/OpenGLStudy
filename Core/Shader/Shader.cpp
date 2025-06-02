#include <fstream>
#include <ios>
#include "Shader.h"
#include <iostream>
#include <sstream>

namespace GLStudy {
    unsigned int Shader::CreateShaderProgram(const std::string& vertex_shader_path, const std::string& fragment_shader_path)
    {
        std::string vertex_shader_src = ReadFile(vertex_shader_path);
        std::string fragment_shader_src = ReadFile(fragment_shader_path);

        if (vertex_shader_src.empty() || fragment_shader_src.empty()) {
            std::cerr << "ERROR: One or more shader source files are empty." << std::endl;
            return 0;
        }

        unsigned int vertex_shader_bin = CompileShader(vertex_shader_src, GL_VERTEX_SHADER);
        unsigned int fragment_shader_bin = CompileShader(fragment_shader_src, GL_FRAGMENT_SHADER);

        if (vertex_shader_bin == 0 || fragment_shader_bin == 0) {
            return 0;
        }

        unsigned int program = glCreateProgram();
        glAttachShader(program, vertex_shader_bin);
        glAttachShader(program, fragment_shader_bin);
        glLinkProgram(program);

        // Check for link errors
        GLint success;
        glGetProgramiv(program, GL_LINK_STATUS, &success);
        if (!success) {
            GLint logLength;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
            std::string infoLog(logLength, ' ');
            glGetProgramInfoLog(program, logLength, nullptr, &infoLog[0]);
            std::cerr << "ERROR: Program linking failed:\n" << infoLog << std::endl;
            glDeleteProgram(program);
            program = 0;
        }

        // Once linked, we can delete the shader buffer code
        glDeleteShader(vertex_shader_bin);
        glDeleteShader(fragment_shader_bin);

        return program;
    }

    std::string Shader::ReadFile(const std::string& filePath)
    {
        std::ifstream file(filePath, std::ios::in);
        if (!file.is_open())
        {
            std::cout << "Failed to open file " << filePath << std::endl;
            return "";
        }

        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }

    unsigned int Shader::CompileShader(const std::string& source, GLenum shader_type)
    {
        unsigned int shader = glCreateShader(shader_type);
        const char* src_ptr = source.c_str();
        glShaderSource(shader, 1, &src_ptr, nullptr);
        glCompileShader(shader);
        int success;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

        if (!success) {
            GLint logLength;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logLength);
            std::string infoLog(logLength, ' ');
            glGetShaderInfoLog(shader, logLength, nullptr, &infoLog[0]);
            std::cerr << "ERROR: Shader compilation failed:\n" << infoLog << std::endl;
            glDeleteShader(shader);
            return 0;
        }

        return shader;
    }
} // GLStudy