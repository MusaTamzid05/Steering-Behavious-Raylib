#include "scene.h"
#include "consts.h"
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
    scene_init = true;

}

void Scene::start() {
    if(!scene_init) {
        std::cerr << "[X] Scene is not initialize\n";
        return;
    }

    while(!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);

        EndDrawing();
    }
}
