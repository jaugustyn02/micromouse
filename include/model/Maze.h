#ifndef MICROMOUSE_INCLUDE_GUI_MAZE_H_
#define MICROMOUSE_INCLUDE_GUI_MAZE_H_

#include <vector>
#include "Cell.h"

class Maze {
 public:
  Maze(int width, int height);
  void generate();
  [[nodiscard]] Cell &getCell(int x, int y) const;
  [[nodiscard]] int getWidth() const { return width; }
  [[nodiscard]] int getHeight() const { return height; }

 private:
  int width, height;
  std::vector<std::vector<Cell>> grid;
  void initializeGrid();
  void resetGrid();
};

#endif //MICROMOUSE_INCLUDE_GUI_MAZE_H_
