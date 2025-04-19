#ifndef MICROMOUSE_INCLUDE_MODEL_MAZERENDERER_H_
#define MICROMOUSE_INCLUDE_MODEL_MAZERENDERER_H_

#include "../core/maze/Maze.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "Drawable.h"
#include "TGUI/Backend/SFML-Graphics.hpp"

class MazeRenderer final : public Drawable {
public:
 explicit MazeRenderer(MazeReader &maze);

 void draw(sf::RenderWindow &window) override;

 void colorCells(sf::RenderWindow &window);

 void drawWalls(sf::RenderWindow &window);

private:
 MazeReader &maze;
 sf::RectangleShape horizontalWallShape;
 sf::RectangleShape verticalWallShape;
 sf::RectangleShape cellShape;

 void drawCellWalls(sf::RenderWindow &window, Position cellPosition);

 void drawCellBackground(sf::RenderWindow &window, Position cellPosition, CellType cellType);

 static float getTopLeftCornerPositionX(Position cellPosition);

 static float getTopLeftCornerPositionY(Position cellPosition);
};

#endif //MICROMOUSE_INCLUDE_MODEL_MAZERENDERER_H_
