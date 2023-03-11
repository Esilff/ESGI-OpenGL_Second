//
// Created by Esilff on 11/03/2023.
//

#include "Shader.h"

shader::Shader::Shader(const std::string &path) : m_path(path) {
    int success;
    char infoLog[LOG_SIZE];
    m_shaderSources = shader::Shader::parseShader(path);
    const char * vs = m_shaderSources[0].c_str();
    const char * fs = m_shaderSources[1].c_str();
    unsigned int vertexShader, fragmentShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vs, nullptr);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, LOG_SIZE, nullptr, infoLog);
        std::cout << "Could not compile the vertex shader : " << infoLog << std::endl;
    }
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fs, nullptr);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, LOG_SIZE, nullptr, infoLog);
        std::cout << "Could not compile the fragment shader : " << infoLog << std::endl;
    }
    m_shaderProgram = glCreateProgram();
    glAttachShader(m_shaderProgram, vertexShader);
    glAttachShader(m_shaderProgram, fragmentShader);
    glLinkProgram(m_shaderProgram);
    glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(m_shaderProgram, LOG_SIZE, nullptr, infoLog);
        std::cout << "Could not compile the shader program : " << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

shader::Shader::~Shader() {
    glDeleteProgram(m_shaderProgram);
}

void shader::Shader::bind() {
    glUseProgram(m_shaderProgram);
}

void shader::Shader::unbind() {
    glUseProgram(0);
}

std::string shader::Shader::getSource(ShaderType type) {
    return this->m_shaderSources[type];
}

std::array<std::string, 2> shader::Shader::parseShader(const std::string &path) {
    std::array<std::string, 2> shaderSources;
    std::ifstream file(std::string(SOURCE_DIR) + "/" + path);
    shader::ShaderType type = shader::NONE;
    if (!file.is_open()) {
        std::cout << "No file found at : " << path << std::endl;
    }
    std::string line;
    while (std::getline(file, line)) {
        if (line.find("#pragma") != std::string::npos) {
            if (line.find("vertex") != std::string::npos) type = shader::VERTEX;
            if (line.find("fragment") != std::string::npos) type = shader::FRAGMENT;
            continue;
        }
        shaderSources[type].append(line + "\n");
    }
    return shaderSources;
}

unsigned int shader::Shader::getPosLocation() {
    return glGetAttribLocation(m_shaderProgram, "aPos");
}
