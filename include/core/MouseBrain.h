#ifndef MICROMOUSE_INCLUDE_MODEL_MOUSEBRAIN_H_
#define MICROMOUSE_INCLUDE_MODEL_MOUSEBRAIN_H_

#include <utility>

#include "../logic/MouseDecisionStrategy.h"
#include "GlobalConfig.h"
#include "../model/MouseMode.h"
#include "MouseSensor.h"

class MouseBrain {
 public:
  MouseBrain(MouseDecisionStrategy &explorationStrategy,
             MouseDecisionStrategy &pathfindingStrategy);
  void setMode(MouseMode _mode);
  MouseMode getMode() const { return mode; }
  Direction getNextMove(Position position, SensorReadings readings);
  void reset();
 private:
  MouseDecisionStrategy &explorationStrategy;
  MouseDecisionStrategy &pathfindingStrategy;
  MouseDecisionStrategy *currentStrategy;
  MouseMode mode{EXPLORATION};
  std::map<Position, SensorReadings> mazeMap;
  Position goalTopLeftCorner{GLOBAL::SIMULATION::MAZE_WIDTH / 2 - 1,
                             GLOBAL::SIMULATION::MAZE_HEIGHT / 2 - 1};
  Position startPosition{GLOBAL::SIMULATION::START_POSITION_X,
                         GLOBAL::SIMULATION::START_POSITION_Y};
};

#endif //MICROMOUSE_INCLUDE_MODEL_MOUSEBRAIN_H_
