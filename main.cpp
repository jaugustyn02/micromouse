#ifndef MICROMOUSE_SRC_MAIN_H_
#define MICROMOUSE_SRC_MAIN_H_

#include "include/model/Maze.h"
#include "include/model/Micromouse.h"
#include "include/gui/GUIManager.h"
#include "include/core/GlobalConfig.h"

int main() {
  Maze maze(GLOBAL::SIMULATION::MAZE_WIDTH, GLOBAL::SIMULATION::MAZE_HEIGHT);
  maze.generate();

  Micromouse mouse(maze);

  GUIManager guiManager(maze, mouse);
  guiManager.run();

  return 0;
}

#endif //MICROMOUSE_SRC_MAIN_H_
