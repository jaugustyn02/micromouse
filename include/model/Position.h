#ifndef MICROMOUSE_INCLUDE_MODEL_POSITION_H_
#define MICROMOUSE_INCLUDE_MODEL_POSITION_H_

#include <iostream>
#include "Direction.h"

class Position {
public:
  Position(int x, int y) : x(x), y(y) {
  }

  int getX() const { return x; }
  int getY() const { return y; }

  bool operator<(const Position &other) const {
    return (x == other.x) ? (y < other.y) : (x < other.x);
  }

  bool operator==(const Position &other) const {
    return x == other.x && y == other.y;
  }

  void translate(const Direction direction) {
    switch (direction) {
      case NORTH: y--;
        break;
      case SOUTH: y++;
        break;
      case EAST: x++;
        break;
      case WEST: x--;
        break;
    }
  }

  Position translated(const Direction direction) const {
    switch (direction) {
      case NORTH:
        return {x, y - 1};
      case SOUTH:
        return {x, y + 1};
      case EAST:
        return {x + 1, y};
      default:
      case WEST:
        return {x - 1, y};
    }
  }

  std::string toString() const {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
  }

private:
  int x, y;
};

#endif // MICROMOUSE_INCLUDE_MODEL_POSITION_H_
