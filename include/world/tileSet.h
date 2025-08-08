#pragma once

#include <cstdint>
#include <memory>
#include <unordered_map>

#include "./tile.h"
#include "./tileIds.h"

class TileSet {

private:

  std::unordered_map<uint16_t, std::shared_ptr<Tile>> tileSet;
  
public:

  TileSet();
  ~TileSet();

  void Init();
  void DrawTile(uint16_t tileId, float x, float y);

};
