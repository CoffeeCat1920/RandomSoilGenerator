#pragma once

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
  std::vector<uint8_t> tileMap;

  TileSet tileSet;
  
public:

  WorldGrid();
  
  void DrawStencil();
  void Init();
  void Draw();
};
