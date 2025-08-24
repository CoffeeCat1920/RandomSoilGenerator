#include "grid.hpp"
#include "dataStruts/tileMap.hpp"
#include "isoMath/isometric_math.hpp"
#include "raylib/raylib.h"
#include "core/settings.hpp"
#include "core/colors.hpp"
#include "tileMap/tileMap.hpp"
#include "tileMap/tileSet.hpp"
#include "generate/hightMapGen/terrainGen.hpp"
#include "generate/tileMapGen/tileMapGen.hpp"

#include <cstdint>
#include <cstdio>
#include <vector>

WorldGrid::WorldGrid(uint32_t width, uint32_t height) :
  tileSet("assets/Tiled/TileSets/Generic_Tileset.json"),
  tileMap(tileSet),
  width(width),
  height(height)
{
  zIndex = HeightMapGen::GenerateNewHeightMap(497019, width, height);
  std::vector<uint16_t> tiles= TileMapGen::GenerateNewTileMap(zIndex, tileSet);
}

void WorldGrid::DrawStencil() {
  
  // for (int x = 0; x <= BOARD_X; x++) {
  //   Vector2 sp = IsocMath::ToIsometric( Vector2{ (float)x, 0 });
  //   Vector2 ep = IsocMath::ToIsometric( Vector2{ (float)x, (float)BOARD_Y });
  //   DrawLineEx(sp, ep, 1.5f, GRUVBOX_LIGHT0);
  // }
  //
  // for (int y = 0; y <= BOARD_Y; y++) {
  //   Vector2 sp = IsocMath::ToIsometric( Vector2{ 0, (float)y });
  //   Vector2 ep = IsocMath::ToIsometric( Vector2{ (float)BOARD_X, (float)y });
  //   DrawLineEx(sp, ep, 1.5f, GRUVBOX_LIGHT0);
  // }
  //
  for (int x = 0; x < BOARD_X; x++) {
    for (int y = 0; y < BOARD_X; y++) {
      uint8_t height = zIndex[y * BOARD_X + x];
      Vector2 pos = IsocMath::ToIsometric( Vector2{(float)x, (float)y - 1} );
      char buffer[4]; 
      snprintf(buffer, sizeof(buffer), "%u", height);
      DrawText(buffer, pos.x, pos.y + 10, 12.0f, GRUVBOX_AQUA);
    }
  }

  return;
}

void WorldGrid::Init() {
  std::vector<uint16_t> tiles = TileMapGen::GenerateNewTileMap(zIndex, tileSet);
  TileMapData tileMapData;
  tileMapData.tiles = tiles;
  tileMapData.zIndex = zIndex;
  tileMapData.width = width;
  tileMapData.height = height;
  tileMap.Init(tileMapData); 
}

void WorldGrid::Draw() {
  // tileSet.DrawTile(0, GetScreenWidth()/2, GetScreenHeight()/2);
  tileMap.Draw();
  // DrawStencil();
}
