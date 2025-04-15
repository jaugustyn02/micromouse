#ifndef MICROMOUSE_INCLUDE_MODEL_MOUSEBRAINTYPE_H_
#define MICROMOUSE_INCLUDE_MODEL_MOUSEBRAINTYPE_H_

#include <string>

enum MouseBrainType {
  RANDOM,
  ADVANCED
};

inline std::string toString(MouseBrainType type) {
  switch (type) {
    case RANDOM: return "RANDOM";
    case ADVANCED: return "ADVANCED";
    default: return "UNKNOWN";
  }
}

#endif //MICROMOUSE_INCLUDE_MODEL_MOUSEBRAINTYPE_H_
