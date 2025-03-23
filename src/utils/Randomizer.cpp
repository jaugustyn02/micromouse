#include <chrono>
#include <random>

#include "../../include/utils/Randomizer.h"
#include "../../include/core/GlobalConfig.h"

template<typename T>
T Randomizer::GetRandom(T min, T max) {
  if constexpr (std::is_integral_v<T>) {
    std::uniform_int_distribution<T> distribution(min, max);
    return distribution(GetEngine());
  }
  if constexpr (std::is_floating_point_v<T>) {
    std::uniform_real_distribution<T> distribution(min, max);
    return distribution(GetEngine());
  }
  throw std::invalid_argument("GetRandom supports only integral and floating-point types.");
}

bool Randomizer::GetRandomBool() {
  return GetRandom(0, 1);
}

std::mt19937 &Randomizer::GetEngine() {
  static const long long seed = GLOBAL::RANDOM::USE_RANDOM_SEED
                                ? std::chrono::system_clock::now().time_since_epoch().count()
                                : GLOBAL::RANDOM::SEED;
  static std::mt19937 randomEngine(seed);
  return randomEngine;
}
