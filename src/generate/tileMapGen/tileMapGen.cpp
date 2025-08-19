#include "tileMapGen.hpp"
#include "tileMap/tileSet.hpp"
#include <cstdint>
#include <vector>

std::vector<uint8_t> TileMapGen::GenerateNewTileMap(std::vector<uint8_t>& zIndex, TileSet& tileSet) {
  std::vector<uint8_t> tileMap(zIndex.size(), 0); 
  return tileMap;
}
