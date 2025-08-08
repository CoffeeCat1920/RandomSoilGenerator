#include "../../include/world/tileSet.h"
#include "../../include/world/tileIds.h"
#include <cstdint>

TileSet::TileSet() {}
TileSet::~TileSet() {}

void TileSet::Init() {
  tileSet[GRASS] = std::make_shared<Tile>("assets/Tiles/png/Grass.png");
  tileSet[STONE] = std::make_shared<Tile>("assets/Tiles/png/Stone.png");
}

void TileSet::DrawTile(uint16_t tileId, float x, float y) {
  if (tileId < tileSet.size() && tileSet[tileId]) {
      tileSet[tileId]->Draw(x, y);
  }
}
