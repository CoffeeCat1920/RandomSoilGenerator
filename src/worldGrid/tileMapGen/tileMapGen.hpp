#pragma once

#include "tileMap/tileSet.hpp"
#include <filesystem>
#include <vector>
#include <cstdint>

struct TileMapData {
  uint16_t width, height;
  std::filesystem::path dataPath;
};

namespace TileMapGen {
  std::vector<uint8_t> GenerateNewTileMap(std::vector<uint8_t>& zIndex, TileSet& tileSet, TileMapData tileMapData);
}
