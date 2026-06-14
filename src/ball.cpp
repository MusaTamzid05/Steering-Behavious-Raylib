#include "ball.h"
#include "consts.h"


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
    if(IsKeyDown(KEY_A))
        position.x -= BALL_SPEED;
    else if(IsKeyDown(KEY_D))
        position.x += BALL_SPEED;
    else if(IsKeyDown(KEY_W))
        position.z -= BALL_SPEED;
    else if(IsKeyDown(KEY_S))
        position.z += BALL_SPEED;

}
