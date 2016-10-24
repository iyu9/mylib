#include "scene.h"

class scane_manager
{
private:
    scene* current_scene;

public:
    void change_scene(scene* next_scene)
    {
           current_scene = next_scene; 
    }

    void update()
    {
        current_scene->update();        
    }
};
