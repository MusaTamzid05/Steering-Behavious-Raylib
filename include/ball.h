#ifndef BALL_H
#define BALL_H

#include "game_object.h"

struct Ball : GameObject {
    Ball();
    virtual ~Ball();

    void init(const Vector3& position, float scale=1.0f);

    void render();
    void update(float delta_time);

};


#endif
