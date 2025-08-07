#include "./include/raylib.h"
#include "./include/settings.h"
#include "./include/colors.h"

int main (int argc, char *argv[]) {
  
  InitWindow(BLOCK * BOARD, BLOCK * BOARD, "Soil thing");
  SetTargetFPS(60);

  while ( !WindowShouldClose() )
  { 

    BeginDrawing();

    ClearBackground(GRUVBOX_DARK0);

    EndDrawing();
    
  }

  CloseWindow();

  return 0;
}
