#pragma once

#include "raylib.h"
#include <cstdint>
#include <filesystem>
#include <sys/types.h>

struct Tile {
  uint16_t id;
  uint8_t x, y;
  Tile(uint16_t id, uint8_t x, uint8_t y);
};

class TileSet {
  
private:
  std::filesystem::path jsonPath; 
  Texture2D atlas;

  uint8_t atlasWidth, atlasHeight;

  uint8_t tileWidth, tileHeight;

  bool initialied = false;

public:

  TileSet(std::filesystem::path jsonPath); 
  
};
