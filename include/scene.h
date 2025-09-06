#ifndef SCENE_H
#define SCENE_H

#include <raylib.h>

struct Scene {
    Scene();
    virtual ~Scene();

    void init();
    void start();

    bool scene_init;

};


#endif
