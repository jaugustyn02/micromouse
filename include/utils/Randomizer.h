#ifndef MICROMOUSE_INCLUDE_UTILS_RANDOMIZER_H_
#define MICROMOUSE_INCLUDE_UTILS_RANDOMIZER_H_

#include <random>

class Randomizer {
 public:
  template<typename T>
  static T GetRandom(T min, T max);

  static bool GetRandomBool();

 private:
  static std::mt19937 &GetEngine();
};

#endif //MICROMOUSE_INCLUDE_UTILS_RANDOMIZER_H_
