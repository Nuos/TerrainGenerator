#include "LandscapeManager.h"
#include "Globals.h"

LandscapeManager::LandscapeManager() {
    _terrain = NULL;
    _length = 1000.0f;
}

LandscapeManager::~LandscapeManager() {
    if (_terrain != NULL) {
        delete _terrain;
    }
}

void LandscapeManager::create_landscape() {
    _terrain = new ROAMTerrain(glm::vec3(0, 0, 0), glm::vec3(_length, 0, _length));
}

Object LandscapeManager::get_landscape() {
    return _terrain->get_object();
}

void LandscapeManager::update_landscape() {
    if (_terrain == NULL) {
        return;
    }
    _terrain->calc();
}
