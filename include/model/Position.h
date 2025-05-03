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

  [[nodiscard]] int getX() const { return x; }
  [[nodiscard]] int getY() const { return y; }

  bool operator<(const Position &other) const {
    return (x == other.x) ? (y < other.y) : (x < other.x);
  }

  bool operator==(const Position &other) const {
    return x == other.x && y == other.y;
  }

  bool operator!=(const Position &start) const {
    return !(*this == start);
  }

  void translate(const Direction direction) {
    switch (direction) {
      case NORTH: --y;
        break;
      case SOUTH: ++y;
        break;
      case EAST: ++x;
        break;
      case WEST: --x;
        break;
      default:
        throw std::invalid_argument("Invalid direction");
    }
  }

  [[nodiscard]] Position translated(const Direction direction) const {
    switch (direction) {
      case NORTH:
        return {x, y - 1};
      case SOUTH:
        return {x, y + 1};
      case EAST:
        return {x + 1, y};
      case WEST:
        return {x - 1, y};
      default:
        throw std::invalid_argument("Invalid direction");
    }
  }

  [[nodiscard]] std::vector<Position> Position::getNeighborCellPositions(
    const int gridWidth, const int gridHeight) const {
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

  [[nodiscard]] Direction getDirectionToNeighbourPosition(const Position destination) const {
    const int xDiff = destination.getX() - x;
    const int yDiff = destination.getY() - y;

    if (xDiff == 1 && yDiff == 0) {
      return EAST;
    }
    if (xDiff == -1 && yDiff == 0) {
      return WEST;
    }
    if (xDiff == 0 && yDiff == 1) {
      return SOUTH;
    }
    if (xDiff == 0 && yDiff == -1) {
      return NORTH;
    }
    throw std::invalid_argument("[Position]: Positions are not neighbour!");
  }

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
