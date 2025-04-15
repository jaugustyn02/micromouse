#ifndef MICROMOUSE_INCLUDE_MODEL_MOUSEMODE_H_
#define MICROMOUSE_INCLUDE_MODEL_MOUSEMODE_H_

enum MouseMode {
  EXPLORATION,
  FASTEST_PATH
};

inline const std::string toString(MouseMode mode) {
  switch (mode) {
    case EXPLORATION: return "Exploration";
    case FASTEST_PATH: return "Fastest Path";
    default: return "Unknown";
  }
}

#endif //MICROMOUSE_INCLUDE_MODEL_MOUSEMODE_H_
