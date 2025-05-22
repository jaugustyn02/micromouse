#ifndef MICROMOUSE_INCLUDE_MODEL_RANDOM_FASTEST_PATH_STRATEGY_H_
#define MICROMOUSE_INCLUDE_MODEL_RANDOM_FASTEST_PATH_STRATEGY_H_

#include <optional>

#include "FastestPathStrategy.h"
#include "core/mouse/brain/strategy/MouseMovementProvider.h"
#include "model/SensorReadings.h"

/**
 * @class RandomFastestPathStrategy
 * @brief Naive pathfinding strategy that chooses random legal moves.
 *
 * Uses basic randomness, optionally avoiding backward movement.
 */

class RandomFastestPathStrategy final : public FastestPathStrategy {
 public:
  /// @copydoc MouseMovementProvider::decideMove
  Direction decideMove(Position position, SensorReadings readings) override;

  /// @copydoc MouseMovementProvider::reset
  void reset() override {
    lastMove.reset();
  }

 private:
  std::optional<Direction> lastMove;

  [[nodiscard]]
  bool isBackwardMove(Direction direction) const;
};

#endif //MICROMOUSE_INCLUDE_MODEL_RANDOM_FASTEST_PATH_STRATEGY_H_
