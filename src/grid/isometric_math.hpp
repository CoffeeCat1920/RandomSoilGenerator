#include "raylib.h"
#include "settings.hpp"

namespace IsocMath {

  inline Vector2 ToIsometric(Vector2 vec) {

    float x = (vec.x - vec.y) * (TILE_WIDTH * 0.5f) - (TILE_WIDTH * 0.5f) + (float)GetScreenWidth()/2;
    float y = (vec.x + vec.y) * (TILE_HEIGHT * 0.5f);

    return Vector2{x, y};
  }

  inline Vector2 ToWorld(Vector2 vec) {
    float x = 0.5f * ( (vec.x * 2.0f) / TILE_WIDTH  + (vec.y * 4.0f) / TILE_HEIGHT );
    float y = 0.5f * ( (vec.x * 4.0f) / TILE_HEIGHT - (vec.y * 2.0f) / TILE_WIDTH );

    return { x, y };
  }

}
