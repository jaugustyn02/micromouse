#ifndef FASTESTPATHSTRATEGY_H
#define FASTESTPATHSTRATEGY_H

#include "core/mouse/brain/strategy/MouseMovementProvider.h"

/**
 * @class FastestPathStrategy
 * @brief Abstract base class for pathfinding algorithms to reach destination by the fastest route.
 *
 * Maintains a known map of the maze and is used after exploration to reach destinations efficiently.
 */
class FastestPathStrategy : public MouseMovementProvider {
 public:
  /**
   * @brief Sets the maze map.
   * This method allows the strategy to use a predefined map of the maze for pathfinding.
   * @param map A map where keys are positions in the maze and values are sensor readings at those positions.
   */
  void setMazeMap(const std::map<Position, SensorReadings> &map) {
    mazeMap = map;
  }

 protected:
  std::map<Position, SensorReadings> mazeMap;
};

#endif //FASTESTPATHSTRATEGY_H
