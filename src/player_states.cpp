#include "player_states.h"
#include "player.h"


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


}
