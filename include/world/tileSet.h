#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "./tile.h"

class TileSet {
private:
  std::string dataPath;
  std::vector<std::shared_ptr<Tile>> tiles;


  std::string atlasPath;
  std::string name;

  int imageWidth = 0;
  int imageHeight = 0;

  int tileWidth = 0;
  int tileHeight = 0;

  int tileCount = 0;

  Texture2D atlasTexture;
  
  std::vector<Rectangle> texturesRecs;
  
public:
  TileSet(std::string dataPath);
  ~TileSet();

  int GetTileWidth();
  int GetTileHeight();

  void Init();
  void DrawTile(uint16_t tileId, int x, int y);
};
