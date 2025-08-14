#pragma once

#include <cstdint>
#include <filesystem>
#include <vector>

class TileMap {
private:
  std::filesystem::path dataPath;

  uint8_t x, y;
  uint16_t width, height;

  std::vector<uint8_t> tiles;    
  std::vector<uint8_t> zIndex;  

public:
  TileMap(std::filesystem::path path);

  void Init();
  void Draw();
};
