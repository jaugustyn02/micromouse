#ifndef MICROMOUSE_INCLUDE_CORE_SIMULATION_H_
#define MICROMOUSE_INCLUDE_CORE_SIMULATION_H_

#include <utility>
#include <vector>
#include "maze/Maze.h"
#include "mouse/Micromouse.h"
#include "SimulationController.h"

class Simulation : public SimulationController {
 public:
  Simulation();
  void start() override;
  void stop() override;
  void reset() override;
  void nextStep() override;
  void setMouseMode(MouseMode mode) override;
  void setMouseBrain(MouseBrainType brainType) override;
  void setSpeed(int speed) override;
  void generateMaze() override;
  Micromouse &getMouse() override { return mouse; }
  Maze &getMaze() override { return maze; }
 private:
  Maze maze{GLOBAL::SIMULATION::MAZE_WIDTH, GLOBAL::SIMULATION::MAZE_HEIGHT};
  Micromouse mouse;
  bool isRunning{false};
  void moveMouse();
};

#endif //MICROMOUSE_INCLUDE_CORE_SIMULATION_H_
