#ifndef MICROMOUSE_INCLUDE_CORE_SIMULATIONCONTROLLER_H_
#define MICROMOUSE_INCLUDE_CORE_SIMULATIONCONTROLLER_H_

#include <utility>

#include "../model/MouseMode.h"
#include "mouse/brain/MouseBrain.h"
#include "mouse/Micromouse.h"
#include "maze/Maze.h"

class SimulationController {
 public:
  virtual void start() = 0;
  virtual void stop() = 0;
  virtual void reset() = 0;
  virtual void nextStep() = 0;
  virtual void setMouseMode(MouseMode mode) = 0;
  virtual void setMouseBrain(MouseBrainType brainType) = 0;
  virtual void generateMaze() = 0;
  virtual void setSpeed(int speed) = 0;
  virtual Micromouse &getMouse() = 0;
  virtual Maze &getMaze() = 0;
  virtual ~SimulationController() = default;
};

#endif //MICROMOUSE_INCLUDE_CORE_SIMULATIONCONTROLLER_H_
