#ifndef ESGI_OPENGL_SECOND_SHADER_H
#define ESGI_OPENGL_SECOND_SHADER_H
#include <string>
#include <array>
#include <glad/glad.h>
#include <iostream>
#include <fstream>

#define LOG_SIZE 512

namespace shader {

    enum ShaderType {
        NONE = -1,
        VERTEX,
        FRAGMENT
    };

    class Shader {


        std::string m_path;
        std::array<std::string, 2> m_shaderSources;
        unsigned int m_shaderProgram;

    public:
        Shader(const std::string &path);
        ~Shader();

        void bind();
        void unbind();
        std::string getSource(ShaderType type);
        std::array<std::string, 2> parseShader(const std::string &path);
        unsigned int getPosLocation();

    };
}




#endif //ESGI_OPENGL_SECOND_SHADER_H
