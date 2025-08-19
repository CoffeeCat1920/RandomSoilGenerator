#include "raylib/raylib.h"
#include "core/settings.hpp"
#include "core/colors.hpp"
#include "game/game.hpp"

int main () {
  
  InitWindow(BLOCK * SCREEN_WIDTH, BLOCK * SCREEN_HEIGHT, "Soil thing");

  SetTargetFPS(60);

  Game game(SCREEN_WIDTH, SCREEN_HEIGHT);

  game.Init();

  while ( !WindowShouldClose() )
  { 

    BeginDrawing();

    game.Draw();

    ClearBackground(GRUVBOX_DARK0);

    EndDrawing();
    
  }

  CloseWindow();

  return 0;
}
