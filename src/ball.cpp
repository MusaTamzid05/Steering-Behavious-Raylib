#include "ball.h"
#include "consts.h"
#include "collision_object.h"


Ball::Ball() {

}


Ball::~Ball() {

}

void Ball::init(const Vector3& position, float scale) {
    Vector3 scale_vec = (Vector3) { scale, scale, scale};
    GameObject::init(position, scale_vec);
    m_collision_object = new CollisionObject();
    m_collision_object->init(
            this,
            (Vector3) { 0.0f, 0.0f, 0.0f},
            (Vector3) { 1.0f, 1.0f, 1.0f}
            );

}

void Ball::render() {
    DrawSphereWires(
            position,
            scale.x,
            10,
            10,
            GREEN
            );

    m_collision_object->render();

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

    m_collision_object->update(delta_time);

}


