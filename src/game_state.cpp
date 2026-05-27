#include "game_states.h"
#include "scene.h"
#include "player_states.h"
#include "player.h"
#include "state_machine.h"
#include "camera.h"
#include "ball.h"



namespace GameStates {
    GameState::GameState(
            Scene* scene,
            const State::Type& type,
            const std::string& state_render_text
            ):
        scene(scene),
        State(type),
        player(scene->player),
        ball(scene->ball),
        camera_instance(MCamera::get_instance()),
        state_render_text(state_render_text) {


    }

    GameState::~GameState() {}


    void GameState::render() {
        BeginMode3D(camera_instance->camera);
            player->render();
            ball->render();
            DrawGrid(30, 2.0f);
        EndMode3D();
        DrawText(state_render_text.c_str(), 10, 20, 20, RED);

    }


    PauseState::PauseState(Scene* scene):
        GameState(scene, State::Type::Pause, "Pause State") {}


    PauseState::~PauseState() {}

    void PauseState::on_enter() {
        player->m_state_machine->change_state(
                new PlayerStates::PauseState(player));

    }
    
    void PauseState::on_execute(float delta_time) {
        player->m_state_machine->m_current_state->on_execute(delta_time);
        ball->update(delta_time);

        if(IsKeyPressed(KEY_ENTER)) 
            scene->m_state_machine->change_state(
                    new PlayState(scene));

        

    }

    void PauseState::on_exit() {

    }


    PlayState::PlayState(Scene* scene):
        GameState(scene, State::Type::Run, "Play State") {}


    PlayState::~PlayState() {}

    void PlayState::on_enter() {
        player->m_state_machine->change_state(
                new PlayerStates::IdleState(player));

    }
    
    void PlayState::on_execute(float delta_time) {
        player->m_state_machine->m_current_state->on_execute(delta_time);
        ball->update(delta_time);

        if(IsKeyPressed(KEY_ENTER)) 
            scene->m_state_machine->change_state(
                    new PauseState(scene));


        if(IsKeyPressed(KEY_R)) 
            player->m_state_machine->change_state(
                    new PlayerStates::RunState(player));

        else if(IsKeyPressed(KEY_I)) 
            player->m_state_machine->change_state(
                    new PlayerStates::IdleState(player));

        else if(IsKeyPressed(KEY_S)) 
            player->m_state_machine->change_state(
                    new PlayerStates::SeekState(player, ball));

        

    }

    void PlayState::on_exit() {

    }
    


}


