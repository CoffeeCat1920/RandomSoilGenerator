#pragma once

#include "dataStruts/tileMap.hpp"
#include "tileMap/tileSet.hpp"

class TileMap {
private:
  TileMapData tileMapData;
  TileSet tileSet;

public:
  TileMap(TileSet tileSet);

  void Init(TileMapData tileMapData);
  void Draw();
};
