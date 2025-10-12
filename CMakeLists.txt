cmake_minimum_required(VERSION 3.0)

project(game)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


SET(SOURCE_FILES
    src/main.cpp
    src/scene.cpp
    src/camera.cpp
    src/player.cpp
    src/state.cpp
    src/state_machine.cpp
    src/player_states.cpp
    src/game_state.cpp
    )



add_executable(game ${SOURCE_FILES})

include_directories(include)
target_link_libraries(game raylib GL pthread dl rt X11)
