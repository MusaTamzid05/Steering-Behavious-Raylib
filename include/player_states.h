#ifndef PLAYER_STATES_H
#define PLAYER_STATES_H

#include "state.h"

struct Player;
struct Ball;

namespace PlayerStates {

    struct BaseState : State {
        BaseState(const  Type& type, Player* player);
        virtual ~BaseState();


        Player* player;

    };
    struct PauseState : BaseState {
        PauseState(Player* player);
        virtual ~PauseState();

        void on_enter();
        void on_execute(float delta_time);
        void on_exit();
        void render();

    };


    struct IdleState : BaseState {
        IdleState(Player* player);
        virtual ~IdleState();

        void on_enter();
        void on_execute(float delta_time);
        void on_exit();
        void render();


    };


    struct RunState : BaseState {
        RunState(Player* player);
        virtual ~RunState();

        void on_enter();
        void on_execute(float delta_time);
        void on_exit();
        void render();


    };


    struct SeekState : BaseState {
        SeekState(Player* player, Ball* ball);
        virtual ~SeekState();

        void on_enter();
        void on_execute(float delta_time);
        void on_exit();
        void render();

        Ball* ball;


    };
}


#endif

