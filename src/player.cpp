#include "player.h"
#include "consts.h"
#include <raymath.h>

Player::Player():
    is_player_init(false) {

    }


Player::~Player() {

}

void Player::init(const Vector3& position) {
    this->position = position;
    model = LoadModel(PLAYER_MODEL_PATH.c_str());

    // this is because the way the model
    // was saved with blender
    //

    model.transform = MatrixRotateXYZ (
            (Vector3) {
                       DEG2RAD * 90,
                       DEG2RAD * 0,
                       DEG2RAD * 0
                     }
            );

    is_player_init = true;

}

void Player::render() {
    DrawModel(
            model,
            position,
            0.01f, // again the way the model was save !!
            WHITE
            );
}
