#ifndef KINEMATIC_H
#define KINEMATIC_H

#include <raylib.h>

struct Kinematic {
    Kinematic();
    virtual ~Kinematic();

    void init(
            const Vector3& velocity,
            const Vector3& acceleration
            );

    Vector3 velocity;
    Vector3 acceleration;


};

#endif
