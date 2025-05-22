#ifndef MICROMOUSE_INCLUDE_MODEL_MOUSEBRAINTYPE_H_
#define MICROMOUSE_INCLUDE_MODEL_MOUSEBRAINTYPE_H_

#include <string>

/**
 * @brief The MouseBrainType enum class represents the different types of mouse brains.
 * It is used to identify the type of brain used by the micromouse.
 */
enum MouseBrainType {
  RANDOM,
  ADVANCED
};

/**
 * @brief Converts a MouseBrainType enum value to its string representation.
 * @param type The mouse brain type to convert.
 * @return The string representation of the mouse brain type.
 */
inline std::string toString(MouseBrainType type) {
  switch (type) {
    case RANDOM: return "RANDOM";
    case ADVANCED: return "ADVANCED";
    default: throw std::invalid_argument("Invalid mouse brain type");
  }
}

#endif //MICROMOUSE_INCLUDE_MODEL_MOUSEBRAINTYPE_H_
