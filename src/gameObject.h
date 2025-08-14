#pragma once

#include <cstdint>

class GameObject {

private:

  uint8_t x, y;
  

public:

  virtual void Init() = 0;
  virtual void Draw() = 0;
};
