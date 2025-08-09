#include "./include/raylib/raylib.h"
#include "./include/core/settings.h"
#include "./include/core/colors.h"
#include "include/world/tileMap.h"
#include "include/world/tileSet.h"

class Game {
  
private:

  TileMap tileMap;
  TileSet tileSet;

public:

  Game() : 
    tileMap("./assets/Tiled/json/tileMap.json"),
    tileSet("./assets/Tiled/json/TileSet.json") {}

  void Init() {
    tileMap.Init();
    tileSet.Init();
  }

  void Draw() {
    tileMap.Draw();
    // tileSet.DrawTile(1, 1, 1);
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
