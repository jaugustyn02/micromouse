#include "../../../../include/core/mouse/brain/MouseBrain.h"

MouseBrain::MouseBrain(std::unique_ptr<MouseDecisionStrategy> explorationStrategy,
                       std::unique_ptr<MouseDecisionStrategy> pathfindingStrategy) :
    explorationStrategy(std::move(explorationStrategy)),
    pathfindingStrategy(std::move(pathfindingStrategy)),
    currentStrategy(this->explorationStrategy.get()) {
  auto goalReadings = SensorReadings(CellType::GOAL);
  mazeMap.insert({goalTopLeftCorner, goalReadings});
  mazeMap.insert({{goalTopLeftCorner.getX(), goalTopLeftCorner.getY() + 1}, goalReadings});
  mazeMap.insert({{goalTopLeftCorner.getX() + 1, goalTopLeftCorner.getY()}, goalReadings});
  mazeMap.insert({{goalTopLeftCorner.getX() + 1, goalTopLeftCorner.getY() + 1}, goalReadings});
}

void MouseBrain::setMode(MouseMode _mode) {
  this->mode = _mode;
  currentStrategy = (_mode == EXPLORATION) ? explorationStrategy.get() : pathfindingStrategy.get();
  currentStrategy->reset();
}

Direction MouseBrain::getNextMove(Position position, SensorReadings readings) {
  mazeMap.insert({position, readings});
  return currentStrategy->decideMove(position, std::move(readings));
}

void MouseBrain::reset() {
  currentStrategy->reset();
}