#include "ball.h"
#include "consts.h"


Ball::Ball() {

}


Ball::~Ball() {

}

void Ball::init(const Vector3& position, float scale) {
    Vector3 scale_vec = (Vector3) { scale, scale, scale};
    GameObject::init(position, scale_vec);

}

void Ball::render() {
    DrawSphereWires(
            position,
            scale.x,
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
        position.z += BALL_SPEED; }
