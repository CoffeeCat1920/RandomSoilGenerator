#include "tileSet.hpp"
#include "../../include/nlohmann/json_utils.hpp"
#include "../../include/raylib/raylib.h"
#include "settings.hpp"

#include <cstdint>
#include <fstream>
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

  tileWidth = mapData["tileWidth"];
  tileHeight = mapData["tileHeight"];

  uint8_t id = 0;
  for (int x = 0; x < tileWidth; x += BLOCK) {
    for (int y = 0; y < tileHeight; y += BLOCK) {
      tiles.push_back( std::make_shared<Tile>(id, x, y) );
      id++;
    } 
  }
}
