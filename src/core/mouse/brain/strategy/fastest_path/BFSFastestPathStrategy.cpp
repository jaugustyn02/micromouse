#include "core/mouse/brain/strategy/fastest_path/BFSFastestPathStrategy.h"

#include <queue>

Direction BFSFastestPathStrategy::decideMove(const Position currentPosition, const SensorReadings readings) {
  if (!path.has_value()) {
    findFastestPath(currentPosition);
  }
  const auto nextMove = path.value().front();
  path.value().pop_front();
  return nextMove;
}

void BFSFastestPathStrategy::findFastestPath(const Position start) {
  path = std::deque<Direction>();
  std::map<Position, int> distance = getDistanceMap(start);

  auto currentPosition = getReachedDestination(distance);
  while (currentPosition != start) {
    const auto move = getBestMove(distance, currentPosition);
    path.value().push_front(opposite(move));
    currentPosition.translate(move);
  }
}

Position BFSFastestPathStrategy::getReachedDestination(const std::map<Position, int> &distance) const {
  for (const auto position : getDestination()) {
    if (isVisited(distance, position)) {
      return position;
    }
  }
  throw std::out_of_range("[FloodingExplorationStrategy]: No reached destination found");
}

Direction BFSFastestPathStrategy::getBestMove(std::map<Position, int> &distance, const Position position) const {
  const int desiredDistance = distance[position] - 1;

  for (const auto &neighbour : position.getNeighborCellPositions(mazeWidth, mazeHeight)) {
    if (!isWallBetween(position, neighbour) && distance[neighbour] == desiredDistance) {
      return position.getDirectionToNeighbourPosition(neighbour);
    }
  }
  throw std::invalid_argument("[FloodingExplorationStrategy]: Best move is not legal!");
}

std::map<Position, int> BFSFastestPathStrategy::getDistanceMap(const Position start) const {
  std::map<Position, int> distance;
  std::queue<Position> queue;

  queue.push(start);
  distance[start] = 0;
  while (!queue.empty()) {
    const auto currentPosition = queue.front();
    const auto currentDistance = distance[currentPosition];
    queue.pop();

    for (const auto neighbour : currentPosition.getNeighborCellPositions(mazeWidth, mazeHeight)) {
      if (!isVisited(distance, neighbour) && !isWallBetween(currentPosition, neighbour)) {
        distance[neighbour] = currentDistance + 1;
        queue.push(neighbour);
      }
    }
  }

  return distance;
}

bool BFSFastestPathStrategy::isVisited(std::map<Position, int> distance, const Position position) {
  return distance.find(position) != distance.end();
}

bool BFSFastestPathStrategy::isWallBetween(const Position source, const Position destination) const {
  const auto direction = source.getDirectionToNeighbourPosition(destination);

  if (const auto pair = mazeMap.find(source); pair != mazeMap.end()) {
    return pair->second.isWall(direction);
  }
  if (const auto pair = mazeMap.find(destination); pair != mazeMap.end()) {
    return pair->second.isWall(opposite(direction));
  }
  return true;
}



