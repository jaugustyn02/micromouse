#ifndef MICROMOUSE_INCLUDE_CORE_SIMULATION_H_
#define MICROMOUSE_INCLUDE_CORE_SIMULATION_H_

#include <utility>
#include <vector>
#include "Maze.h"
#include "Micromouse.h"
#include "SimulationController.h"

class Simulation : public SimulationController {
 public:
  Simulation(Maze &maze, Micromouse &mouse);
  void start() override;
  void stop() override;
  void reset() override;
  void setMouseMode(int mode) override;
  void setSpeed(int speed) override;
  void generateMaze() override;
 private:
  Maze &maze;
  Micromouse &mouse;
};

#endif //MICROMOUSE_INCLUDE_CORE_SIMULATION_H_
