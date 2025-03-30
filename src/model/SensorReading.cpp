#include "../../include/model/SensorReading.h"

bool SensorReading::isWall(Direction dir) const {
  return readings.at(dir);
}
void SensorReading::setWall(Direction direction, bool isWall) {
  readings[direction] = isWall;
}
CellType SensorReading::getCellType() const {
  return cellType;
}




