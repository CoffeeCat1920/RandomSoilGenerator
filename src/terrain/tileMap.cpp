#include "tileMap.hpp"
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <ios>
#include <stdexcept>

TileMap::TileMap(std::filesystem::path dataPath)
    : dataPath(dataPath)
{
  std::ifstream in(dataPath, std::ios::binary);
  if (!in.is_open()) {
    throw std::runtime_error("ERROR: Can't find TileMap at path: " + dataPath.string() + "\n");
  }

  in.read(reinterpret_cast<char*>(&width), sizeof(width));
  in.read(reinterpret_cast<char*>(&height), sizeof(height));

  tiles.resize(width * height);
  zIndex.resize(width * height);

  in.read(reinterpret_cast<char*>(tiles.data()), tiles.size() * sizeof(uint8_t));

  in.read(reinterpret_cast<char*>(zIndex.data()), zIndex.size() * sizeof(uint8_t));

  if (!in) {
      throw std::runtime_error("ERROR: Failed to fully read TileMap data from: " + dataPath.string() + "\n");
  }
}
