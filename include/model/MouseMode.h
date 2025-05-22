#ifndef MICROMOUSE_INCLUDE_MODEL_MOUSEMODE_H_
#define MICROMOUSE_INCLUDE_MODEL_MOUSEMODE_H_

/**
 * @brief The MouseMode enum class represents the different modes of operation for the micromouse.
 * It is used to identify the current mode of the micromouse during its operation.
 */
enum MouseMode {
  EXPLORATION,
  EXPLORATION_ON_RETURN,
  FASTEST_PATH,
  RETURN,
};

/**
 * @brief Converts a MouseMode enum value to its string representation.
 * @param mode The mouse mode to convert.
 * @return The string representation of the mouse mode.
 */
inline std::string toString(const MouseMode mode) {
  switch (mode) {
    case EXPLORATION: return "Exploration";
    case EXPLORATION_ON_RETURN: return "Exploration on return";
    case FASTEST_PATH: return "Fastest Path";
    case RETURN: return "Return";
    default: return std::to_string(mode);
  }
}

#endif //MICROMOUSE_INCLUDE_MODEL_MOUSEMODE_H_
