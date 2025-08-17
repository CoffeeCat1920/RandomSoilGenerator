#pragma once

#include "tileMap/tileSet.hpp"
#include <vector>
#include <cstdint>

namespace TileMapGen {
  std::vector<uint8_t> GenerateNewTileMap(std::vector<uint8_t>& zIndex, TileSet& tileSet);
}
