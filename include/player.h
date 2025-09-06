#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

struct Player {
    Player();
    virtual ~Player();

    void init(const Vector3& position);
    void render();

    Vector3 position;
    Model model;

    bool is_player_init;

};

#endif
