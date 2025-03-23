#ifndef MICROMOUSE_INCLUDE_GUI_MICROMOUSE_H_
#define MICROMOUSE_INCLUDE_GUI_MICROMOUSE_H_

#include <map>
#include "../model/Maze.h"
#include "../model/MouseSensor.h"
#include "Direction.h"
#include "MouseMode.h"
#include "Position.h"

class Micromouse {
 public:
  explicit Micromouse(Position &position, MouseSensor &sensor, Direction direction, MouseMode mode);
  void makeMove();
  void setMode(MouseMode mode);
  [[nodiscard]] int getX() const;
  [[nodiscard]] int getY() const;

 private:
  Position &position;
  MouseSensor &sensor;
  Direction direction;
  MouseMode mode;
};

#endif //MICROMOUSE_INCLUDE_GUI_MICROMOUSE_H_
