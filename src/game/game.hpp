#pragma once

#include "worldGrid/grid.hpp"

enum GameState {
  PLAYING
};

class Game {
  
private:
  
  WorldGrid worldGrid;

public:

  Game(uint8_t width, uint8_t height); 

  void Init();
  void Draw();
};
