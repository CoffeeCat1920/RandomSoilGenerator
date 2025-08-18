#include "tileMapGen.hpp"
#include "tileMap/tileSet.hpp"
#include <cstdint>
#include <vector>

std::vector<uint8_t> TileMapGen::GenerateNewTileMap(std::vector<uint8_t>& zIndex, TileSet& tileSet) {
  std::vector<uint8_t> tileMap; 
  tileMap.resize(zIndex.size());

  for (uint8_t z : zIndex) {
    if (z < 3) {
      tileMap.push_back(0);
    } else {
      tileMap.push_back(1);
    }
  }

  return tileMap;
}
