#ifndef MICROMOUSE_INCLUDE_LOGIC_DIJKSTRAFASTESTPATHSTRATEGY_H_
#define MICROMOUSE_INCLUDE_LOGIC_DIJKSTRAFASTESTPATHSTRATEGY_H_

#include "../MouseDecisionStrategy.h"

class DijkstraFastestPathStrategy : public MouseDecisionStrategy {
 public:
  Direction decideMove(Position position, SensorReadings readings) override {
    return Direction::NORTH;
  };
  void reset() override {};
};

#endif //MICROMOUSE_INCLUDE_LOGIC_DIJKSTRAFASTESTPATHSTRATEGY_H_
