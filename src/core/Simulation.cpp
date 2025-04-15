#include "../../include/core/Simulation.h"

Simulation::Simulation() :
    mouse(Micromouse(MouseSensor(maze))) {
  maze.generate();
}

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
  stop();
}

void Simulation::nextStep() {
  if (isRunning) {
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

void Simulation::setMouseBrain(MouseBrainType brainType) {
  std::cout << "[SIMULATION]: Setting mouse brain to " << toString(brainType) << std::endl;
  try {
    auto brain = std::make_unique<MouseBrain>(MouseBrainProvider::getMouseBrainInstance(brainType));
    mouse.setBrain(std::move(brain));
  } catch (const std::exception &e) {
    std::cerr << "[SIMULATION]: Error setting mouse brain: " << e.what() << std::endl;
    return;
  }
}

