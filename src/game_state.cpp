#include "game_states.h"
#include "scene.h"
#include "player_states.h"
#include "player.h"
#include "state_machine.h"
#include "camera.h"



namespace GameStates {
    GameState::GameState(Scene* scene, const State::Type& type):
        scene(scene),
        State(type),
        player(scene->player),
        camera_instance(MCamera::get_instance())
    {}

    GameState::~GameState() {}


    PauseState::PauseState(Scene* scene):
        GameState(scene, State::Type::Pause) {}


    PauseState::~PauseState() {}

    void PauseState::on_enter() {
        player->m_state_machine->change_state(
                new PlayerStates::PauseState(player));

    }
    
    void PauseState::on_execute(float delta_time) {
        player->m_state_machine->m_current_state->on_execute(delta_time);

    }

    void PauseState::on_exit() {

    }
    
    void PauseState::render() {
        BeginMode3D(camera_instance->camera);
            player->update(GetFPS());
            player->render();
            DrawGrid(30, 2.0f);
        EndMode3D();

    }

}


