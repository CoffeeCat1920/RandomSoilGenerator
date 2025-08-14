#include "./include/raylib/raylib.h"
#include "./include/core/settings.hpp"
#include "./include/core/colors.hpp"

#include "./src/grid/grid.hpp"

class Game {
  
private:
  
  Grid grid;
  
public:

  Game() {} 

  void Init() {
  }

  void Draw() {
    grid.DrawStencil();
  }
};

int main () {
  
  InitWindow(BLOCK * SCREEN_WIDTH, BLOCK * SCREEN_HEIGHT, "Soil thing");

  SetTargetFPS(60);

  Game game;

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
