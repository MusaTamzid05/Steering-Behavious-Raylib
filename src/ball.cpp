#include "ball.h"


Ball::Ball() {

}


Ball::~Ball() {

}

void Ball::init(const Vector3& position, float scale) {
    this->position = position;
    this->scale = scale;

}

void Ball::render() {
    DrawSphereWires(
            position,
            scale,
            10,
            10,
            GREEN
            );

}


void Ball::update(float delta_time) {

}
