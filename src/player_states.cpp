#include "player_states.h"
#include "player.h"


namespace PlayerStates {
    PauseState::PauseState(Player* player):
        State(State::Type::Pause), 
        player(player) {

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
        State(State::Type::Idle), 
        player(player) {

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
        State(State::Type::Run), 
        player(player) {

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
