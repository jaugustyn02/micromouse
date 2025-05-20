#include "core/mouse/Micromouse.h"

#include <utility>

Micromouse::Micromouse(const MouseSensor sensor, const Position startPosition) : sensor(sensor),
                                                                                 brain(std::make_unique<MouseBrain>(
                                                                                     MouseBrainProvider::getMouseBrainInstance(
                                                                                         ADVANCED))),
                                                                                 startPosition(startPosition),
                                                                                 currentPosition(startPosition) {
  std::cout << "[Micromouse]: Initial position: " << currentPosition.toString() << std::endl;
  std::cout << "[Micromouse]: Initial mode: " << toString(brain->getMode()) << std::endl;
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

void Micromouse::onDestinationReached() const {
  std::cout << "[Micromouse]: Destination reached!" << std::endl;
  brain->nextMode();
}

void Micromouse::reset() {
  std::cout << "[Micromouse]: Mouse reset" << std::endl;
  currentPosition = startPosition;
  brain->reset();
}

void Micromouse::setBrain(std::unique_ptr<MouseBrain> _brain) {
  reset();
  std::cout << "[Micromouse]: Mouse brain changed" << std::endl;
  this->brain = std::move(_brain);
  std::cout << "[Micromouse]:Brain mode changed to: " << toString(brain->getMode()) << std::endl;
}
