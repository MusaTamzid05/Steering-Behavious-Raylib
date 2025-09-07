#include "player.h"
#include "consts.h"
#include "state_machine.h"
#include "player_states.h"
#include <raymath.h>

Player::Player():
    is_player_init(false),
    m_state_machine(nullptr) {

    }


Player::~Player() {
    delete m_state_machine;
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

    
    model_animations = LoadModelAnimations(
            PLAYER_MODEL_PATH.c_str(),
            &total_animations
            );

    current_anim_frame = 0;
    m_state_machine = new StateMachine();
    m_state_machine->change_state(
            new PlayerStates::IdleState(this)
            );


}

void Player::render() {
    m_state_machine->m_current_state->render();
}

void Player::update(float delta_time) {
    m_state_machine->m_current_state->on_execute(delta_time);
}


void Player::set_animation(const AnimationType& anim_type) {
    current_animation = model_animations[anim_type]; 
}


void Player::update_animation() {
    current_anim_frame = (current_anim_frame + 1) % current_animation.frameCount;
    UpdateModelAnimation(model, current_animation, current_anim_frame);
}

void Player::draw_model() {
    DrawModel(
            model,
            position,
            0.01f, // again the way the model was save !!
            WHITE
            );

}


