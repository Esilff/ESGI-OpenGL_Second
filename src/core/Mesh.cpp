#include "Mesh.h"

Mesh::Mesh(float *vertices, int drawCount, shader::Shader shader) : m_shader(shader) {
    m_drawCount = drawCount;
    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    m_vertices = vertices;
    m_shader = shader;

    glBufferData(GL_ARRAY_BUFFER, 3 * 3 * sizeof(float), m_vertices, GL_STATIC_DRAW);
    unsigned int posLocation = glGetAttribLocation(m_shader.getProgram(), "aPos");
    glEnableVertexAttribArray(posLocation);
    glVertexAttribPointer(posLocation, 3, GL_FLOAT, GL_FALSE, 3 * sizeof (float), (void*) 0);
//    glEnableVertexAttribArray(posLocation);
//    glVertexAttribPointer(posLocation, 3,GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
}

Mesh::~Mesh() {
    glDeleteBuffers(1, &m_vbo);
}

void Mesh::draw(unsigned int mode) {
    glDrawArrays(mode, 0, m_drawCount);
}