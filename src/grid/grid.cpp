#include "grid.hpp"
#include "isometric_math.hpp"
#include "../core/settings.hpp"
#include "colors.hpp"
#include "raylib.h"

void Grid::DrawStencil() {
  
  for (int x = 0; x <= BOARD_X; x++) {
      Vector2 sp = IsocMath::ToIsometric( Vector2{ (float)x, 0 });
      Vector2 ep = IsocMath::ToIsometric( Vector2{ (float)x, (float)BOARD_Y });
      DrawLineEx(sp, ep, 1.5f, GRUVBOX_LIGHT0);
  }

  for (int y = 0; y <= BOARD_Y; y++) {
      Vector2 sp = IsocMath::ToIsometric( Vector2{ 0, (float)y });
      Vector2 ep = IsocMath::ToIsometric( Vector2{ (float)BOARD_X, (float)y });
      DrawLineEx(sp, ep, 1.5f, GRUVBOX_LIGHT0);
  }

  return;
}
