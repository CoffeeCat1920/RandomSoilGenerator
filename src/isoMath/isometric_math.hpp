#include "raylib/raylib.h"
#include "core/settings.hpp"

namespace IsocMath {

  inline Vector2 ToIsometric(Vector2 vec) {

    float screenWidth = (float)GetScreenWidth();

    float x = (vec.x - vec.y) * (TILE_WIDTH * 0.5f) - (TILE_WIDTH * 0.5f) + screenWidth/2;
    float y = (vec.x + vec.y) * (TILE_HEIGHT * 0.5f) + (GetScreenHeight()/2.0f);

    return Vector2{x, y};
  }

  inline Vector2 ToIsometricWithZ(Vector2 vec, float z) {

    float screenWidth = (float)GetScreenWidth();
    vec.x -= z;
    vec.y -= z;

    float x = (vec.x - vec.y) * (TILE_WIDTH * 0.5f) - (TILE_WIDTH * 0.5f) + screenWidth/2;
    float y = (vec.x + vec.y) * (TILE_HEIGHT * 0.5f) + (GetScreenHeight()/2.0f);

    return Vector2{x, y};
  }

  inline Vector2 ToWorld(Vector2 vec) {

    float screenWidth = (float)GetScreenWidth();
    
    Vector2 worldVec;
    worldVec.x = (vec.x + (TILE_WIDTH * 0.5f) - (screenWidth / 2)) / TILE_HEIGHT;
    worldVec.y = (vec.y - (vec.x + (TILE_WIDTH * 0.5f) - (screenWidth / 2))) / TILE_WIDTH;

    return worldVec;
  }
}
