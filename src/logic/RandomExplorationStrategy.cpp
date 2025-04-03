#include "../../include/logic/RandomExplorationStrategy.h"
#include "../../include/core/GlobalConfig.h"

Direction RandomExplorationStrategy::decideMove(Position _position, SensorReadings readings) {
  std::vector<Direction> possibleMoves;
  auto backwardMove = opposite(lastMove);
  for (auto direction : GLOBAL::CONSTANTS::DIRECTIONS) {
    if (!readings.isWall(direction) && (isFirstMove || direction != backwardMove)) {
      possibleMoves.push_back(direction);
    }
  }

  if (possibleMoves.empty()) {
    if (isFirstMove) {
      throw std::runtime_error("[RandomExplorationStrategy]: No possible moves");
    }
    lastMove = opposite(lastMove);
    return lastMove;
  }

  isFirstMove = false;
  lastMove = Randomizer::GetRandomElement(possibleMoves);
  return lastMove;
}