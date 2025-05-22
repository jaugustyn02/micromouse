#ifndef MICROMOUSE_INCLUDE_MODEL_MAZERENDERER_H_
#define MICROMOUSE_INCLUDE_MODEL_MAZERENDERER_H_

#include "core/maze/Maze.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "Drawable.h"
#include "TGUI/Backend/SFML-Graphics.hpp"

/**
 * @brief The MazeRenderer class is responsible for rendering the maze on the screen.
 * It uses SFML to draw the maze walls and cells.
 */
class MazeRenderer final : public Drawable {
 public:
  /**
   * @brief Constructor for the MazeRenderer class.
   * @param maze Reference to the Maze object.
   */
  explicit MazeRenderer(MazeReader &maze);

  /**
   * @brief draws the maze on the given window.
   * @param window The window to draw on.
   */
  void draw(sf::RenderWindow &window) override;

  /**
   * @brief Draws the maze on the given window with a specific color for each cell.
   * @param window The window to draw on.
   */
  void colorCells(sf::RenderWindow &window);

  /**
   * @brief Draws the walls of the maze on the given window.
   * @param window The window to draw on.
   */
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
