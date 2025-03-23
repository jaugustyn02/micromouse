#include "../../include/model/Maze.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "../../include/gui/MazeRenderer.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "../../include/core/GlobalConfig.h"

MazeRenderer::MazeRenderer(Maze &maze) : maze(maze) {
  sf::Color wallColor = GLOBAL::RENDER::WALL_COLOR;
  float wallThickness = GLOBAL::RENDER::WALL_THICKNESS;
  float cellSize = GLOBAL::RENDER::CELL_SIZE;
  float offsetX = GLOBAL::RENDER::OFFSET_X;
  float offsetY = GLOBAL::RENDER::OFFSET_Y;

  horizontalWallShape.setSize(sf::Vector2f(cellSize, wallThickness));
  horizontalWallShape.setFillColor(wallColor);
  horizontalWallShape.setOrigin(-offsetX, -offsetY);

  verticalWallShape.setSize(sf::Vector2f(wallThickness, cellSize));
  verticalWallShape.setFillColor(wallColor);
  verticalWallShape.setOrigin(-offsetX, -offsetY);

  startAriaShape.setSize(sf::Vector2f(cellSize, cellSize));
  startAriaShape.setFillColor(GLOBAL::RENDER::START_COLOR);
  startAriaShape.setOrigin(-offsetX, -offsetY);

  goalAriaShape.setSize(sf::Vector2f(cellSize, cellSize));
  goalAriaShape.setFillColor(GLOBAL::RENDER::GOAL_COLOR);
  goalAriaShape.setOrigin(-offsetX, -offsetY);
}

void MazeRenderer::draw(sf::RenderWindow &window) {
  float wallThickness = GLOBAL::RENDER::WALL_THICKNESS;
  float cellSize = GLOBAL::RENDER::CELL_SIZE;

  for (int y = 0; y < maze.getHeight(); ++y) {
    for (int x = 0; x < maze.getWidth(); ++x) {
      Cell &cell = maze.getCell(x, y);
      float posX = (float) x * (cellSize - wallThickness);
      float posY = (float) y * (cellSize - wallThickness);

      if (cell.isStart) {
        startAriaShape.setPosition(posX, posY);
        window.draw(startAriaShape);
      }

      if (cell.isGoal) {
        goalAriaShape.setPosition(posX, posY);
        window.draw(goalAriaShape);
      }

      if (cell.topWall) {
        horizontalWallShape.setPosition(posX, posY);
        window.draw(horizontalWallShape);
      }
      if (cell.rightWall) {
        verticalWallShape.setPosition(posX + cellSize - wallThickness, posY);
        window.draw(verticalWallShape);
      }
      if (cell.bottomWall) {
        horizontalWallShape.setPosition(posX, posY + cellSize - wallThickness);
        window.draw(horizontalWallShape);
      }
      if (cell.leftWall) {
        verticalWallShape.setPosition(posX, posY);
        window.draw(verticalWallShape);
      }
    }
  }
}