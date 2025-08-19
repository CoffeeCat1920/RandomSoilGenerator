#include "tileMapGen.hpp"
#include "tileMap/tileSet.hpp"
#include <cstdint>
#include <vector>

std::vector<uint16_t> TileMapGen::GenerateNewTileMap(std::vector<uint8_t>& zIndex, TileSet& tileSet) {
  std::vector<uint16_t> tileMap(zIndex.size(), 0); 
  return tileMap;
}
