#ifndef MICROMOUSE_INCLUDE_MODEL_SENSORREADINGS_H_
#define MICROMOUSE_INCLUDE_MODEL_SENSORREADINGS_H_

#include <array>
#include <map>
#include "Direction.h"
#include "CellType.h"

class SensorReadings {
 public:
  SensorReadings(CellType cellType) : cellType(cellType) {};
  void setWall(Direction direction, bool isWall);
  bool isWall(Direction direction) const;
  CellType getCellType() const;

 private:
  std::map<Direction, bool> readings{{NORTH, false}, {EAST, false}, {SOUTH, false}, {WEST, false}};
  CellType cellType{};
};

#endif //MICROMOUSE_INCLUDE_MODEL_SENSORREADINGS_H_
