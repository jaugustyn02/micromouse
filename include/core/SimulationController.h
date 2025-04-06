#ifndef MICROMOUSE_INCLUDE_CORE_SIMULATIONCONTROLLER_H_
#define MICROMOUSE_INCLUDE_CORE_SIMULATIONCONTROLLER_H_

#include "../model/MouseMode.h"
#include "MouseBrain.h"

class SimulationController {
 public:
  virtual void start() = 0;
  virtual void stop() = 0;
  virtual void reset() = 0;
  virtual void nextStep() = 0;
  virtual void setMouseMode(MouseMode mode) = 0;
  virtual void setMouseBrain(MouseBrain &brain) = 0;
  virtual void generateMaze() = 0;
  virtual void setSpeed(int speed) = 0;

  virtual ~SimulationController() = default;
};

#endif //MICROMOUSE_INCLUDE_CORE_SIMULATIONCONTROLLER_H_
