#include "kinematic.h"

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
