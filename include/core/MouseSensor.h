#ifndef MICROMOUSE_INCLUDE_GUI_SENSOR_H_
#define MICROMOUSE_INCLUDE_GUI_SENSOR_H_

#include "Maze.h"
#include "../model/Position.h"
#include "../model/Direction.h"
#include "../model/SensorReadings.h"

class MouseSensor {
 public:
  MouseSensor(MazeReader &mazeReader) : maze(mazeReader) {};
  SensorReadings getSensorReadings(const Position &position) const;

 private:
  MazeReader &maze;
};

#endif //MICROMOUSE_INCLUDE_GUI_SENSOR_H_
