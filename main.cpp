#include "./include/raylib/raylib.h"
#include "./include/core/settings.h"
#include "./include/core/colors.h"
#include "include/world/tileSet.h"

class Game {
  
private:

  TileSet tileSet;

public:

  Game() : 
    tileSet("./assets/Tiled/json/TileSet.json") {}

  void Init() {
    tileSet.Init();
  }

  void Draw() {
    tileSet.DrawTile(0, (float)GetScreenWidth()/2, (float)GetScreenHeight()/2);
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
