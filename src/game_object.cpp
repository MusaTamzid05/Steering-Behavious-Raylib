#include "game_object.h"

GameObject::GameObject() {

}


GameObject::~GameObject() {

}


void GameObject::init(
        const Vector3& position,
        const Vector3& scale) {
    this->position = position;
    this->scale = scale;

}
