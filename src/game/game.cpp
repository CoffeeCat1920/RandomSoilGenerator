#include "game.hpp"
#include "worldGrid/grid.hpp"
#include <cstdint>

Game::Game(uint32_t width, uint32_t height) : worldGrid(width, height) {}

void Game::Init() {
  worldGrid.Init();
}

void Game::Draw() {
  worldGrid.Draw();
}
