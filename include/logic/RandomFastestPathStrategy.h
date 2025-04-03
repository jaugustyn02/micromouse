#ifndef MICROMOUSE_INCLUDE_MODEL_RANDOMFASTESTPATHSTRATEGY_H_
#define MICROMOUSE_INCLUDE_MODEL_RANDOMFASTESTPATHSTRATEGY_H_

#include "MouseDecisionStrategy.h"
#include "../model/SensorReadings.h"

class RandomFastestPathStrategy : public MouseDecisionStrategy {
 public:
  Direction decideMove(Position position, SensorReadings readings) override;
  void reset() override {};
 private:
  Direction lastMove{};
  bool isFirstMove = true;
};

#endif //MICROMOUSE_INCLUDE_MODEL_RANDOMFASTESTPATHSTRATEGY_H_
