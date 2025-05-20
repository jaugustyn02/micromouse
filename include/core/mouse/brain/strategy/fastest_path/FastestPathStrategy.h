#ifndef FASTESTPATHSTRATEGY_H
#define FASTESTPATHSTRATEGY_H

#include "core/mouse/brain/strategy/MouseMovementProvider.h"

class FastestPathStrategy : public MouseMovementProvider {
 public:
  void setMazeMap(const std::map<Position, SensorReadings> &map) {
    mazeMap = map;
  }

 protected:
  std::map<Position, SensorReadings> mazeMap;
};

#endif //FASTESTPATHSTRATEGY_H
