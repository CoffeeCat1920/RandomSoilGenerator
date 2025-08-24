#pragma once

#include "tileMap/tileMap.hpp"
#include "tileMap/tileSet.hpp"
#include <cstdint>
#include <vector>

enum class Layer {
  LANDSCAPE,
  PLANTS
};

class WorldGrid {
  
private:
  std::vector<uint8_t> zIndex; 
  TileSet tileSet;
  TileMap tileMap;

  uint16_t width, height;

  void DrawStencil();
public:

  WorldGrid(uint32_t width, uint32_t height);
  
  void Init();
  void Draw();
};
