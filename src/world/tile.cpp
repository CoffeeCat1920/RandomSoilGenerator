#include "../../include/world/tile.h"
#include <string>

Tile::Tile (std::string path) {
  image = LoadImage(path.c_str());
  texture = LoadTextureFromImage(image);
  UnloadImage(image);
}

Tile::~Tile() {
  UnloadTexture(texture);
}

void Tile::Draw(float x, float y) {
  DrawTexture(texture, x, y, WHITE);   
}
