#pragma once

#include "dataStruts/tileMap.hpp"

class TileMap {
private:
  TileMapData tileMapData;

public:
  TileMap();

  void Init(TileMapData tileMapData);
  void Draw();
};
