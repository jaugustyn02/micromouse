#ifndef MICROMOUSE_INCLUDE_MODEL_MOUSEBRAIN_H_
#define MICROMOUSE_INCLUDE_MODEL_MOUSEBRAIN_H_

#include <utility>

#include "MouseDecisionStrategy.h"
#include "../core/GlobalConfig.h"
#include "../model/MouseMode.h"
#include "MouseSensor.h"

class MouseBrain {
 public:
  MouseBrain(MouseDecisionStrategy &explorationStrategy, MouseDecisionStrategy &pathfindingStrategy)
      : explorationStrategy(explorationStrategy),
        pathfindingStrategy(pathfindingStrategy),
        currentStrategy(&explorationStrategy),
        mode(EXPLORATION) {
  }

  void setMode(MouseMode _mode) {
    this->mode = _mode;
    currentStrategy = (mode == EXPLORATION) ? &explorationStrategy : &pathfindingStrategy;
    currentStrategy->reset();
  }

  Direction getNextMove(Position position, SensorReadings readings) {
    return currentStrategy->decideMove(position, std::move(readings));
  }

 private:
  MouseDecisionStrategy &explorationStrategy;
  MouseDecisionStrategy &pathfindingStrategy;
  MouseDecisionStrategy *currentStrategy;
  MouseMode mode;
};

#endif //MICROMOUSE_INCLUDE_MODEL_MOUSEBRAIN_H_
