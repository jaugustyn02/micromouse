#ifndef MICROMOUSE_INCLUDE_MODEL_MOUSE_MOVEMENT_PROVIDER_H_
#define MICROMOUSE_INCLUDE_MODEL_MOUSE_MOVEMENT_PROVIDER_H_

#include "core/GlobalConfig.h"
#include "model/Direction.h"
#include "model/Position.h"
#include "model/SensorReadings.h"
#include <utility>
#include <vector>

class MouseMovementProvider {
 public:
  virtual ~MouseMovementProvider() = default;

  virtual Direction decideMove(Position position, SensorReadings readings) = 0;

  virtual void reset() {
  };

  void setDestination(const std::set<Position> &_destination) {
    destination = _destination;
  }

  [[nodiscard]] std::set<Position> getDestination() const {
    return destination;
  }

 protected:
  const int mazeWidth = GLOBAL::MAZE::COLUMNS;
  const int mazeHeight = GLOBAL::MAZE::ROWS;
  std::set<Position> destination = GLOBAL::CONSTANTS::GOAL_POSITIONS;

  bool isDestination(const Position position) {
    return destination.find(position) != destination.end();
  }
};

#endif //MICROMOUSE_INCLUDE_MODEL_MOUSE_MOVEMENT_PROVIDER_H_
