#include "../../include/model/Maze.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "../../include/gui/MazeRenderer.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "../../include/core/GlobalConfig.h"

MazeRenderer::MazeRenderer(Maze &maze) : maze(maze) {}

void MazeRenderer::draw(sf::RenderWindow &window) {
  float cellSize = GLOBAL::RENDER::CELL_SIZE;
  sf::Color wallColor = GLOBAL::RENDER::WALL_COLOR;

  for (int y = 0; y < maze.getHeight(); ++y) {
    for (int x = 0; x < maze.getWidth(); ++x) {
      Cell &cell = maze.getCell(x, y);
      float posX = x * cellSize + 1;
      float posY = y * cellSize + 1;

      sf::Vertex line[2];

      if (cell.topWall) {
        line[0] = sf::Vertex(sf::Vector2f(posX, posY), wallColor);
        line[1] = sf::Vertex(sf::Vector2f(posX + cellSize, posY), wallColor);
        window.draw(line, 2, sf::Lines);
      }
      if (cell.rightWall) {
        line[0] = sf::Vertex(sf::Vector2f(posX + cellSize, posY), wallColor);
        line[1] = sf::Vertex(sf::Vector2f(posX + cellSize, posY + cellSize), wallColor);
        window.draw(line, 2, sf::Lines);
      }
      if (cell.bottomWall) {
        line[0] = sf::Vertex(sf::Vector2f(posX, posY + cellSize), wallColor);
        line[1] = sf::Vertex(sf::Vector2f(posX + cellSize, posY + cellSize), wallColor);
        window.draw(line, 2, sf::Lines);
      }
      if (cell.leftWall) {
        line[0] = sf::Vertex(sf::Vector2f(posX, posY), wallColor);
        line[1] = sf::Vertex(sf::Vector2f(posX, posY + cellSize), wallColor);
        window.draw(line, 2, sf::Lines);
      }
    }
  }
}
