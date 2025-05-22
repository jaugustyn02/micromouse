#ifndef MICROMOUSE_INCLUDE_MODEL_MOUSE_MOVEMENT_PROVIDER_H_
#define MICROMOUSE_INCLUDE_MODEL_MOUSE_MOVEMENT_PROVIDER_H_

#include "core/GlobalConfig.h"
#include "model/Direction.h"
#include "model/Position.h"
#include "model/SensorReadings.h"
#include <utility>
#include <vector>

class MouseMovementProvider {
 public:
  /**
   * @brief Default destructor for MouseMovementProvider.
   */
  virtual ~MouseMovementProvider() = default;

  /**
   * @brief Decides the next move based on the current position and sensor readings.
   *
   * @param position The current position of the mouse.
   * @param readings The sensor readings from the mouse.
   * @return The direction to move in.
   */
  virtual Direction decideMove(Position position, SensorReadings readings) = 0;

  /**
   * @brief Resets the state of the movement provider.
   *
   * This function can be overridden by derived classes to implement specific reset logic.
   */
  virtual void reset() {
  };

  /**
   * @brief Sets the destination positions for the mouse.
   *
   * @param _destination A set of positions representing the destination.
   */
  void setDestination(const std::set<Position> &_destination) {
    destination = _destination;
  }

  /**
   * @brief Gets the destination positions for the mouse.
   *
   * @return A set of positions representing the destination.
   */
  [[nodiscard]]
  std::set<Position> getDestination() const {
    return destination;
  }

 protected:
  const int mazeWidth = GLOBAL::MAZE::COLUMNS;
  const int mazeHeight = GLOBAL::MAZE::ROWS;
  std::set<Position> destination = GLOBAL::CONSTANTS::GOAL_POSITIONS;
};

#endif //MICROMOUSE_INCLUDE_MODEL_MOUSE_MOVEMENT_PROVIDER_H_
