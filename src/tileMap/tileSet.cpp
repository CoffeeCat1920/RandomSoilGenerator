#include "tileSet.hpp"
#include "nlohmann/json_utils.hpp"
#include "raylib/raylib.h"
#include "isoMath/isometric_math.hpp"
#include "core/settings.hpp"

#include <cstdint>
#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

Tile::Tile(uint16_t id, uint8_t x, uint8_t y) : 
  id(id), 
  x(x), 
  y(y) {}

TileSet::TileSet(std::filesystem::path jsonPath) : 
  jsonPath(jsonPath) 
{
  std::ifstream file(jsonPath);
  if (!file.is_open()) {
    throw std::runtime_error("ERROR: Couldn't find Tileset [" + jsonPath.string() + "]\n");
  }

  json mapData;
  file >> mapData;

  std::filesystem::path atlasPath;
  atlasPath = std::filesystem::path(
      mapData["image"].get<std::string>().replace(0, 5, "./assets")
  );
  atlas = LoadTexture(atlasPath.c_str());

  atlasWidth = mapData["imagewidth"];
  atlasHeight = mapData["imageheight"];

  tileWidth = mapData["tilewidth"];
  tileHeight = mapData["tileheight"];

  uint8_t id = 0;
  for (int x = 0; x < atlasWidth; x += BLOCK) {
    for (int y = 0; y < atlasHeight; y += BLOCK) {
      tiles.push_back( std::make_shared<Tile>(id, x, y) );
      id++;
    } 
  }
}

void TileSet::DrawTile(uint16_t id, uint32_t x, uint32_t y, uint8_t z) {
  if (id >= tiles.size()) {
    std::cerr << "ERROR: INVALID TILE OF id:" << id << "\n";
    return;
  }

  std::shared_ptr<Tile> tile = tiles[id];
  Rectangle rec = Rectangle{(float)tile->x, (float)tile->y, (float)tileWidth, (float)tileHeight};   
  Vector2 pos = IsocMath::ToIsometricWithZ(Vector2{(float)x, (float)y}, z); 
  DrawTextureRec(atlas, rec, pos, WHITE);
}
