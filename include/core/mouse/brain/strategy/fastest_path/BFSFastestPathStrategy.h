#ifndef MICROMOUSE_DFS_FASTEST_PATH_STRATEGY_H_
#define MICROMOUSE_DFS_FASTEST_PATH_STRATEGY_H_

#include <optional>
#include <deque>

#include "FastestPathStrategy.h"

/**
 * @class BFSFastestPathStrategy
 * @brief Pathfinding strategy that uses BFS to find the fastest path to the destination.
 *
 * This strategy maintains a known map of the maze and is used after exploration to reach destinations efficiently.
 */

class BFSFastestPathStrategy final : public FastestPathStrategy {
 public:
  /// @copydoc MouseMovementProvider::decideMove
  Direction decideMove(Position currentPosition, SensorReadings readings) override;

  /// @copydoc MouseMovementProvider::reset
  void reset() override {
    path.reset();
  };

 private:
  std::optional<std::deque<Direction>> path;

  void findFastestPath(Position start);

  [[nodiscard]]
  Position getReachedDestination(const std::map<Position, int> &distance) const;

  Direction getBestMove(std::map<Position, int> &distance, Position position) const;

  [[nodiscard]]
  std::map<Position, int> getDistanceMap(Position start) const;

  static bool isVisited(std::map<Position, int> distance, Position position);

  [[nodiscard]]
  bool isWallBetween(Position source, Position destination) const;
};

#endif //MICROMOUSE_DFS_FASTEST_PATH_STRATEGY_H_
