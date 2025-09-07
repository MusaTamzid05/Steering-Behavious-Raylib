#include "scene.h"
#include "consts.h"
#include "camera.h"
#include "player.h"
#include <iostream>


Scene::Scene():
    is_scene_init(false),
    player(nullptr) {

}

Scene::~Scene() {
    delete player;
    CloseWindow();
}

void Scene::init() {
    InitWindow(
            WINDOW_WIDTH,
            WINDOW_HEIGHT,
            TITLE.c_str()
            );

    SetTargetFPS(FPS);
    MCamera::get_instance()->init((Vector3) { 0.0f, 3.0f, 0.0f});

    player = new Player();
    player->init((Vector3) { 0.0f, 0.0f, -6.0f});
    MCamera::get_instance()->look_at(player->position);



    is_scene_init= true;

}

void Scene::start() {
    if(!is_scene_init) {
        std::cerr << "[X] Scene is not initialize\n";
        return;
    }

    MCamera* m_camera =  MCamera::get_instance();

    while(!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);

            BeginMode3D(m_camera->camera);
                player->update(GetFPS());
                player->render();
                DrawGrid(30, 2.0f);
            EndMode3D();

        EndDrawing();
    }
}
