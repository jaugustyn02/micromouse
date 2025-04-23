#ifndef MICROMOUSE_INCLUDE_MODEL_POSITION_H_
#define MICROMOUSE_INCLUDE_MODEL_POSITION_H_

#include <iostream>
#include "Direction.h"
#include <vector>

class Position {
public:
  Position(const int x, const int y) : x(x), y(y) {
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

  std::vector<Position> Position::getNeighborCellPositions(const int gridWidth, const int gridHeight) const {
    std::vector<Position> neighbors;

    if (x > 0) {
      neighbors.emplace_back(x - 1, y);
    }
    if (y > 0) {
      neighbors.emplace_back(x, y - 1);
    }
    if (x < gridWidth - 1) {
      neighbors.emplace_back(x + 1, y);
    }
    if (y < gridHeight - 1) {
      neighbors.emplace_back(x, y + 1);
    }

    return neighbors;
  }

  bool isOutOfBounds(const int gridWidth, const int gridHeight) const {
    return x < 0 || x >= gridWidth || y < 0 || y >= gridHeight;
  }

  std::string toString() const {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
  }

private:
  int x, y;
};

#endif // MICROMOUSE_INCLUDE_MODEL_POSITION_H_
