
#include "../../include/logic/MouseBrain.h"

MouseBrain::MouseBrain(MouseDecisionStrategy &explorationStrategy, MouseDecisionStrategy &pathfindingStrategy)
    : explorationStrategy(explorationStrategy),
      pathfindingStrategy(pathfindingStrategy),
      currentStrategy(&explorationStrategy),
      mode(EXPLORATION) {
}

void MouseBrain::setMode(MouseMode _mode) {
  this->mode = _mode;
  currentStrategy = (mode == EXPLORATION) ? &explorationStrategy : &pathfindingStrategy;
  currentStrategy->reset();
}

Direction MouseBrain::getNextMove(Position position, SensorReadings readings) {
  return currentStrategy->decideMove(position, std::move(readings));
}

void MouseBrain::reset() {
  currentStrategy->reset();
}