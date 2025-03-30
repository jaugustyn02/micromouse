#ifndef MICROMOUSE_INCLUDE_MODEL_RANDOMFASTESTPATHSTRATEGY_H_
#define MICROMOUSE_INCLUDE_MODEL_RANDOMFASTESTPATHSTRATEGY_H_

#include "MouseDecisionStrategy.h"
class FastestPathStrategy : public MouseDecisionStrategy {
 public:
  Direction decideMove(Position position, const std::vector<std::vector<Cell>> &map) override;
};
Direction FastestPathStrategy::decideMove(Position position, const std::vector<std::vector<Cell>> &map) {
  return Direction::NORTH;
}

#endif //MICROMOUSE_INCLUDE_MODEL_RANDOMFASTESTPATHSTRATEGY_H_
