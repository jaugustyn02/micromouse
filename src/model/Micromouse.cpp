#include "../../include/model/Micromouse.h"

Micromouse::Micromouse(Position &position, MouseSensor &sensor, Direction direction, MouseMode mode)
    : position(position), sensor(sensor), direction(direction), mode(mode) {}

void Micromouse::makeMove() {}

int Micromouse::getX() const {
  return position.getX();
}

int Micromouse::getY() const {
  return position.getY();
}
void Micromouse::setMode(MouseMode mode) {

}
