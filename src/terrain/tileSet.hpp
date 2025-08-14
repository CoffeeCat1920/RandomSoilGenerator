#pragma once

#include "raylib.h"
#include <cstdint>
#include <filesystem>
#include <memory>
#include <sys/types.h>
#include <vector>

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

  std::vector<std::shared_ptr<Tile>> tiles;

public:

  TileSet(std::filesystem::path jsonPath); 
  
};
