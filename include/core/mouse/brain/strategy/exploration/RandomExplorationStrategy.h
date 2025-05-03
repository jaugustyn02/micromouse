#ifndef MICROMOUSE_INCLUDE_MODEL_RANDOMEXPLORATIONSTRATEGY_H_
#define MICROMOUSE_INCLUDE_MODEL_RANDOMEXPLORATIONSTRATEGY_H_

#include "ExplorationStrategy.h"
#include "../MouseMovementProvider.h"
#include "../../../../../utils/Randomizer.h"
#include <optional>

class RandomExplorationStrategy final : public ExplorationStrategy {
public:
 Direction decideMove(Position currentPosition, SensorReadings readings) override;

 void reset() override {
  lastMove.reset();
 }

private:
 std::optional<Direction> lastMove;

 [[nodiscard]] bool isBackwardMove(Direction direction) const;
};

#endif //MICROMOUSE_INCLUDE_MODEL_RANDOMEXPLORATIONSTRATEGY_H_
