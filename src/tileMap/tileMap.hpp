#pragma once

#include "dataStruts/tileMap.hpp"

class TileMap {
private:
  TileMapData tileMapData;

public:
  TileMap(TileMapData tileMapData);

  void Init();
  void Draw();
};
