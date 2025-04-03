#include "../../include/core/Micromouse.h"

Micromouse::Micromouse(MouseBrain &brain, MouseSensor sensor, Position position, Direction direction)
    : brain(brain), sensor(sensor), direction(direction), position(position) {
}

void Micromouse::makeMove() {
  auto sensorReadings = sensor.getSensorReadings(position);
  direction = brain.getNextMove(position, sensorReadings);
  position.translate(direction);
  std::cout << "[MICROMOUSE]: Move in direction: " << to_string(direction) << std::endl;
}

int Micromouse::getX() const {
  return position.getX();
}

int Micromouse::getY() const {
  return position.getY();
}

void Micromouse::setMode(MouseMode mode) {
  brain.setMode(mode);
}
