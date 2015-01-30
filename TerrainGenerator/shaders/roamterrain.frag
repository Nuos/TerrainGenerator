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
    else if (dot(f_norm, vec3(0, 1, 0)) < 0.9) {
        color = mix(texture(tex2, f_tex),
                    texture(tex1, f_tex),
                    (dot(f_norm, vec3(0, 1, 0)) - 0.8) / (1 - 0.8));
    } 
    else {
        color = mix(texture(tex1, f_tex),
                    texture(tex0, f_tex),
                    (dot(f_norm, vec3(0, 1, 0)) - 0.9) / (1 - 0.9));
    }

    //code from OpenGL 4.0 Shading Language Cookbook
    /*float dist = abs(f_pos.z);
    float fogfactor = (2500.0 - dist) / (2500.0 - 0.0);
    fogfactor = clamp(fogfactor, 0, 1);
    color = mix(vec4(0.5, 0.5, 0.5, 1), color, fogfactor);*/

    //color = vec4(f_norm, color.y);
}