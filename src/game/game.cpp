#include "game.hpp"
#include "worldGrid/grid.hpp"
#include <cstdint>

Game::Game(uint8_t width, uint8_t height) : worldGrid(width, height) {}

void Game::Init() {
  worldGrid.Init();
}

void Game::Draw() {
  worldGrid.Draw();
}
