#ifndef MICROMOUSE_INCLUDE_CORE_MAZEREADER_H_
#define MICROMOUSE_INCLUDE_CORE_MAZEREADER_H_

#include "../../model/Cell.h"

class MazeReader {
 public:
  virtual bool isWall(Position position, Direction direction) const = 0;
  virtual CellType getCellType(Position position) const = 0;
  virtual int getWidth() const = 0;
  virtual int getHeight() const = 0;
};

#endif //MICROMOUSE_INCLUDE_CORE_MAZEREADER_H_
