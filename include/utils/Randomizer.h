#ifndef MICROMOUSE_INCLUDE_UTILS_RANDOMIZER_H_
#define MICROMOUSE_INCLUDE_UTILS_RANDOMIZER_H_

#include <random>
#include <vector>
#include "../model/Direction.h"

class Randomizer {
public:
  template<typename T>
  static T GetRandom(T min, T max);

  template<class T>
  static T &GetRandomElement(std::vector<T> &elements);

  static bool GetRandomBool();

  static Direction GetRandomDirection();

private:
  static std::mt19937 &GetEngine();
};

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

template<typename T>
T &Randomizer::GetRandomElement(std::vector<T> &elements) {
  if (elements.empty()) {
    throw std::invalid_argument("GetRandomElement: elements vector is empty.");
  }
  return elements[GetRandom(0, static_cast<int>(elements.size()) - 1)];
}

#endif //MICROMOUSE_INCLUDE_UTILS_RANDOMIZER_H_
