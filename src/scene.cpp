#include "scene.h"
#include "consts.h"
#include "camera.h"
#include "player.h"
#include "state_machine.h"
#include <iostream>
#include "game_states.h"
#include "ball.h"


Scene::Scene():
    is_scene_init(false),
    player(nullptr) {

}

Scene::~Scene() {
    delete player;
    delete m_state_machine;
    CloseWindow();
}

void Scene::init() {
    InitWindow(
            WINDOW_WIDTH,
            WINDOW_HEIGHT,
            TITLE.c_str()
            );

    SetTargetFPS(FPS);
    MCamera::get_instance()->init((Vector3) { 0.0f, 3.0f, 6.0f});

    ball = new Ball();
    ball->init((Vector3) { 3.0f, 0.0f, -6.0f});


    player = new Player();
    player->init(
            (Vector3) { 0.0f, 0.0f, -6.0f},
            ball
            );
    MCamera::get_instance()->look_at(player->position);

    m_state_machine = new StateMachine();
    m_state_machine->change_state(new GameStates::PauseState(this));



    is_scene_init= true;

}

void Scene::start() {
    if(!is_scene_init) {
        std::cerr << "[X] Scene is not initialize\n";
        return;
    }


    while(!WindowShouldClose()) {
        m_state_machine->m_current_state->on_execute(GetFrameTime());
        BeginDrawing();
            ClearBackground(BLACK);
            m_state_machine->m_current_state->render();
        EndDrawing();
    }
}
