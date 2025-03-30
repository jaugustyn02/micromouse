#ifndef MICROMOUSE_INCLUDE_MODEL_MOUSEDECISIONSTRATEGY_H_
#define MICROMOUSE_INCLUDE_MODEL_MOUSEDECISIONSTRATEGY_H_

#include <vector>
#include "../model/Direction.h"
#include "../model/Position.h"
#include "../model/Cell.h"

class MouseDecisionStrategy {
 public:
  virtual Direction decideMove(Position position, const std::vector<std::vector<Cell>> &map) = 0;
  virtual ~MouseDecisionStrategy() = default;
};

#endif //MICROMOUSE_INCLUDE_MODEL_MOUSEDECISIONSTRATEGY_H_
