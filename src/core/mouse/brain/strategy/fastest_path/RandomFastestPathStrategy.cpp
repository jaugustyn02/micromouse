#include "../../../../../../include/core/mouse/brain/strategy/fastest_path/RandomFastestPathStrategy.h"
#include "../../../../../../include/utils/Randomizer.h"
#include "../../../../../../include/core/GlobalConfig.h"

Direction RandomFastestPathStrategy::decideMove(const Position currentPosition, const SensorReadings readings) {
  std::vector<Direction> possibleMoves;
  for (auto direction: GLOBAL::CONSTANTS::DIRECTIONS) {
    if (!readings.isWall(direction) && !isBackwardMove(direction)) {
      possibleMoves.push_back(direction);
    }
  }

  if (possibleMoves.empty()) {
    if (!lastMove.has_value()) {
      throw std::runtime_error("[RandomExplorationStrategy]: No possible moves");
    }
    possibleMoves.push_back(opposite(lastMove.value()));
  }

  lastMove = Randomizer::GetRandomElement(possibleMoves);
  return lastMove.value();
}

bool RandomFastestPathStrategy::isBackwardMove(const Direction direction) const {
  return lastMove.has_value() && direction == opposite(lastMove.value());
}
