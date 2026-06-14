#include "kinematic.h"
#include <raymath.h>

Kinematic::Kinematic() {

}

Kinematic::~Kinematic() {

}


void Kinematic::init(
        const Vector3& velocity,
        const Vector3& acceleration
        ) {
    this->velocity = velocity;
    this->acceleration = acceleration;
}

void Kinematic::update(Vector3& position) {
    velocity = Vector3Add(
            velocity,
            acceleration
            );

    position = Vector3Add(position, velocity);
    acceleration = (Vector3) { 0.0f,  0.0f, 0.0f};

}
