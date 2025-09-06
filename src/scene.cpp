#include "scene.h"
#include "consts.h"
#include "camera.h"
#include <iostream>


Scene::Scene():scene_init(false){

}

Scene::~Scene() {

}

void Scene::init() {
    InitWindow(
            WINDOW_WIDTH,
            WINDOW_HEIGHT,
            title.c_str()
            );

    SetTargetFPS(FPS);
    MCamera::get_instance()->init((Vector3) { 0.0f, 0.3f, 0.0f});
    scene_init = true;

}

void Scene::start() {
    if(!scene_init) {
        std::cerr << "[X] Scene is not initialize\n";
        return;
    }

    MCamera* m_camera =  MCamera::get_instance();

    while(!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);

            BeginMode3D(m_camera->camera);
            EndMode3D();

        EndDrawing();
    }
}
