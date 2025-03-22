#ifndef MICROMOUSE_INCLUDE_CORE_SIMULATION_H_
#define MICROMOUSE_INCLUDE_CORE_SIMULATION_H_

#include <utility>
#include <vector>
#include "../model/Maze.h"
#include "../model/Micromouse.h"

class Simulation {
 private:
  Maze maze;
  Micromouse mouse;
};

#endif //MICROMOUSE_INCLUDE_CORE_SIMULATION_H_
