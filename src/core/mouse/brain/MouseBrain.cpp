#include "../../../../include/core/mouse/brain/MouseBrain.h"

MouseBrain::MouseBrain(
  std::unique_ptr<MouseDecisionStrategy> explorationStrategy,
  std::unique_ptr<MouseDecisionStrategy> pathfindingStrategy
) : explorationStrategy(std::move(explorationStrategy)),
    pathfindingStrategy(std::move(pathfindingStrategy)),
    currentStrategy(this->explorationStrategy.get()) {
  auto goalReadings = SensorReadings(CellType::GOAL);
  mazeMap.insert({goalTopLeftCorner, goalReadings});
  mazeMap.insert({{goalTopLeftCorner.getX(), goalTopLeftCorner.getY() + 1}, goalReadings});
  mazeMap.insert({{goalTopLeftCorner.getX() + 1, goalTopLeftCorner.getY()}, goalReadings});
  mazeMap.insert({{goalTopLeftCorner.getX() + 1, goalTopLeftCorner.getY() + 1}, goalReadings});
}

void MouseBrain::setMode(const MouseMode mode) {
  this->activeMode = mode;
  currentStrategy = (mode == EXPLORATION) ? explorationStrategy.get() : pathfindingStrategy.get();
  currentStrategy->reset();
}

Direction MouseBrain::getNextMove(Position position, SensorReadings readings) {
  mazeMap.insert({position, readings});
  const auto move = currentStrategy->decideMove(position, std::move(readings));
  validateMove(position, move);
  return move;
}

void MouseBrain::validateMove(const Position position, const Direction move) {
  if (position.translated(move).isOutOfBounds(GLOBAL::SIMULATION::MAZE_WIDTH, GLOBAL::SIMULATION::MAZE_HEIGHT)) {
    throw std::runtime_error("Invalid move: out of bounds");
  }
  if (!isMoveLegal(position, move)) {
    throw std::runtime_error("Invalid move: move is not legal");
  }
}

bool MouseBrain::isMoveLegal(const Position position, const Direction move) {
  return !mazeMap[position].isWall(move);
}

void MouseBrain::reset() const {
  currentStrategy->reset();
}
