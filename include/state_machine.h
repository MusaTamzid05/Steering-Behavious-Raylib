#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "state.h"

struct StateMachine {
    StateMachine();
    virtual ~StateMachine();

    void change_state(State* new_state);

    State* m_current_state;
};

#endif
