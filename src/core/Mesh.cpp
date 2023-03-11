#include "Mesh.h"

Mesh::Mesh(float *vertices, int drawCount, unsigned int posLocation) {
    m_drawCount = drawCount;
    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    m_vertices = vertices;

    glBufferData(GL_ARRAY_BUFFER, 3 * 3 * sizeof(float), m_vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(posLocation);
    glVertexAttribPointer(posLocation, 3,GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
}

Mesh::~Mesh() {
    glDeleteBuffers(1, &m_vbo);
}

void Mesh::draw(unsigned int mode) {
    glDrawArrays(mode, 0, m_drawCount);
}