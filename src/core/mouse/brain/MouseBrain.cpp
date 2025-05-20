#include "core/mouse/brain/MouseBrain.h"

MouseBrain::MouseBrain(
    std::unique_ptr<ExplorationStrategy> explorationStrategy,
    std::unique_ptr<FastestPathStrategy> pathfindingStrategy
) : explorationStrategy(std::move(explorationStrategy)),
    pathfindingStrategy(std::move(pathfindingStrategy)) {
  setMode(EXPLORATION);
}

void MouseBrain::setMode(const MouseMode mode) {
  this->activeMode = mode;
  switch (mode) {
    case EXPLORATION:currentStrategy = explorationStrategy.get();
      currentStrategy->setDestination(GLOBAL::CONSTANTS::GOAL_POSITIONS);
      break;
    case EXPLORATION_ON_RETURN:currentStrategy = explorationStrategy.get();
      currentStrategy->setDestination({GLOBAL::MAZE::START_POSITION});
      break;
    case FASTEST_PATH: {
      currentStrategy = pathfindingStrategy.get();
      currentStrategy->setDestination(GLOBAL::CONSTANTS::GOAL_POSITIONS);
      pathfindingStrategy->setMazeMap(mazeMap);
      break;
    }
    case RETURN: {
      currentStrategy = pathfindingStrategy.get();
      currentStrategy->setDestination({GLOBAL::MAZE::START_POSITION});
      pathfindingStrategy->setMazeMap(mazeMap);
      break;
    }
  }
  currentStrategy->reset();
}

void MouseBrain::nextMode() {
  setMode(getNextMode());
}

MouseMode MouseBrain::getNextMode() const {
  switch (this->activeMode) {
    case EXPLORATION: return EXPLORATION_ON_RETURN;
    case EXPLORATION_ON_RETURN: return FASTEST_PATH;
    case FASTEST_PATH: return RETURN;
    case RETURN: return FASTEST_PATH;
  }
}

Direction MouseBrain::getNextMove(const Position currentPosition, const SensorReadings &readings) {
  mazeMap.insert({currentPosition, readings});
  const auto move = currentStrategy->decideMove(currentPosition, readings);
  validateMove(currentPosition, move);
  return move;
}

void MouseBrain::validateMove(const Position position, const Direction move) const {
  if (position.translated(move).isOutOfBounds(GLOBAL::MAZE::COLUMNS, GLOBAL::MAZE::ROWS)) {
    throw std::runtime_error("[MouseBrain]: Invalid move: out of bounds");
  }
  if (!isMoveLegal(position, move)) {
    throw std::runtime_error("[MouseBrain]: Invalid move: move is not legal");
  }
}

bool MouseBrain::isMoveLegal(const Position position, const Direction move) const {
  return !mazeMap.at(position).isWall(move);
}

void MouseBrain::reset() {
  mazeMap.clear();
  setMode(EXPLORATION);
}

bool MouseBrain::isDestinationReached(const Position position) const {
  const auto destination = currentStrategy->getDestination();
  return destination.find(position) != destination.end();
}
