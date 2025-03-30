#ifndef MICROMOUSE_INCLUDE_MODEL_SENSORREADING_H_
#define MICROMOUSE_INCLUDE_MODEL_SENSORREADING_H_

#include <array>
#include <map>
#include "Direction.h"
#include "CellType.h"

class SensorReading {
 public:
  SensorReading(CellType cellType) : cellType(cellType) {};
  void setWall(Direction direction, bool isWall);
  bool isWall(Direction direction) const;
  CellType getCellType() const;

 private:
  std::map<Direction, bool> readings{{NORTH, false}, {EAST, false}, {SOUTH, false}, {WEST, false}};
  CellType cellType{};
};

#endif //MICROMOUSE_INCLUDE_MODEL_SENSORREADING_H_
