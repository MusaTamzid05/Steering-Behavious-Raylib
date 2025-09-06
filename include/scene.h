#ifndef SCENE_H
#define SCENE_H

#include <raylib.h>

struct Player;

struct Scene {
    Scene();
    virtual ~Scene();

    void init();
    void start();

    bool is_scene_init;

    Player* player;

};


#endif
