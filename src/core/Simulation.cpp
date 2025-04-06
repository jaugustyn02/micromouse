#include "../../include/core/Simulation.h"

Simulation::Simulation(Maze &maze, Micromouse &mouse) : maze(maze), mouse(mouse) {}

void Simulation::start() {
  std::cout << "[SIMULATION]: Simulation started" << std::endl;
  isRunning = true;
}

void Simulation::stop() {
  std::cout << "[SIMULATION]: Simulation stopped" << std::endl;
  isRunning = false;
}

void Simulation::reset() {
  std::cout << "[SIMULATION]: Simulation reset" << std::endl;
  stop();
  mouse.reset();
}

void Simulation::setSpeed(int speed) {

}

void Simulation::generateMaze() {
  std::cout << "[SIMULATION]: Generate maze" << std::endl;
  reset();
  maze.generate();
}

void Simulation::setMouseMode(MouseMode mode) {
  mouse.setMode(mode);
  reset();
}

void Simulation::setMouseBrain(MouseBrain &brain) {
}

void Simulation::nextStep() {
  if (isRunning) {
    std::cout << "[SIMULATION]: Next step" << std::endl;
    moveMouse();
  }
}

void Simulation::moveMouse() {
  auto moveStatus = mouse.makeMove();
  if (moveStatus == MoveStatus::FAILURE
      || moveStatus == MoveStatus::GOAL_REACHED
      || moveStatus == MoveStatus::START_REACHED) {
    stop();
  }
}

