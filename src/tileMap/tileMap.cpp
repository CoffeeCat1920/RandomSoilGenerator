#include "tileMap.hpp"
#include "dataStruts/tileMap.hpp"
#include "tileMap/tileSet.hpp"

TileMap::TileMap(TileSet tileSet) : 
  tileSet(tileSet) {}

void TileMap::Init(TileMapData tileMapData) {
  this->tileMapData = tileMapData;
}

void TileMap::Draw() {
  for (int x = 0; x < tileMapData.width; ++x) {
    for (int y = 0; y < tileMapData.height; ++y) {
      int height = tileMapData.zIndex[y * tileMapData.width + x];
      int tileId = tileMapData.tiles[y * tileMapData.width + x];
      tileSet.DrawTile(tileId, x, y, height);
    }
  }
}
