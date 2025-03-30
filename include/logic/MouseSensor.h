#ifndef MICROMOUSE_INCLUDE_GUI_SENSOR_H_
#define MICROMOUSE_INCLUDE_GUI_SENSOR_H_

#include "../core/Maze.h"
#include "../model/Position.h"
#include "../model/Direction.h"
#include "../model/SensorReading.h"

class MouseSensor {
 public:
  MouseSensor(MazeReader &mazeReader) : maze(mazeReader) {};
  SensorReading getSensorReading(const Position &position) const;

 private:
  MazeReader &maze;
};

#endif //MICROMOUSE_INCLUDE_GUI_SENSOR_H_
