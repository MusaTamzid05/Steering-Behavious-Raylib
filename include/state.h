#ifndef STATE_H
#define STATE_H

struct State {
    enum Type {
        Pause = 0,
        Run,
        Idle
    };

    State(const Type& type);
    virtual ~State();

    virtual void on_enter() = 0;
    virtual void on_execute(float delta_time) = 0;
    virtual void on_exit() = 0;

    Type type;

};

#endif
