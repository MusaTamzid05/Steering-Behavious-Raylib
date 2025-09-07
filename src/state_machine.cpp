#include "state_machine.h"

StateMachine::StateMachine():m_current_state(nullptr){

}

StateMachine::~StateMachine() {

}


void StateMachine::change_state(State* new_state) {
    if(m_current_state != nullptr) {
        if(m_current_state->type != new_state->type)
            m_current_state->on_exit();
    }

    m_current_state = new_state;
    m_current_state->on_enter();

}
