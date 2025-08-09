#include "../../include/world/tileMap.h"
#include "../../include/nlohmann/json_utils.hpp"
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>

TileMap::TileMap(std::string dataPath) : 
  tileSet("./assets/Tiled/json/TileSet.json"),
  dataPath(dataPath) {}
  
void TileMap::Init() {
  tileSet.Init();

  std::ifstream file(dataPath);
  if (!file.is_open()) {
    std::cerr << "Could not open TileSet.json\n";
    return;
  }

  json mapData;

  file >> mapData;

  mapWidth = mapData["width"];
  mapHeight = mapData["height"];

  for (const auto& layer : mapData["layers"]) {
    layers.push_back(std::make_shared<MapLayer>(layer));
  } 

}

void TileMap::Draw() {
  const std::vector<std::vector<int>> mapLayer = layers[0]->Grid();

  for (int x = 0; x < layers[0]->Width(); ++x) {
    for (int y = 0; y < layers[0]->Height(); ++y) {
        int tileId = mapLayer[x][y];
        tileSet.DrawTile(tileId-1, x, y);
    }
  }
}
