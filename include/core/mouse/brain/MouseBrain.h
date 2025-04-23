#ifndef MICROMOUSE_INCLUDE_MODEL_MOUSEBRAIN_H_
#define MICROMOUSE_INCLUDE_MODEL_MOUSEBRAIN_H_

#include "strategy/MouseDecisionStrategy.h"
#include "../../GlobalConfig.h"
#include "../../../model/MouseMode.h"
#include "../MouseSensor.h"
#include <utility>

class MouseBrain {
 public:
  MouseBrain(std::unique_ptr<MouseDecisionStrategy> explorationStrategy,
             std::unique_ptr<MouseDecisionStrategy> pathfindingStrategy);
  void setMode(MouseMode mode);
  MouseMode getMode() const { return activeMode; }
  Direction getNextMove(Position position, SensorReadings readings);

  void validateMove(Position position, Direction move);

  bool isMoveLegal(Position position, Direction move);

  void reset() const;
 private:
  std::unique_ptr<MouseDecisionStrategy> explorationStrategy;
  std::unique_ptr<MouseDecisionStrategy> pathfindingStrategy;
  MouseDecisionStrategy *currentStrategy;
  MouseMode activeMode{EXPLORATION};
  std::map<Position, SensorReadings> mazeMap;
  Position goalTopLeftCorner{GLOBAL::SIMULATION::MAZE_WIDTH / 2 - 1,
                             GLOBAL::SIMULATION::MAZE_HEIGHT / 2 - 1};
  Position startPosition{GLOBAL::SIMULATION::START_POSITION_X,
                         GLOBAL::SIMULATION::START_POSITION_Y};
};

#endif //MICROMOUSE_INCLUDE_MODEL_MOUSEBRAIN_H_
