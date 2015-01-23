#include "KeyHandler.h"
#include "Globals.h"
#include <glm.hpp>

const Uint8* keystate = SDL_GetKeyboardState(NULL);
bool wireframe_enabled = false;

void KeyHandler::handlekey(SDL_Keycode& key) {
    switch (key) {

    /* End program */
    case SDLK_ESCAPE:
        Globals::program_running = false;
        break;
    /* Toggle wireframe mode on/off */
    case SDLK_r:
        wireframe_enabled = !wireframe_enabled;
        if (wireframe_enabled) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        } else {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }
        break;
    default:
        break;
    }
}

void KeyHandler::handlekey_cont() {
    /* Movement along direction vector of camera */
    if (keystate[SDL_SCANCODE_W]) {
        Globals::camera.set_pos(Globals::camera.get_pos() + Globals::movement_speed * Globals::camera.get_dir());
    }
    if (keystate[SDL_SCANCODE_S]) {
        Globals::camera.set_pos(Globals::camera.get_pos() - Globals::movement_speed * Globals::camera.get_dir());
    }
    /* Movement along right vector of camera */
    if (keystate[SDL_SCANCODE_A]) {
        Globals::camera.set_pos(Globals::camera.get_pos() - Globals::movement_speed *  glm::normalize(glm::cross(Globals::camera.get_dir(), Globals::camera.get_up())));
    }
    if (keystate[SDL_SCANCODE_D]) {
        Globals::camera.set_pos(Globals::camera.get_pos() + Globals::movement_speed * glm::normalize(glm::cross(Globals::camera.get_dir(), Globals::camera.get_up())));
    }
    /* Movement along up vector of camera */
    if (keystate[SDL_SCANCODE_SPACE]) {
        Globals::camera.set_pos(Globals::camera.get_pos() + Globals::movement_speed * Globals::camera.get_up());
    }
    if (keystate[SDL_SCANCODE_LSHIFT]) {
        Globals::camera.set_pos(Globals::camera.get_pos() - Globals::movement_speed * Globals::camera.get_up());
    }
}