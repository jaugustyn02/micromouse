#ifndef MICROMOUSE_INCLUDE_LOGIC_BFSEXPLORATIONSTRATEGY_H_
#define MICROMOUSE_INCLUDE_LOGIC_BFSEXPLORATIONSTRATEGY_H_

#include <vector>
#include <set>
#include <queue>
#include "../../../../../model/Position.h"
#include "../../../../../model/Direction.h"
#include "../MouseDecisionStrategy.h"

class FloodingExplorationStrategy : public MouseDecisionStrategy {
 public:
  FloodingExplorationStrategy()
      : mazeMap(), visited(), queue() {}
  Direction decideMove(Position position, SensorReadings readings) override;
  void reset() override {};
 private:
  std::map<Position, SensorReadings> mazeMap;
  std::set<Position> visited;
  std::queue<Position> queue;
};

#endif //MICROMOUSE_INCLUDE_LOGIC_BFSEXPLORATIONSTRATEGY_H_
