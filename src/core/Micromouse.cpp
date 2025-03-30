#include "../../include/core/Micromouse.h"

Micromouse::Micromouse(Position &position, MouseSensor &sensor, MouseBrain &brain, Direction direction)
    : position(position), sensor(sensor), direction(direction), brain(brain) {}

void Micromouse::makeMove() {}

int Micromouse::getX() const {
  return position.getX();
}

int Micromouse::getY() const {
  return position.getY();
}
void Micromouse::setMode(MouseMode mode) {

}
