#version 120
attribute vec3 aPos;
varying vec3 vCol;

void main() {
    gl_Position = vec4(aPos, 1.0);
    vCol = aPos;
}
