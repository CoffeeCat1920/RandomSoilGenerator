#pragma once

#include <cstdint>
#include <vector>

enum class Layer {
  LANDSCAPE,
  PLANTS
};

class WorldGrid {
  
private:

  uint16_t width, height;
  std::vector<uint8_t> zIndex; 
  
public:

  WorldGrid();
  
  void DrawStencil();
};
