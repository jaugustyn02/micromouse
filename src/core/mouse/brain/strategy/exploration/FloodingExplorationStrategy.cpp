#include "../../../../../../include/core/mouse/brain/strategy/exploration/FloodingExplorationStrategy.h"
#include <queue>

FloodingExplorationStrategy::FloodingExplorationStrategy() {
  calculateDistances();
}

Direction FloodingExplorationStrategy::decideMove(const Position position, const SensorReadings readings) {
  updateMazeMap(position, readings);
  if (!isBestMoveLegal(position)) {
    calculateDistances();
  }
  return getBestMove(position);
}

void FloodingExplorationStrategy::updateMazeMap(const Position position, const SensorReadings &readings) {
  mazeMap.emplace(position, readings);
}

bool FloodingExplorationStrategy::isBestMoveLegal(const Position position) const {
  const int desiredDistance = getDistance(position) - 1;

  for (const auto neighbourCell: position.getNeighborCellPositions(mazeWidth, mazeHeight)) {
    if (!isWallBetween(position, neighbourCell) && getDistance(neighbourCell) == desiredDistance) {
      return true;
    }
  }
  return false;
}

Direction FloodingExplorationStrategy::getBestMove(const Position position) const {
  const int desiredDistance = getDistance(position) - 1;

  for (const auto &neighbourCell: position.getNeighborCellPositions(mazeWidth, mazeHeight)) {
    if (!isWallBetween(position, neighbourCell) && getDistance(neighbourCell) == desiredDistance) {
      return getDirectionToNeighbourCell(position, neighbourCell);
    }
  }
  throw std::invalid_argument("[FloodingExplorationStrategy]: Best move is not legal!");
}

void FloodingExplorationStrategy::calculateDistances() {
  clearDistance();

  std::queue<Position> queue;

  for (auto position: destination) {
    setDistance(position, 0);
    queue.emplace(position);
  }

  while (!queue.empty()) {
    const auto currentPosition = queue.front();
    const auto currentDistance = getDistance(currentPosition);
    queue.pop();

    for (const auto neighbourCell: currentPosition.getNeighborCellPositions(mazeWidth, mazeHeight)) {
      if (!isVisited(neighbourCell) && !isWallBetween(currentPosition, neighbourCell)) {
        setDistance(neighbourCell, currentDistance + 1);
        queue.emplace(neighbourCell);
      }
    }
  }
}

bool FloodingExplorationStrategy::isVisited(const Position position) const {
  return getDistance(position) != empty;
}

bool FloodingExplorationStrategy::isWallBetween(const Position source, const Position destination) const {
  const auto direction = getDirectionToNeighbourCell(source, destination);

  if (const auto pair = mazeMap.find(source); pair != mazeMap.end()) {
    return pair->second.isWall(direction);
  }
  if (const auto pair = mazeMap.find(destination); pair != mazeMap.end()) {
    return pair->second.isWall(opposite(direction));
  }
  return false;
}

Direction FloodingExplorationStrategy::getDirectionToNeighbourCell(
  const Position source,
  const Position destination) {
  const int xDiff = destination.getX() - source.getX();
  const int yDiff = destination.getY() - source.getY();

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
  throw std::invalid_argument("[FloodingExplorationStrategy]: Given positions are not neighbour!");
}

int FloodingExplorationStrategy::getDistance(const Position position) const {
  return cellDistance[position.getY()][position.getX()];
}

void FloodingExplorationStrategy::setDistance(const Position position, const int distance) {
  cellDistance[position.getY()][position.getX()] = distance;
}

void FloodingExplorationStrategy::clearDistance() {
  for (auto &row: cellDistance) {
    for (auto &x: row) {
      x = empty;
    }
  }
}
