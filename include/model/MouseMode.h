#ifndef MICROMOUSE_INCLUDE_MODEL_MOUSEMODE_H_
#define MICROMOUSE_INCLUDE_MODEL_MOUSEMODE_H_

enum MouseMode {
  EXPLORATION,
  EXPLORATION_ON_RETURN,
  FASTEST_PATH,
  RETURN,
};

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
