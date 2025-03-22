#ifndef MICROMOUSE_INCLUDE_GUI_MICROMOUSE_H_
#define MICROMOUSE_INCLUDE_GUI_MICROMOUSE_H_

#include "../model/Maze.h"
#include "../model/Sensor.h"

class Micromouse {
 public:
  explicit Micromouse(Maze &maze);
  void move();
  void scanSurroundings();
  [[nodiscard]] int getX() const { return x; }
  [[nodiscard]] int getY() const { return y; }

 private:
  int x = 0, y = 0;
  Sensor sensors[4] = {Sensor(0, -1), Sensor(1, 0), Sensor(0, 1), Sensor(-1, 0)};
  Maze &maze;
};

#endif //MICROMOUSE_INCLUDE_GUI_MICROMOUSE_H_
