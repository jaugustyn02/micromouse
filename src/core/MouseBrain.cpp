#include "../../include/core/MouseBrain.h"

MouseBrain::MouseBrain(MouseDecisionStrategy &explorationStrategy,
                       MouseDecisionStrategy &pathfindingStrategy)
    : explorationStrategy(explorationStrategy),
      pathfindingStrategy(pathfindingStrategy),
      currentStrategy(&explorationStrategy) {
  auto goalReadings = SensorReadings(CellType::GOAL);
  mazeMap.insert({goalTopLeftCorner, goalReadings});
  mazeMap.insert({{goalTopLeftCorner.getX(), goalTopLeftCorner.getY() + 1}, goalReadings});
  mazeMap.insert({{goalTopLeftCorner.getX() + 1, goalTopLeftCorner.getY()}, goalReadings});
  mazeMap.insert({{goalTopLeftCorner.getX() + 1, goalTopLeftCorner.getY() + 1}, goalReadings});
}

void MouseBrain::setMode(MouseMode _mode) {
  this->mode = _mode;
  currentStrategy = (mode == EXPLORATION) ? &explorationStrategy : &pathfindingStrategy;
  currentStrategy->reset();
}

Direction MouseBrain::getNextMove(Position position, SensorReadings readings) {
  mazeMap.insert({position, readings});
  return currentStrategy->decideMove(position, std::move(readings));
}

void MouseBrain::reset() {
  currentStrategy->reset();
}