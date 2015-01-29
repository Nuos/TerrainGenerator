/* Vertex shader for ROAMTerrain. */

#version 430

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

layout (location = 0) in vec3 v_pos;
layout (location = 1) in vec2 v_tex;
layout (location = 2) in vec3 v_norm;

out vec3 f_pos;
out vec2 f_tex;
out vec3 f_norm;

void main() {
    gl_Position = projection * view * model * vec4(v_pos, 1.0);
    f_pos = vec3(view * model * vec4(v_pos, 1)); //test code
    f_tex = v_tex;
    f_norm = v_norm;
}