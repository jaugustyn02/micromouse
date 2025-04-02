#include "../../include/core/Micromouse.h"

Micromouse::Micromouse(MouseBrain &brain, MouseSensor sensor, Position position, Direction direction)
    : brain(brain), sensor(sensor), direction(direction), position(position) {
}

void Micromouse::makeMove() {}

int Micromouse::getX() const {
  return position.getX();
}

int Micromouse::getY() const {
  return position.getY();
}
void Micromouse::setMode(MouseMode mode) {

}
