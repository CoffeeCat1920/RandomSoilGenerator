#include "../../include/world/tileSet.h"
#include "../../include/world/tileIds.h"
#include "../../include/core/settings.h"
#include <cstdint>

TileSet::TileSet() {}
TileSet::~TileSet() {}

void TileSet::Init() {
  tileSet[GRASS] = std::make_shared<Tile>("assets/Tiles/png/Grass.png");
  tileSet[STONE] = std::make_shared<Tile>("assets/Tiles/png/Stone.png");
}

void TileSet::DrawTile(uint16_t tileId, float x, float y) {
  if (tileId < tileSet.size() && tileSet[tileId]) {
      int positionX = (x - y) * ((float)BLOCK_X / 2);
      int positionY = (x + y) * ((float)BLOCK_Y / 2);
      tileSet[tileId]->Draw(positionX, positionY);
  }
}
