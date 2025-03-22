#ifndef MICROMOUSE_INCLUDE_GUI_SENSOR_H_
#define MICROMOUSE_INCLUDE_GUI_SENSOR_H_

#include "Maze.h"
class Sensor {
 public:
  Sensor(int offsetX, int offsetY);
  bool detectWall(const Maze &maze, int x, int y) const;

 private:
  int offsetX, offsetY;
};

#endif //MICROMOUSE_INCLUDE_GUI_SENSOR_H_
