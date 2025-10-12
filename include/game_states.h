#ifndef GAME_STATES_H
#define GAME_STATES_H

#include "state.h"
#include <string>
struct Scene;
struct Player;
class MCamera;


namespace GameStates {
    struct GameState : State {
        GameState(
                Scene* scene,
                const State::Type& type,
                const std::string& state_render_text
                );
        virtual ~GameState();


        virtual void on_enter() = 0;
        virtual void on_execute(float delta_time) = 0;
        virtual void on_exit() = 0;
        virtual void render();

        Scene* scene;
        Player* player;
        MCamera* camera_instance;

        std::string state_render_text;


    };

    struct PauseState : GameState {
        PauseState(Scene* scene);
        virtual ~PauseState();

        void on_enter();
        void on_execute(float delta_time);
        void on_exit();

    };


    struct IdleState : GameState {
        IdleState(Scene* scene);
        virtual ~IdleState();

        void on_enter();
        void on_execute(float delta_time);
        void on_exit();

    };

    struct RunState : GameState {
        RunState(Scene* scene);
        virtual ~RunState();

        void on_enter();
        void on_execute(float delta_time);
        void on_exit();

    };

}


#endif
