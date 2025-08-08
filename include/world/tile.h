#pragma once

#include "../raylib/raylib.h"
#include <string>

class Tile {

private:
  Image image;
  Texture2D texture;
public:

  Tile(std::string path);
  ~Tile();

  void Draw(float x, float y);

};
