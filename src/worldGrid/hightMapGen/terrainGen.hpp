#pragma once

#include <cstdint>
#include <vector>

namespace HeightMapGen {
  std::vector<uint8_t> GenerateNewHeightMap(uint32_t seed, int8_t width, uint8_t height);
}
