#pragma once

#include "dataStruts/tileMap.hpp"
#include <filesystem>

namespace TileMapIO {
  TileMapData Load(std::filesystem::path filePath);
  void Save(std::filesystem::path filePath, TileMapData tileMapData);
  void Create(std::filesystem::path filePath, TileMapData tileMapData);
}
