#include "model/SensorReadings.h"

bool SensorReadings::isWall(Direction dir) const {
  return readings.at(dir);
}

void SensorReadings::setWall(Direction direction, bool isWall) {
  readings[direction] = isWall;
}

CellType SensorReadings::getCellType() const {
  return cellType;
}

bool SensorReadings::isCellAGoal() const {
  return cellType == CellType::GOAL;
}




