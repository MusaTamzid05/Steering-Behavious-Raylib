#include "collision_object.h"
#include <raymath.h>

CollisionObject::CollisionObject() {

}


CollisionObject::~CollisionObject() {

}

void CollisionObject::init(
        GameObject* src,
        const Vector3& offset_pos,
        const Vector3& offset_scale
        ) {
    this->src = src;

    color = GREEN;

    this->offset_pos = offset_pos;
    this->offset_scale = offset_scale;
}

void CollisionObject::update(float delta_time) {
    position = Vector3Add(src->position, offset_pos);
    scale = Vector3Add(src->scale , offset_scale);

}

void CollisionObject::render() {

    DrawCubeWires(
            position,
            scale.x,
            scale.y,
            scale.z,
            color
            );

}
