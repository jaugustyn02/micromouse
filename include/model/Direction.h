#ifndef MICROMOUSE_INCLUDE_MODEL_DIRECTION_H_
#define MICROMOUSE_INCLUDE_MODEL_DIRECTION_H_

#include <string>

enum Direction {
  NORTH,
  EAST,
  SOUTH,
  WEST
};

inline std::string toString(Direction direction) {
  switch (direction) {
    case NORTH: return "NORTH";
    case EAST: return "EAST";
    case SOUTH: return "SOUTH";
    case WEST: return "WEST";
  }
}

inline Direction opposite(Direction direction) {
  switch (direction) {
    case NORTH: return SOUTH;
    case EAST: return WEST;
    case SOUTH: return NORTH;
    case WEST: return EAST;
  }
}

#endif //MICROMOUSE_INCLUDE_MODEL_DIRECTION_H_
