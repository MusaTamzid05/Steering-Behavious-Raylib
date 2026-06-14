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


    this->offset_pos = offset_pos;
    this->offset_scale = offset_scale;
    deactivate();
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


BoundingBox CollisionObject::get_bounding_box() const {
    Vector3 min = (Vector3) {
        position.x - (scale.x / 2.0f),
        position.y - (scale.y / 2.0f),
        position.z - (scale.z / 2.0f)
    };

    Vector3 max = (Vector3) {
        position.x + (scale.x / 2.0f),
        position.y + (scale.y / 2.0f),
        position.z + (scale.z / 2.0f)
    };

    return (BoundingBox){ min, max };

}

bool CollisionObject::check_collision_with(CollisionObject* other) {
    BoundingBox current_box = get_bounding_box();
    BoundingBox other_box = other->get_bounding_box();

    return CheckCollisionBoxes(current_box, other_box);

}

void CollisionObject::activate() {
    collide_flag = true;
    color = RED;
}


void CollisionObject::deactivate() {
    collide_flag = true;
    color = GREEN;
}
