#ifndef MICROMOUSE_FLOODINGEXPLORATIONSTRATEGY_H_
#define MICROMOUSE_FLOODINGEXPLORATIONSTRATEGY_H_

#include "model/Position.h"
#include "model/Direction.h"
#include "ExplorationStrategy.h"

/**
 * @class FloodingExplorationStrategy
 * @brief Maze exploration using a flooding/distance propagation algorithm.
 *
 * Keeps track of sensor readings and distances from the current position to goal cells.
 * Chooses the best move based on a dynamically updated distance map.
 */
class FloodingExplorationStrategy final : public ExplorationStrategy {
 public:
  /**
   * @brief Constructor for FloodingExplorationStrategy.
   *
   * Initializes the maze map and distance map.
   */
  FloodingExplorationStrategy();

  /// @copydoc MouseMovementProvider::decideMove
  Direction decideMove(Position position, SensorReadings readings) override;

  /// @copydoc MouseMovementProvider::reset
  void reset() override {
    mazeMap.clear();
    clearDistance();
  }

 private:
  const int empty = -1;
  std::map<Position, SensorReadings> mazeMap;
  std::vector<std::vector<int> > cellDistance = std::vector(mazeHeight, std::vector(mazeWidth, empty));

  void updateMazeMap(Position position, const SensorReadings &readings);

  void calculateDistances();

  Direction getBestMove(Position position) const;

  bool isBestMoveLegal(Position position) const;

  bool isVisited(Position position) const;

  bool isWallBetween(Position source, Position destination) const;

  int getDistance(Position position) const;

  void setDistance(Position position, int distance);

  void clearDistance();
};

#endif //MICROMOUSE_FLOODINGEXPLORATIONSTRATEGY_H_
