#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <raylib.h>


struct GameObject {
    GameObject();
    virtual ~GameObject();

    void init(const Vector3& position, const Vector3& scale);

    virtual void render() = 0;
    virtual void update(float delta_time) = 0;

    Vector3 position;
    Vector3 scale;


};

#endif
