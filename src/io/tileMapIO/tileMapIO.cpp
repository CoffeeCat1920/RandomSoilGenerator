#include <filesystem>
#include <fstream>
#include <stdexcept>
 
#include "tileMapIO.hpp"
#include "dataStruts/tileMap.hpp"

TileMapData TileMapIO::Load(std::filesystem::path filePath) {

  TileMapData tileMapData;

  if (!std::filesystem::exists(filePath)) {
    throw std::runtime_error("ERROR: Can't find Save file at path: " + filePath.string() + "\n");
  }

  filePath /= "tileMap.dat"; 
  std::ifstream in(filePath, std::ios::binary);
  if (!in.is_open()) {
    throw std::runtime_error("ERROR: Can't find tileMap data file at path: " + filePath.string() + "\n");
  }

  in.read(reinterpret_cast<char*>(&tileMapData.width), sizeof(tileMapData.width));
  in.read(reinterpret_cast<char*>(&tileMapData.height), sizeof(tileMapData.height));
  in.read(reinterpret_cast<char*>(tileMapData.tiles.data()), tileMapData.tiles.size() * sizeof(uint8_t));

  if (!in) {
      throw std::runtime_error("ERROR: Failed to fully read TileMap data from: " + filePath.string() + "\n");
  }

  return tileMapData;
}

void TileMapIO::Save(std::filesystem::path filePath, TileMapData tileMapData) {

  if (!std::filesystem::exists(filePath)) {
    throw std::runtime_error("ERROR: Can't find Save file at path: " + filePath.string() + "\n");
  }

  filePath /= "tileMap.dat";

  if (!std::filesystem::exists(filePath)) {
    throw std::runtime_error("ERROR: TileMap doesn't exists" + filePath.string() + "\n");
  }

  std::ofstream out(filePath, std::ios::binary);
  if (!out.is_open()) {
    throw std::runtime_error("ERROR: Can't find tileMap data file at path: " + filePath.string() + "\n");
  }

  out.write(reinterpret_cast<char*>(&tileMapData.width), sizeof(tileMapData.width));
  out.write(reinterpret_cast<char*>(&tileMapData.height), sizeof(tileMapData.height));
  out.write(reinterpret_cast<char*>(tileMapData.tiles.data()), tileMapData.tiles.size() * sizeof(uint8_t));

  if (!out) {
    throw std::runtime_error("ERROR: Failed to fully write TileMap data to: " + filePath.string() + "\n");
  }

  return;  
}

void TileMapIO::Create(std::filesystem::path filePath, TileMapData tileMapData) {

  if (std::filesystem::exists(filePath)) {
    throw std::runtime_error("ERROR: Can't find Save file at path: " + filePath.string() + "\n");
  }

  std::filesystem::create_directory(filePath);

  filePath /= "tileMap.dat";

  std::ofstream out(filePath); 

  Save(filePath, tileMapData);

}
