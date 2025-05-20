#ifndef MICROMOUSE_INCLUDE_CORE_SIMULATIONCONTROLLER_H_
#define MICROMOUSE_INCLUDE_CORE_SIMULATIONCONTROLLER_H_

#include <utility>

#include "model/MouseMode.h"
#include "mouse/brain/MouseBrain.h"
#include "mouse/Micromouse.h"
#include "maze/Maze.h"

/**
 * @class SimulationController
 * @brief Abstract interface for controlling a simulation instance.
 *
 * This class defines the essential operations for managing the simulation lifecycle,
 * including control over the simulation state, mouse configuration, and maze generation.
 */
class SimulationController {
 public:
  /**
   * @brief Starts the simulation.
   */
  virtual void start() = 0;

  /**
   * @brief Stops the simulation.
   */
  virtual void stop() = 0;

  /**
   * @brief Resets the simulation by resetting the position and state of the mouse.
   */
  virtual void reset() = 0;

  /**
   * @brief Executes the next step in the simulation.
   */
  virtual void nextStep() = 0;

  /**
    * @brief Assigns a brain of given type to the mouse.
    * @param brainType The brain implementation to use.
    */
  virtual void setMouseBrain(MouseBrainType brainType) = 0;

  /**
   * @brief Invokes maze generation.
   */
  virtual void generateMaze() = 0;

  /**
   * @brief Sets the simulation speed.
   * @param speed The new speed value.
   */
  virtual void setSpeed(int speed) = 0;

  /**
   * @brief Retrieves the current simulation speed.
   * @return The speed value.
   */
  virtual int getSpeed() = 0;

  /**
   * @brief Checks if the simulation is currently running.
   * @return True if the simulation is running, false otherwise.
   */
  virtual bool getIsRunning() = 0;

  /**
   * @brief Retrieves the current mouse instance.
   * @return A reference to the Micromouse instance.
   */
  virtual Micromouse &getMouse() = 0;

  /**
   * @brief Retrieves the current maze instance.
   * @return A reference to the Maze instance.
   */
  virtual Maze &getMaze() = 0;

  /**
   * @brief Virtual destructor.
   */
  virtual ~SimulationController() = default;
};

#endif //MICROMOUSE_INCLUDE_CORE_SIMULATIONCONTROLLER_H_
