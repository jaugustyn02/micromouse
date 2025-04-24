#include "../../../../include/core/mouse/brain/MouseBrain.h"

MouseBrain::MouseBrain(
  std::unique_ptr<MouseDecisionStrategy> explorationStrategy,
  std::unique_ptr<MouseDecisionStrategy> pathfindingStrategy
) : explorationStrategy(std::move(explorationStrategy)),
    pathfindingStrategy(std::move(pathfindingStrategy)),
    currentStrategy(this->explorationStrategy.get()) {
}

void MouseBrain::setMode(const MouseMode mode) {
  this->activeMode = mode;
  currentStrategy = (mode == EXPLORATION) ? explorationStrategy.get() : pathfindingStrategy.get();
  currentStrategy->reset();
}

Direction MouseBrain::getNextMove(const Position position, const SensorReadings &readings) {
  mazeMap.insert({position, readings});
  const auto move = currentStrategy->decideMove(position, readings);
  validateMove(position, move);
  return move;
}

void MouseBrain::validateMove(const Position position, const Direction move) const {
  if (position.translated(move).isOutOfBounds(GLOBAL::SIMULATION::MAZE_WIDTH, GLOBAL::SIMULATION::MAZE_HEIGHT)) {
    throw std::runtime_error("Invalid move: out of bounds");
  }
  if (!isMoveLegal(position, move)) {
    throw std::runtime_error("Invalid move: move is not legal");
  }
}

bool MouseBrain::isMoveLegal(const Position position, const Direction move) const {
  return !mazeMap.at(position).isWall(move);
}

void MouseBrain::reset() {
  mazeMap.clear();
  currentStrategy->reset();
}
