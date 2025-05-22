#ifndef MICROMOUSE_INCLUDE_MODEL_RANDOMEXPLORATIONSTRATEGY_H_
#define MICROMOUSE_INCLUDE_MODEL_RANDOMEXPLORATIONSTRATEGY_H_

#include "ExplorationStrategy.h"
#include "core/mouse/brain/strategy/MouseMovementProvider.h"
#include "utils/Randomizer.h"
#include <optional>

/**
 * @class RandomExplorationStrategy
 * @brief Naive exploration strategy that chooses random legal moves.
 *
 * Uses basic randomness, optionally avoiding backward movement.
 */
class RandomExplorationStrategy final : public ExplorationStrategy {
 public:

  /// @copydoc MouseMovementProvider::decideMove
  Direction decideMove(Position currentPosition, SensorReadings readings) override;

  /// @copydoc MouseMovementProvider::reset
  void reset() override {
    lastMove.reset();
  }

 private:
  std::optional<Direction> lastMove;

  [[nodiscard]]
  bool isBackwardMove(Direction direction) const;
};

#endif //MICROMOUSE_INCLUDE_MODEL_RANDOMEXPLORATIONSTRATEGY_H_
