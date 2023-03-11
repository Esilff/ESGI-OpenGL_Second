//
// Created by Esilff on 11/03/2023.
//

#ifndef ESGI_OPENGL_SECOND_MESH_H
#define ESGI_OPENGL_SECOND_MESH_H
#include <glad/glad.h>

class Mesh {
    float * m_vertices;
    int m_drawCount;
    unsigned int m_vbo;
public:
    Mesh(float * vertices, int drawCount, unsigned int posLocation);
    ~Mesh();

    void draw(unsigned int mode);
};


#endif //ESGI_OPENGL_SECOND_MESH_H
