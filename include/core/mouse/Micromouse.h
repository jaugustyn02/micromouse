#ifndef MICROMOUSE_INCLUDE_GUI_MICROMOUSE_H_
#define MICROMOUSE_INCLUDE_GUI_MICROMOUSE_H_

#include <map>
#include "../maze/Maze.h"
#include "MouseSensor.h"
#include "../../model/Direction.h"
#include "../../model/MouseMode.h"
#include "../../model/Position.h"
#include "brain/MouseBrain.h"
#include "../../model/MoveStatus.h"
#include "brain/MouseBrainProvider.h"

class Micromouse {
 public:
  Micromouse(MouseSensor sensor, Position startPosition);
  MoveStatus makeMove();
  void setMode(MouseMode mode);
  void setBrain(std::unique_ptr<MouseBrain> brain);
  void reset();
  [[nodiscard]] int getX() const;
  [[nodiscard]] int getY() const;

 private:
  MouseSensor sensor;
  std::unique_ptr<MouseBrain> brain;
  Position startPosition;
  Position position;
  void onGoalReached();
};

#endif //MICROMOUSE_INCLUDE_GUI_MICROMOUSE_H_
