#ifndef MICROMOUSE_INCLUDE_MODEL_MAZERENDERER_H_
#define MICROMOUSE_INCLUDE_MODEL_MAZERENDERER_H_

#include "../model/Maze.h"
#include "SFML/Graphics/RenderWindow.hpp"

class MazeRenderer {
 public:
  MazeRenderer(Maze &maze);
  void draw(sf::RenderWindow &window);

 private:
  Maze &maze;
};

#endif //MICROMOUSE_INCLUDE_MODEL_MAZERENDERER_H_
