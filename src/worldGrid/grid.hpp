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

  uint8_t width, height;

  void DrawStencil();
public:

  WorldGrid(uint8_t width, uint8_t height);
  
  void Init();
  void Draw();
};
