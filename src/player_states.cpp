#include "player_states.h"
#include "player.h"
#include "ball.h"
#include <raymath.h>
#include "consts.h"


namespace PlayerStates {

    BaseState::BaseState( const Type& type, Player* player):
        State(type),
        player(player) {

        }

    BaseState::~BaseState() {

    }


    PauseState::PauseState(Player* player):
        BaseState(State::Type::Pause, player) {

    }

    PauseState::~PauseState() {

    }

    void PauseState::on_enter() {
        player->set_animation(Player::AnimationType::Pause);

    }


    void PauseState::on_execute(float delta_time) {
        player->update_animation();
        player->look_at_ball();

    }

    void PauseState::on_exit() {

    }

    void PauseState::render() {
        player->draw_model();
    }


    IdleState::IdleState(Player* player):
        BaseState(State::Type::Idle, player) {

    }

    IdleState::~IdleState() {

    }

    void IdleState::on_enter() {
        player->set_animation(Player::AnimationType::Idle);

    }


    void IdleState::on_execute(float delta_time) {
        player->update_animation();
        player->look_at_ball();

    }

    void IdleState::on_exit() {

    }

    void IdleState::render() {
        player->draw_model();
    }


    RunState::RunState(Player* player):
        BaseState(State::Type::Run, player) {

    }

    RunState::~RunState() {

    }

    void RunState::on_enter() {
        player->set_animation(Player::AnimationType::Run);

    }


    void RunState::on_execute(float delta_time) {
        player->update_animation();
        player->look_at_ball();

    }

    void RunState::on_exit() {

    }

    void RunState::render() {
        player->draw_model();
    }


    SeekState::SeekState(Player* player, Ball* ball):
        BaseState(State::Type::Run, player), ball(ball) {

    }

    SeekState::~SeekState() {

    }

    void SeekState::on_enter() {
        player->set_animation(Player::AnimationType::Run);

    }


    void SeekState::on_execute(float delta_time) {
        player->update_animation();
        player->look_at_ball();

        Vector3 src_pos = player->position;
        Vector3 target_pos = ball->position;
        Vector3 velocity = player->kinemmatic.velocity;
        Vector3 acceleration = player->kinemmatic.acceleration;

        Vector3 desired = Vector3Subtract(target_pos, src_pos);
        desired = Vector3Normalize(desired);
        desired = Vector3Scale(desired, PLAYER_MAX_SPEED);

        Vector3 steer = Vector3Subtract(desired, velocity);
        steer = Vector3ClampValue(
                steer,
                0.0f,
                PLAYER_MAX_FORCE
                );

        acceleration = Vector3Add(acceleration, steer);
        player->kinemmatic.acceleration = acceleration;
        player->update_movement();


    }

    void SeekState::on_exit() {

    }

    void SeekState::render() {
        player->draw_model();
    }


}
