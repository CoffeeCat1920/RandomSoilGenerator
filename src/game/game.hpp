#pragma once

#include "worldGrid/grid.hpp"

enum GameState {
  PLAYING
};

class Game {
  
private:
  
  WorldGrid worldGrid;

public:

  Game(); 

  void Init();
  void Draw();
};
