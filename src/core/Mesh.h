//
// Created by Esilff on 11/03/2023.
//

#ifndef ESGI_OPENGL_SECOND_MESH_H
#define ESGI_OPENGL_SECOND_MESH_H
#include <glad/glad.h>
#include "Shader.h"

class Mesh {
    float * m_vertices;
    int m_drawCount;
    unsigned int m_vbo;
    shader::Shader m_shader;
public:
    Mesh(float *vertices, int drawCount, shader::Shader shader);
    ~Mesh();

    void draw(unsigned int mode);
};


#endif //ESGI_OPENGL_SECOND_MESH_H
