#include "../../include/core/Micromouse.h"

Micromouse::Micromouse(MouseBrain &brain, MouseSensor sensor, Position position, Direction direction)
    : brain(brain), sensor(sensor), direction(direction), position(position) {
}

MoveStatus Micromouse::makeMove() {
  auto sensorReadings = sensor.getSensorReadings(position);
  if (sensorReadings.getCellType() == CellType::GOAL) {
    std::cout << "[MICROMOUSE]: Goal reached!" << std::endl;
    return MoveStatus::GOAL_REACHED;
  }
  direction = brain.getNextMove(position, sensorReadings);
  position.translate(direction);
  return MoveStatus::SUCCESS;
}

int Micromouse::getX() const {
  return position.getX();
}

int Micromouse::getY() const {
  return position.getY();
}

void Micromouse::setMode(MouseMode mode) {
  std::cout << "[MICROMOUSE]: Mouse mode set to: " << toString(mode) << std::endl;
  brain.setMode(mode);
}

void Micromouse::reset() {
  std::cout << "[MICROMOUSE]: Mouse reset" << std::endl;
  position = Position(GLOBAL::SIMULATION::START_POSITION_X,
                      GLOBAL::SIMULATION::START_POSITION_Y);
  direction = Direction::EAST;
  brain.reset();
}
