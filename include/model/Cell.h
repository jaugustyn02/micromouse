#ifndef MICROMOUSE_INCLUDE_GUI_CELL_H_
#define MICROMOUSE_INCLUDE_GUI_CELL_H_

struct Cell {
  Cell(int x, int y) : x(x), y(y) {}

  bool topWall = true;
  bool rightWall = true;
  bool bottomWall = true;
  bool leftWall = true;

  bool visited = false;
  bool isStart = false;
  bool isGoal = false;

  const int x;
  const int y;
};

#endif //MICROMOUSE_INCLUDE_GUI_CELL_H_
