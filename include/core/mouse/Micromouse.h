#ifndef MICROMOUSE_INCLUDE_GUI_MICROMOUSE_H_
#define MICROMOUSE_INCLUDE_GUI_MICROMOUSE_H_

#include <map>
#include "core/maze/Maze.h"
#include "MouseSensor.h"
#include "model/Direction.h"
#include "model/MouseMode.h"
#include "model/Position.h"
#include "brain/MouseBrain.h"
#include "model/MoveStatus.h"
#include "brain/MouseBrainProvider.h"

/**
 * @class Micromouse
 * @brief Represents the Micromouse robot.
 *
 * This class encapsulates the functionality of the Micromouse robot, including its sensors,
 * brain, and movement logic. It provides methods to control the mouse's behavior and retrieve
 * its current state.
 */
class Micromouse {
 public:
  /**
   * @brief Constructs a Micromouse instance with the specified sensor and starting position.
   * @param sensor The sensor used by the Micromouse.
   * @param startPosition The starting position of the Micromouse in the maze.
   */
  Micromouse(MouseSensor sensor, Position startPosition);

  /**
   * @brief Moves the Micromouse based on its current mode and sensor readings.
   * @return The status of the move operation.
   */
  MoveStatus makeMove();

  /**
   * @brief Sets the brain of the Micromouse to a new instance.
   * @param _brain The new brain instance to be used by the Micromouse.
   */
  void setBrain(std::unique_ptr<MouseBrain> _brain);

  /**
   * @brief Resets the Micromouse to its initial state.
   * This includes resetting the brain and the current position.
   */
  void reset();

  /**
   * @brief Gets the current mode of the Micromouse.
   * @return The current mode of the Micromouse.
   */
  [[nodiscard]] MouseMode getMode() const { return brain->getMode(); };

  /**
   * @brief Gets the current position of the Micromouse.
   * @return The current position of the Micromouse in the maze.
   */
  [[nodiscard]]
  Position getPosition() const { return currentPosition; }

 private:
  MouseSensor sensor;
  std::unique_ptr<MouseBrain> brain;
  Position startPosition;
  Position currentPosition;

  void onDestinationReached() const;
};

#endif //MICROMOUSE_INCLUDE_GUI_MICROMOUSE_H_
