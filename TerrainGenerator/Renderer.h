#ifndef TG_RENDERER_H
#define TG_RENDERER_H

#include "Object.h"
#include <SDL.h>
#include <map>

/* Class to render objects. */
class Renderer {
public:
    /* Creates a Renderer with no objects to render. */
    Renderer();

    /* Add 'object' to rendering list. If the object is already on the rendering list,
    that object is simply updated. */
    void add_object(Object& object);

    /* Update the view matrices of all objects in the rendering list. All objects
    must name their view matrix uniform 'view_uni_name'. */
    void update_view_uniforms(std::string view_uni_name, glm::mat4& view);

    /* Returns number of objects to render. */
    int get_num_objects();

    /* Render all objects in rendering list. */
    void render(SDL_Window* window);

private:
    /* Vector of objects to render. The mapping is from a VAO number to the corresponding object. */
    std::map<GLuint, Object> _render_objects;
};

#endif