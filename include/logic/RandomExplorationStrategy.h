#ifndef MICROMOUSE_INCLUDE_MODEL_RANDOMEXPLORATIONSTRATEGY_H_
#define MICROMOUSE_INCLUDE_MODEL_RANDOMEXPLORATIONSTRATEGY_H_

#include "MouseDecisionStrategy.h"
#include "../utils/Randomizer.h"

class RandomExplorationStrategy : public MouseDecisionStrategy {
 public:
  Direction decideMove(Position position, const std::vector<std::vector<Cell>> &map) override;
};
Direction RandomExplorationStrategy::decideMove(Position position, const std::vector<std::vector<Cell>> &map) {
  return Direction::NORTH;
}

#endif //MICROMOUSE_INCLUDE_MODEL_RANDOMEXPLORATIONSTRATEGY_H_
