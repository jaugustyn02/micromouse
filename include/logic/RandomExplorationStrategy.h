#ifndef MICROMOUSE_INCLUDE_MODEL_RANDOMEXPLORATIONSTRATEGY_H_
#define MICROMOUSE_INCLUDE_MODEL_RANDOMEXPLORATIONSTRATEGY_H_

#include "MouseDecisionStrategy.h"
#include "../utils/Randomizer.h"

class RandomExplorationStrategy : public MouseDecisionStrategy {
 public:
  Direction decideMove(Position position, SensorReadings readings) override;
  void reset() override {};
 private:
  Direction lastMove{};
  bool isFirstMove = true;
};

#endif //MICROMOUSE_INCLUDE_MODEL_RANDOMEXPLORATIONSTRATEGY_H_
