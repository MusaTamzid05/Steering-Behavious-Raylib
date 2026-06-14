#ifndef COLLISION_OBJECT_H
#define COLLISION_OBJECT_H

#include "game_object.h"

struct CollisionObject {
    CollisionObject();
    virtual ~CollisionObject();

    void init(
            GameObject* src,
            const Vector3& offset_pos,
            const Vector3& offset_scale
            );

    void update(float delta_time);
    void render();


    BoundingBox get_bounding_box() const;
    bool check_collision_with(CollisionObject* other);

    void activate(); // meaning object has collided
    void deactivate(); // meaning object has collided

    GameObject* src;

    Vector3 position;
    Vector3 scale;

    Color color;

    Vector3 offset_pos;
    Vector3 offset_scale;

    bool collide_flag;




};

#endif
