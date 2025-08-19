#include <cstdint>
#include <vector>

#include "core/settings.hpp"
#include "FSL/FastNoiseLite.h"
#include "terrainGen.hpp"

std::vector<uint8_t> HeightMapGen::GenerateNewHeightMap(uint32_t seed, int8_t width, uint8_t height) {

  std::vector<uint8_t> zIndex(width * height, 0);

  FastNoiseLite noise;
  noise.SetSeed(seed);  
  noise.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2);

  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      float n = noise.GetNoise((float)x, (float)y);
      uint8_t value = static_cast<uint8_t>((n + 1.0f) * 0.5f * MAX_HEIGHT);
      zIndex[y * width + x] = value;
    }
  }

  return zIndex;
}
