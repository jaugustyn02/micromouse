#include <chrono>
#include <random>

#include "utils/Randomizer.h"
#include "core/GlobalConfig.h"

std::mt19937 &Randomizer::GetEngine() {
  static const long long seed = GLOBAL::RANDOM::USE_RANDOM_SEED
                                ? std::chrono::system_clock::now().time_since_epoch().count()
                                : GLOBAL::RANDOM::SEED;
  static std::mt19937 randomEngine(seed);
  return randomEngine;
}
