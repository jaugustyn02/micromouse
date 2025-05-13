#include "../../include/core/Simulation.h"

Simulation::Simulation() : mouse(Micromouse(MouseSensor(maze), GLOBAL::MAZE::START_POSITION)) {
  maze.generate();
}

void Simulation::start() {
  std::cout << "[Simulation]: Simulation started" << std::endl;
  isRunning = true;
}

void Simulation::stop() {
  std::cout << "[Simulation]: Simulation stopped" << std::endl;
  isRunning = false;
}

void Simulation::reset() {
  std::cout << "[Simulation]: Simulation reset" << std::endl;
  stop();
  mouse.reset();
}

void Simulation::setSpeed(const int _speed) {
  std::cout << "[Simulation]: Setting speed to " << _speed << std::endl;
  speed = _speed;
}

int Simulation::getSpeed() {
  return speed;
}

void Simulation::generateMaze() {
  reset();
  maze.generate();
}

void Simulation::setMouseMode(const MouseMode mode) {
  stop();
  mouse.setMode(mode);
}

void Simulation::nextStep() {
  moveMouse();
}

void Simulation::moveMouse() {
  if (const auto moveStatus = mouse.makeMove(); moveStatus == FAILURE || moveStatus == GOAL_REACHED) {
    stop();
  }
}

void Simulation::setMouseBrain(const MouseBrainType brainType) {
  std::cout << "[Simulation]: Setting mouse brain to " << toString(brainType) << std::endl;
  stop();
  try {
    auto brain = std::make_unique<MouseBrain>(MouseBrainProvider::getMouseBrainInstance(brainType));
    mouse.setBrain(std::move(brain));
  } catch (const std::exception &e) {
    std::cerr << "[Simulation]: Error setting mouse brain: " << e.what() << std::endl;
    exit(1);
  }
}
