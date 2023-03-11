#include <string>
#include <array>
#include <fstream>
#include <iostream>
#include <stdexcept>

namespace project {
    enum ShaderType {
        NONE = -1,
        VERTEX,
        FRAGMENT
    };
}

namespace fparse {
    std::array<std::string, 2> parseShader(const std::string &path) {
        std::array<std::string, 2> shaderSources;
        std::ifstream file(std::string(SOURCE_DIR) + "/" + path);
        project::ShaderType type = project::NONE;
        if (!file.is_open()) {
            std::cout << "No file found at : " << path << std::endl;
        }
        std::string line;
        while (std::getline(file, line)) {
            if (line.find("#pragma") != std::string::npos) {
                if (line.find("vertex") != std::string::npos) type = project::VERTEX;
                if (line.find("fragment") != std::string::npos) type = project::FRAGMENT;
                continue;
            }
            shaderSources[type].append(line + "\n");
        }
        return shaderSources;
    }
}
