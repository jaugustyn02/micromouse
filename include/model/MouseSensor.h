#ifndef MICROMOUSE_INCLUDE_GUI_SENSOR_H_
#define MICROMOUSE_INCLUDE_GUI_SENSOR_H_

#include "Maze.h"
#include "Position.h"
#include "Direction.h"

class MouseSensor {
 public:
  MouseSensor(Position &position, Maze &maze);
  bool isWallInDirection(Direction direction);

 private:
  Position &position;
  Maze &maze;
};

#endif //MICROMOUSE_INCLUDE_GUI_SENSOR_H_
