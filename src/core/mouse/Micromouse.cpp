#include "../../../include/core/mouse/Micromouse.h"

#include <utility>

Micromouse::Micromouse(MouseSensor sensor, Position startPosition) :
    sensor(sensor),
    startPosition(startPosition),
    position(startPosition),
    brain(std::make_unique<MouseBrain>(MouseBrainProvider::getMouseBrainInstance(MouseBrainType::RANDOM))) {
  std::cout << "[MICROMOUSE]: Micromouse initialized at position: " << position.toString() << std::endl;
  std::cout << "[MICROMOUSE]: Initial mode: " << toString(brain->getMode()) << std::endl;
}

MoveStatus Micromouse::makeMove() {
  auto sensorReadings = sensor.getSensorReadings(position);

  if (sensorReadings.isCellAGoal()) {
    onGoalReached();
    return MoveStatus::GOAL_REACHED;
  }

  auto direction = brain->getNextMove(position, sensorReadings);
  position.translate(direction);
  return MoveStatus::SUCCESS;
}

void Micromouse::onGoalReached() {
  std::cout << "[MICROMOUSE]: Goal reached!" << std::endl;
}

void Micromouse::reset() {
  std::cout << "[MICROMOUSE]: Mouse reset" << std::endl;
  position = startPosition;
  brain->reset();
}

void Micromouse::setMode(MouseMode mode) {
  std::cout << "[MICROMOUSE]: Mouse mode set to: " << toString(mode) << std::endl;
  brain->setMode(mode);
  position = startPosition;
}

void Micromouse::setBrain(std::unique_ptr<MouseBrain> _brain) {
  reset();
  std::cout << "[MICROMOUSE]: Mouse brain changed" << std::endl;
  this->brain = std::move(_brain);
  std::cout << "[MICROMOUSE]: New brain mode: " << toString(brain->getMode()) << std::endl;
}

int Micromouse::getX() const {
  return position.getX();
}

int Micromouse::getY() const {
  return position.getY();
}
