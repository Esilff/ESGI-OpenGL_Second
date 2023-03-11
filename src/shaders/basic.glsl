#pragma vertex
#version 120
attribute vec3 aPos;
varying vec3 vCol;

void main() {
    gl_Position = vec4(aPos, 1.0);
    vCol = aPos;
}

#pragma fragment
#version 120
varying vec3 vCol;

void main() {
    gl_FragColor = vec4(vCol, 1.0);
}


