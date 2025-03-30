#ifndef MICROMOUSE_INCLUDE_GUI_CELL_H_
#define MICROMOUSE_INCLUDE_GUI_CELL_H_

#include "Direction.h"
#include "Position.h"
#include "CellType.h"
#include <map>

class Cell {
 public:
  Cell(Position location, CellType type);
  void addWall(Direction direction);
  void removeWall(Direction direction);
  bool hasWall(Direction direction) const;
  Position getLocation() const;
  CellType getType() const;
  void setType(CellType type);

 private:
  std::map<Direction, bool> walls{{
                                      {Direction::NORTH, false},
                                      {Direction::EAST, false},
                                      {Direction::SOUTH, false},
                                      {Direction::WEST, false}
                                  }};
  Position location;
  CellType type;
};

#endif //MICROMOUSE_INCLUDE_GUI_CELL_H_
