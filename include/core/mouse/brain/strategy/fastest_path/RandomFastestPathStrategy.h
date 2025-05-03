#ifndef MICROMOUSE_INCLUDE_MODEL_RANDOM_FASTEST_PATH_STRATEGY_H_
#define MICROMOUSE_INCLUDE_MODEL_RANDOM_FASTEST_PATH_STRATEGY_H_

#include <optional>

#include "FastestPathStrategy.h"
#include "../MouseMovementProvider.h"
#include "../../../../../model/SensorReadings.h"

class RandomFastestPathStrategy final : public FastestPathStrategy {
public:
 Direction decideMove(Position position, SensorReadings readings) override;

 void reset() override {
  lastMove.reset();
 }

private:
 std::optional<Direction> lastMove;

 [[nodiscard]] bool isBackwardMove(Direction direction) const;
};

#endif //MICROMOUSE_INCLUDE_MODEL_RANDOM_FASTEST_PATH_STRATEGY_H_
