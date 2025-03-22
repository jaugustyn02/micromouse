#ifndef MICROMOUSE_INCLUDE_GUI_CELL_H_
#define MICROMOUSE_INCLUDE_GUI_CELL_H_

struct Cell {
  bool topWall = true;
  bool rightWall = true;
  bool bottomWall = true;
  bool leftWall = true;
  bool visited = false;
};

#endif //MICROMOUSE_INCLUDE_GUI_CELL_H_
