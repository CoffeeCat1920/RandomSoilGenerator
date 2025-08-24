#pragma once

#include "worldGrid/grid.hpp"

enum GameState {
  PLAYING
};

class Game {
  
private:
  
  WorldGrid worldGrid;

public:

  Game(uint32_t width, uint32_t height); 

  void Init();
  void Draw();
};
