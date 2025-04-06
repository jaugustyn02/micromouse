#ifndef MICROMOUSE_INCLUDE_MODEL_MOUSEBRAIN_H_
#define MICROMOUSE_INCLUDE_MODEL_MOUSEBRAIN_H_

#include <utility>

#include "../logic/MouseDecisionStrategy.h"
#include "GlobalConfig.h"
#include "../model/MouseMode.h"
#include "MouseSensor.h"

class MouseBrain {
 public:
  MouseBrain(MouseDecisionStrategy &explorationStrategy, MouseDecisionStrategy &pathfindingStrategy);
  void setMode(MouseMode _mode);
  Direction getNextMove(Position position, SensorReadings readings);
  void reset();

 private:
  MouseDecisionStrategy &explorationStrategy;
  MouseDecisionStrategy &pathfindingStrategy;
  MouseDecisionStrategy *currentStrategy;
  MouseMode mode;
};

#endif //MICROMOUSE_INCLUDE_MODEL_MOUSEBRAIN_H_
