#include "model/Position.h"

void Position::translate(const Direction direction) {
  switch (direction) {
    case NORTH: --y;
      break;
    case SOUTH: ++y;
      break;
    case EAST: ++x;
      break;
    case WEST: --x;
      break;
    default:throw std::invalid_argument("Invalid direction");
  }
}

Position Position::translated(const Direction direction) const {
  switch (direction) {
    case NORTH:return {x, y - 1};
    case SOUTH:return {x, y + 1};
    case EAST:return {x + 1, y};
    case WEST:return {x - 1, y};
    default:throw std::invalid_argument("Invalid direction");
  }
}

std::vector<Position> Position::getNeighborCellPositions(
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

Direction Position::getDirectionToNeighbourPosition(const Position destination) const {
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