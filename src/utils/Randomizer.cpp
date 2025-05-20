#include <chrono>
#include <random>

#include "utils/Randomizer.h"
#include "core/GlobalConfig.h"

bool Randomizer::GetRandomBool() {
  return GetRandom(0, 1);
}

Direction Randomizer::GetRandomDirection() {
  return static_cast<Direction>(GetRandom(0, 3));
}

std::mt19937 &Randomizer::GetEngine() {
  static const long long seed = GLOBAL::RANDOM::USE_RANDOM_SEED
                                ? std::chrono::system_clock::now().time_since_epoch().count()
                                : GLOBAL::RANDOM::SEED;
  static std::mt19937 randomEngine(seed);
  return randomEngine;
}
