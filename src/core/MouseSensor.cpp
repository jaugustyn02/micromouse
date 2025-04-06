#include "../../include/core/MouseSensor.h"

SensorReadings MouseSensor::getSensorReadings(const Position &position) const {
  SensorReadings sensorReading(maze.getCellType(position));
  for (int i = 0; i < 4; i++) {
    auto direction = static_cast<Direction>(i);
    sensorReading.setWall(direction, maze.isWall(position, direction));
  }
  return sensorReading;
}