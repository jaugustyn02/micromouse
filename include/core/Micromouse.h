#ifndef MICROMOUSE_INCLUDE_GUI_MICROMOUSE_H_
#define MICROMOUSE_INCLUDE_GUI_MICROMOUSE_H_

#include <map>
#include "Maze.h"
#include "../logic/MouseSensor.h"
#include "../model/Direction.h"
#include "../model/MouseMode.h"
#include "../model/Position.h"
#include "../logic/MouseBrain.h"

class Micromouse {
 public:
  Micromouse(Position &position, MouseSensor &sensor, MouseBrain &brain, Direction direction);
  void makeMove();
  void setMode(MouseMode mode);
  [[nodiscard]] int getX() const;
  [[nodiscard]] int getY() const;

 private:
  Position &position;
  MouseSensor &sensor;
  MouseBrain &brain;
  Direction direction;
};

#endif //MICROMOUSE_INCLUDE_GUI_MICROMOUSE_H_
