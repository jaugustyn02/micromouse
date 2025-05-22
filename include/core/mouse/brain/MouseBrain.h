#ifndef MICROMOUSE_INCLUDE_MODEL_MOUSEBRAIN_H_
#define MICROMOUSE_INCLUDE_MODEL_MOUSEBRAIN_H_

#include "strategy/MouseMovementProvider.h"
#include "core/GlobalConfig.h"
#include "model/MouseMode.h"
#include "core/mouse/MouseSensor.h"
#include <utility>

#include "strategy/exploration/ExplorationStrategy.h"
#include "strategy/fastest_path/FastestPathStrategy.h"

/**
 * @class MouseBrain
 * @brief Controls the decision-making logic of the virtual micromouse.
 *
 * MouseBrain orchestrates the switching between different operational modes
 * (exploration, return, fastest path) and delegates movement decisions to the
 * appropriate strategy. It also maintains an internal map of sensor readings.
 */
class MouseBrain {
 public:
  /**
   * @brief Constructs the MouseBrain with given exploration and pathfinding strategies.
   * @param explorationStrategy Pointer to the exploration strategy implementation.
   * @param fastestPathStrategy Pointer to the fastest path strategy implementation.
   */
  MouseBrain(std::unique_ptr<ExplorationStrategy> explorationStrategy,
             std::unique_ptr<FastestPathStrategy> fastestPathStrategy);

  /**
   * @brief Switches to the next operation mode (exploration -> return -> fastest path -> ...).
   */
  void nextMode();

  /**
   * @brief Gets the current operating mode of the mouse.
   * @return Current MouseMode (e.g., EXPLORATION, FASTEST_PATH).
   */
  [[nodiscard]]
  MouseMode getMode() const { return activeMode; }

  /**
   * @brief Determines the next movement direction based on the current position and sensor data.
   * @param currentPosition The current position of the mouse.
   * @param readings Sensor data at the current position.
   * @return The direction in which the mouse should move next.
   */
  Direction getNextMove(Position currentPosition, const SensorReadings &readings);

  /**
   * @brief Checks whether the given position matches any destination goals.
   * @param position The position to check.
   * @return True if the destination is reached, false otherwise.
   */
  [[nodiscard]]
  bool isDestinationReached(Position position) const;

  /**
   * @brief Resets the brain state, clearing the map and resetting the current mode.
   */
  void reset();

 private:
  std::unique_ptr<ExplorationStrategy> explorationStrategy;
  std::unique_ptr<FastestPathStrategy> fastestPathStrategy;
  MouseMovementProvider *currentStrategy = nullptr;

  MouseMode activeMode{EXPLORATION};

  std::map<Position, SensorReadings> mazeMap;

  void validateMove(Position position, Direction move) const;

  [[nodiscard]]
  bool isMoveLegal(Position position, Direction move) const;

  [[nodiscard]]
  MouseMode getNextMode() const;

  void setMode(MouseMode mode);
};

#endif //MICROMOUSE_INCLUDE_MODEL_MOUSEBRAIN_H_
