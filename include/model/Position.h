#ifndef MICROMOUSE_INCLUDE_MODEL_POSITION_H_
#define MICROMOUSE_INCLUDE_MODEL_POSITION_H_

#include <iostream>

class Position {
 public:
  Position(int x, int y) : x(x), y(y) {}

  int getX() const { return x; }
  int getY() const { return y; }

  bool operator<(const Position &other) const {
    return (x == other.x) ? (y < other.y) : (x < other.x);
  }

  bool operator==(const Position &other) const {
    return x == other.x && y == other.y;
  }

  void translate(Direction direction) {
    switch (direction) {
      case NORTH: y--;
        break;
      case SOUTH: y++;
        break;
      case EAST: x++;
        break;
      case WEST :x--;
        break;
    }
  }

 private:
  int x, y;
};

#endif // MICROMOUSE_INCLUDE_MODEL_POSITION_H_
