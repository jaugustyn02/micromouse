#include "../../include/core/Simulation.h"

Simulation::Simulation(Maze &maze, Micromouse &mouse) : maze(maze), mouse(mouse) {}

void Simulation::start() {
  isRunning = true;
  std::cout << "[SIMULATION]: Simulation started" << std::endl;
}
void Simulation::stop() {
  isRunning = false;
  std::cout << "[SIMULATION]: Simulation stopped" << std::endl;
}
void Simulation::reset() {
  isRunning = false;
  std::cout << "[SIMULATION]: Simulation reset" << std::endl;
}

void Simulation::setSpeed(int speed) {

}

void Simulation::generateMaze() {
  maze.generate();
  std::cout << "[SIMULATION]: Generate maze" << std::endl;
}

void Simulation::setMouseMode(MouseMode mode) {

}

void Simulation::setMouseBrain(MouseBrain &brain) {
}

void Simulation::nextStep() {
  if (isRunning) {
    std::cout << "[SIMULATION]: Next step" << std::endl;
    mouse.makeMove();
  }
}

