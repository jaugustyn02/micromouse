#ifndef MICROMOUSE_INCLUDE_CORE_SIMULATION_H_
#define MICROMOUSE_INCLUDE_CORE_SIMULATION_H_

#include <utility>
#include <vector>
#include "maze/Maze.h"
#include "mouse/Micromouse.h"
#include "SimulationController.h"

/**
 * @class Simulation
 * @brief Concrete implementation of the SimulationController interface.
 *
 * Manages the Micromouse simulation, including maze generation, mouse movement,
 * speed control, and step-by-step execution.
 */
class Simulation final : public SimulationController {
 public:
  /**
   * @brief Constructs a Simulation instance with initialized maze and mouse.
   */
  Simulation();

  /**
   * @copydoc SimulationController::stop
   */
  void start() override;

  /**
   * @copydoc SimulationController::start
   */
  void stop() override;

  /**
   * @copydoc SimulationController::reset
   */
  void reset() override;

  /**
   * @copydoc SimulationController::nextStep
   */
  void nextStep() override;

  /**
   * @copydoc SimulationController::setMouseBrain
   */
  void setMouseBrain(MouseBrainType brainType) override;

  /**
   * @copydoc SimulationController::setSpeed
   */
  void setSpeed(int _speed) override;

  /**
   * @copydoc SimulationController::getSpeed
   */
  int getSpeed() override;

  /**
   * @copydoc SimulationController::generateMaze
   */
  void generateMaze() override;

  /**
   * @copydoc SimulationController::getIsRunning
   */
  bool getIsRunning() override { return isRunning; };

  /**
   * @copydoc SimulationController::getMouse
   */
  Micromouse &getMouse() override { return mouse; }

  /**
   * @copydoc SimulationController::getMaze
   */
  Maze &getMaze() override { return maze; }

 private:
  /**
   * @brief The maze used in the simulation.
   */
  Maze maze{GLOBAL::MAZE::COLUMNS, GLOBAL::MAZE::ROWS};

  /**
   * @brief The micromouse navigating the maze.
   */
  Micromouse mouse;

  /**
   * @brief Indicates whether the simulation is currently running.
   */
  bool isRunning{false};

  /**
   * @brief The speed of the simulation.
   */
  int speed{GLOBAL::SIMULATION::DEFAULT_SPEED};

  /**
   * @brief Executes a move operation for the mouse.
   */
  void moveMouse();
};

#endif //MICROMOUSE_INCLUDE_CORE_SIMULATION_H_
