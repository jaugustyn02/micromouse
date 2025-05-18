#ifndef MICROMOUSE_INCLUDE_CORE_SIMULATION_H_
#define MICROMOUSE_INCLUDE_CORE_SIMULATION_H_

#include <utility>
#include <vector>
#include "maze/Maze.h"
#include "mouse/Micromouse.h"
#include "SimulationController.h"

class Simulation final : public SimulationController {
public:
 Simulation();

 void start() override;

 void stop() override;

 void reset() override;

 void nextStep() override;

 void setMouseMode(MouseMode mode) override;

 void setMouseBrain(MouseBrainType brainType) override;

 void setSpeed(int _speed) override;

 int getSpeed() override;

 void generateMaze() override;

 bool getIsRunning() override { return isRunning; };
 Micromouse &getMouse() override { return mouse; }
 Maze &getMaze() override { return maze; }

private:
 Maze maze{GLOBAL::MAZE::COLUMNS, GLOBAL::MAZE::ROWS};
 Micromouse mouse;
 bool isRunning{false};
 int speed{GLOBAL::SIMULATION::DEFAULT_SPEED};

 void moveMouse();
};

#endif //MICROMOUSE_INCLUDE_CORE_SIMULATION_H_
