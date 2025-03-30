#include "../../include/model/Cell.h"

Cell::Cell(Position location, CellType type) : location(location), type(type) {}

void Cell::addWall(Direction direction) {
  walls[direction] = true;
}

void Cell::removeWall(Direction direction) {
  walls[direction] = false;
}

bool Cell::hasWall(Direction direction) const {
  return walls.at(direction);
}

Position Cell::getLocation() const {
  return location;
}

CellType Cell::getType() const {
  return type;
}

void Cell::setType(CellType type) {
  this->type = type;
}

