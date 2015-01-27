/* Fragment shader for ROAMTerrain. */

#version 430

uniform sampler2D tex0;
uniform sampler2D tex1;
uniform sampler2D tex2;

in vec3 f_pos;
in vec2 f_tex;
in vec3 f_norm;

out vec4 color;

void main() {
    if (dot(f_norm, vec3(0, 1, 0)) < 0.8) {
        color = texture(tex2, f_tex);
    }
    else if (dot(f_norm, vec3(0, 1, 0)) < 0.85) {
        color = mix(texture(tex2, f_tex),
                    texture(tex1, f_tex),
                    (dot(f_norm, vec3(0, 1, 0)) - 0.8) / (1 - 0.8));
    } 
    else {
        color = mix(texture(tex1, f_tex),
                    texture(tex0, f_tex),
                    (dot(f_norm, vec3(0, 1, 0)) - 0.85) / (1 - 0.85));
    }

    //color = vec4(f_norm, color.y);
}