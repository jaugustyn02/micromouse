#ifndef MICROMOUSE_INCLUDE_GUI_MAZE_H_
#define MICROMOUSE_INCLUDE_GUI_MAZE_H_

#include <vector>
#include "Cell.h"

class Maze {
 public:
  Maze(int width, int height);
  void generate();
  Cell &getCell(int x, int y) const;
  int getWidth() const { return width; }
  int getHeight() const { return height; }

 private:
  int width, height;
  std::vector<std::vector<Cell>> grid;
  void resetGrid();
};

#endif //MICROMOUSE_INCLUDE_GUI_MAZE_H_
