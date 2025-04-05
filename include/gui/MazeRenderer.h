#ifndef MICROMOUSE_INCLUDE_MODEL_MAZERENDERER_H_
#define MICROMOUSE_INCLUDE_MODEL_MAZERENDERER_H_

#include "../core/Maze.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "Drawable.h"
#include "TGUI/Backend/SFML-Graphics.hpp"

class MazeRenderer : public Drawable {
 public:
  explicit MazeRenderer(MazeReader &maze);
  void draw(sf::RenderWindow &window) override;

 private:
  MazeReader &maze;
  sf::RectangleShape horizontalWallShape;
  sf::RectangleShape verticalWallShape;
  sf::RectangleShape startAriaShape;
  sf::RectangleShape goalAriaShape;
};

#endif //MICROMOUSE_INCLUDE_MODEL_MAZERENDERER_H_
