#pragma once

#include <cstdint>
#include <vector>

struct TileMapData {
  std::vector<uint16_t> tiles;    
  std::vector<uint8_t> zIndex;    
  uint16_t width, height;
};
