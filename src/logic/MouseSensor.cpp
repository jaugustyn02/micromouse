#include "../../include/logic/MouseSensor.h"

SensorReading MouseSensor::getSensorReading(const Position &position) const {
  SensorReading sensorReading(maze.getCellType(position));
  for (int i = 0; i < 4; i++) {
    auto direction = static_cast<Direction>(i);
    sensorReading.setWall(direction, maze.isWall(position, direction));
  }
  return sensorReading;
}