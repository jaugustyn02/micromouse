#ifndef MICROMOUSE_INCLUDE_MODEL_POSITION_H_
#define MICROMOUSE_INCLUDE_MODEL_POSITION_H_

#include <iostream>
#include "Direction.h"
#include <vector>

class Position {
 public:
  Position(const int x, const int y) : x(x), y(y) {
  }

  Position(const Position &position) = default;

  void translate(Direction direction);

  [[nodiscard]] Position translated(Direction direction) const;

  [[nodiscard]] std::vector<Position> getNeighborCellPositions(int gridWidth, int gridHeight) const;

  [[nodiscard]] Direction getDirectionToNeighbourPosition(Position destination) const;

  bool operator<(const Position &other) const {
    return (x == other.x) ? (y < other.y) : (x < other.x);
  }

  bool operator==(const Position &other) const {
    return x == other.x && y == other.y;
  }

  bool operator!=(const Position &start) const {
    return !(*this == start);
  }

  [[nodiscard]] int getX() const { return x; }

  [[nodiscard]] int getY() const { return y; }

  [[nodiscard]] bool isOutOfBounds(const int gridWidth, const int gridHeight) const {
    return x < 0 || x >= gridWidth || y < 0 || y >= gridHeight;
  }

  [[nodiscard]] std::string toString() const {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
  }

 private:
  int x, y;
};

#endif // MICROMOUSE_INCLUDE_MODEL_POSITION_H_
