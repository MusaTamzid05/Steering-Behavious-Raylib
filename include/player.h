#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

struct StateMachine;

struct Player {

    enum AnimationType {
        Idle = 0,
        Run,
        Pause
    };

    Player();
    virtual ~Player();

    void init(const Vector3& position);
    void render();
    void update(float delta_time);


    void set_animation(const AnimationType& anim_type);
    void update_animation();

    void draw_model();

    Vector3 position;
    Model model;

    bool is_player_init;

    ModelAnimation* model_animations;
    ModelAnimation current_animation;
    int total_animations;
    unsigned int current_anim_frame;

    StateMachine* m_state_machine;

    float yaw;

};

#endif
