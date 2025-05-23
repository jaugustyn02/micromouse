#ifndef MICROMOUSE_INCLUDE_UTILS_RANDOMIZER_H_
#define MICROMOUSE_INCLUDE_UTILS_RANDOMIZER_H_

#include <random>
#include <vector>
#include "model/Direction.h"

/**
 * @brief The Randomizer class provides utility functions for generating random numbers and selecting random elements.
 * It uses the Mersenne Twister engine for random number generation.
 */
class Randomizer {
 public:
  /**
   * @brief Generates a random number between min and max (inclusive).
   * @tparam T The type of the random number (integral or floating-point).
   * @param min The minimum value (inclusive).
   * @param max The maximum value (inclusive).
   * @return A random number between min and max.
   */
  template<typename T>
  static T GetRandom(T min, T max);

  /**
   * @brief Selects a random element from a vector of elements.
   * @tparam T The type of the elements in the vector.
   * @param elements The vector of elements to select from.
   * @return A reference to a random element from the vector.
   */
  template<class T>
  static T &GetRandomElement(std::vector<T> &elements);

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
