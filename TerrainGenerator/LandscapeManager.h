#ifndef TG_LANDSCAPEMANAGER_H
#define TG_LANDSCAPEMANAGER_H

#include "ROAMTerrain.h"

/* Class to create and update a landscape. */
class LandscapeManager {
public:
    LandscapeManager();
    ~LandscapeManager();
    /* Creates a landscape and add it to the global renderer. */
    void create_landscape();
    /* Returns the landscape object which can be added to the render list. */
    Object get_landscape();
    /* Updates landscape for the current frame. Must call create_landscape() first. */
    void update_landscape();

private:
    ROAMTerrain* _terrain; //The landscape
    float _length; //Length of the terrain
};

#endif