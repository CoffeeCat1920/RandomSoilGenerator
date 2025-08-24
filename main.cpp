#include "global/global.hpp"
#include "raylib/raylib.h"
#include "core/settings.hpp"
#include "core/colors.hpp"
#include "game/game.hpp"

int main () {
  
  InitWindow(BLOCK * SCREEN_WIDTH, BLOCK * SCREEN_HEIGHT, "Soil thing");

  SetTargetFPS(60);

  Game game(BOARD_X, BOARD_Y);

  game.Init();

  Vector2 prevMousePos = GetMousePosition();

  while ( !WindowShouldClose() )
  {    

    // Update
    if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
    {
        Vector2 mousePos = GetMousePosition();
        Vector2 delta = { mousePos.x - prevMousePos.x, mousePos.y - prevMousePos.y };

        // Move the camera target opposite to mouse movement (drag effect)
        global.camera.target.x -= delta.x / global.camera.zoom;
        global.camera.target.y -= delta.y / global.camera.zoom;
        
        prevMousePos = mousePos;
    }
    else
    {
        prevMousePos = GetMousePosition();
    }

    // Draw
    BeginDrawing();
    ClearBackground(GRUVBOX_DARK0);

    int fps = GetFPS();
    int textWidth = MeasureText(TextFormat("%d FPS", fps), 20);
    DrawRectangle(BLOCK * SCREEN_WIDTH - textWidth - 10, 10, textWidth + 10, 30, BLACK);
    DrawText(TextFormat("%d FPS", fps), BLOCK * SCREEN_WIDTH - textWidth - 5, 15, 20, WHITE);

    BeginMode2D(global.camera);
    game.Draw();
    EndMode2D();

    EndDrawing();

  }

  CloseWindow();

  return 0;
}
