#pragma once

#include "raylib/raylib.h"

struct Globals {
    Camera2D camera;
    int screenWidth{};
    int screenHeight{};
};

inline Globals global {
    .camera = {
        .offset = { 0.0f, 0.0f },
        .target = { 0.0f, 0.0f },
        .rotation = 0.0f,
        .zoom = 1.4f
    },
    .screenWidth = GetScreenWidth(),
    .screenHeight = GetScreenHeight()
};
