#ifndef MICROMOUSE_INCLUDE_GUI_MICROMOUSE_H_
#define MICROMOUSE_INCLUDE_GUI_MICROMOUSE_H_

#include <map>
#include "core/maze/Maze.h"
#include "MouseSensor.h"
#include "model/Direction.h"
#include "model/MouseMode.h"
#include "model/Position.h"
#include "brain/MouseBrain.h"
#include "model/MoveStatus.h"
#include "brain/MouseBrainProvider.h"

class Micromouse {
 public:
  Micromouse(MouseSensor sensor, Position startPosition);

  MoveStatus makeMove();

  void setBrain(std::unique_ptr<MouseBrain> _brain);

  void reset();

  [[nodiscard]] MouseMode getMode() const { return brain->getMode(); };

  [[nodiscard]] Position getPosition() const { return currentPosition; }

 private:
  MouseSensor sensor;
  std::unique_ptr<MouseBrain> brain;
  Position startPosition;
  Position currentPosition;

  void onDestinationReached() const;
};

#endif //MICROMOUSE_INCLUDE_GUI_MICROMOUSE_H_
