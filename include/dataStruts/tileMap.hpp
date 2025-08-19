#pragma once

#include <cstdint>
#include <vector>

struct TileMapData {
  std::vector<uint16_t> tiles;    
  uint16_t width, height;
};
