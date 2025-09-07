#ifndef PLAYER_STATES_H
#define PLAYER_STATES_H

#include "state.h"

struct Player;

namespace PlayerStates {
    struct PauseState : State {
        PauseState(Player* player);
        virtual ~PauseState();

        void on_enter();
        void on_execute(float delta_time);
        void on_exit();
        void render();

        Player* player;

    };


    struct IdleState : State {
        IdleState(Player* player);
        virtual ~IdleState();

        void on_enter();
        void on_execute(float delta_time);
        void on_exit();
        void render();

        Player* player;

    };


    struct RunState : State {
        RunState(Player* player);
        virtual ~RunState();

        void on_enter();
        void on_execute(float delta_time);
        void on_exit();
        void render();

        Player* player;

    };
}


#endif

