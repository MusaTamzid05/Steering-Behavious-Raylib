#ifndef GAME_STATES_H
#define GAME_STATES_H

#include "state.h"
struct Scene;
struct Player;
class MCamera;


namespace GameStates {
    struct GameState : State {
        GameState(Scene* scene, const State::Type& type);
        virtual ~GameState();


        virtual void on_enter() = 0;
        virtual void on_execute(float delta_time) = 0;
        virtual void on_exit() = 0;
        virtual void render() = 0;

        Scene* scene;
        Player* player;
        MCamera* camera_instance;


    };

    struct PauseState : GameState {
        PauseState(Scene* scene);
        virtual ~PauseState();

        void on_enter();
        void on_execute(float delta_time);
        void on_exit();
        void render();


    };

}


#endif
