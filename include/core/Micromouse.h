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
  Micromouse(MouseBrain &brain, MouseSensor sensor, Position position, Direction direction);
  void makeMove();
  void setMode(MouseMode mode);
  [[nodiscard]] int getX() const;
  [[nodiscard]] int getY() const;

 private:
  MouseBrain brain;
  Position position;
  MouseSensor sensor;
  Direction direction;
};

#endif //MICROMOUSE_INCLUDE_GUI_MICROMOUSE_H_
