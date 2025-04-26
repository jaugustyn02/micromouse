#include "../../../include/core/mouse/Micromouse.h"

#include <utility>

Micromouse::Micromouse(const MouseSensor sensor, const Position startPosition) : sensor(sensor),
  brain(std::make_unique<MouseBrain>(MouseBrainProvider::getMouseBrainInstance(RANDOM))),
  startPosition(startPosition),
  currentPosition(startPosition) {
  std::cout << "[MICROMOUSE]: Micromouse initialized at position: " << currentPosition.toString() << std::endl;
  std::cout << "[MICROMOUSE]: Initial mode: " << toString(brain->getMode()) << std::endl;
}

MoveStatus Micromouse::makeMove() {
  const auto sensorReadings = sensor.getSensorReadings(currentPosition);

  if (brain->isDestinationReached(currentPosition)) {
    onDestinationReached();
    return GOAL_REACHED;
  }

  const auto direction = brain->getNextMove(currentPosition, sensorReadings);
  currentPosition.translate(direction);
  return SUCCESS;
}

void Micromouse::onDestinationReached() {
  std::cout << "[MICROMOUSE]: Destination reached!" << std::endl;
  switch (brain->getMode()) {
    case EXPLORATION:
      setMode(EXPLORATION_ON_RETURN);
      break;
    case EXPLORATION_ON_RETURN:
      setMode(FASTEST_PATH);
      break;
    case FASTEST_PATH:
    default:
      setMode(EXPLORATION);
  }
}

void Micromouse::reset() {
  std::cout << "[MICROMOUSE]: Mouse reset" << std::endl;
  currentPosition = startPosition;
  brain->reset();
}

void Micromouse::setMode(const MouseMode mode) const {
  std::cout << "[MICROMOUSE]: Mouse mode set to: " << toString(mode) << std::endl;
  brain->setMode(mode);
}

void Micromouse::setBrain(std::unique_ptr<MouseBrain> _brain) {
  reset();
  std::cout << "[MICROMOUSE]: Mouse brain changed" << std::endl;
  this->brain = std::move(_brain);
  std::cout << "[MICROMOUSE]: New brain mode: " << toString(brain->getMode()) << std::endl;
}

int Micromouse::getX() const {
  return currentPosition.getX();
}

int Micromouse::getY() const {
  return currentPosition.getY();
}
