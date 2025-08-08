#include "./include/raylib/raylib.h"
#include "./include/core/settings.h"
#include "./include/core/colors.h"
#include "include/world/tileIds.h"
#include "include/world/tileSet.h"

class Game {
  
private:

  TileSet tileSet;

public:

  void Init() {
    tileSet.Init();
  }

  void Draw() {
    tileSet.DrawTile(GRASS, BLOCK_X * 0, BLOCK_Y * 0);
    tileSet.DrawTile(GRASS, BLOCK_X * 1, BLOCK_Y * 1);
  }

};

int main (int argc, char *argv[]) {
  
  InitWindow(BLOCK * BOARD, BLOCK * BOARD, "Soil thing");
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
