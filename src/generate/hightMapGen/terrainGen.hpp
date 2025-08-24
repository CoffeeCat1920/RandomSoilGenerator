#pragma once

#include <cstdint>
#include <vector>

namespace HeightMapGen {
  std::vector<uint8_t> GenerateNewHeightMap(uint32_t seed, int32_t width, uint32_t height);
}
