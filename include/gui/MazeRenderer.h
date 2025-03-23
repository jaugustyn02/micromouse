#ifndef MICROMOUSE_INCLUDE_MODEL_MAZERENDERER_H_
#define MICROMOUSE_INCLUDE_MODEL_MAZERENDERER_H_

#include "../model/Maze.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/RectangleShape.hpp"

class MazeRenderer {
 public:
  explicit MazeRenderer(Maze &maze);
  void draw(sf::RenderWindow &window);

 private:
  Maze &maze;
  sf::RectangleShape horizontalWallShape;
  sf::RectangleShape verticalWallShape;
  sf::RectangleShape startAriaShape;
  sf::RectangleShape goalAriaShape;
};

#endif //MICROMOUSE_INCLUDE_MODEL_MAZERENDERER_H_
