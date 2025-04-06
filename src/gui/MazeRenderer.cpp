#include "../../include/core/Maze.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "../../include/gui/MazeRenderer.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "../../include/core/GlobalConfig.h"

MazeRenderer::MazeRenderer(MazeReader &maze) : maze(maze) {
  const sf::Color wallColor = GLOBAL::RENDER::WALL_COLOR;
  const float wallThickness = GLOBAL::RENDER::WALL_THICKNESS;
  const float cellSize = GLOBAL::RENDER::CELL_SIZE;
  const float offsetX = GLOBAL::RENDER::OFFSET_X;
  const float offsetY = GLOBAL::RENDER::OFFSET_Y;

  horizontalWallShape.setSize(sf::Vector2f(cellSize, wallThickness));
  horizontalWallShape.setFillColor(wallColor);
  horizontalWallShape.setOrigin(-offsetX, -offsetY);

  verticalWallShape.setSize(sf::Vector2f(wallThickness, cellSize));
  verticalWallShape.setFillColor(wallColor);
  verticalWallShape.setOrigin(-offsetX, -offsetY);

  cellShape.setSize(sf::Vector2f(cellSize, cellSize));
  cellShape.setFillColor(GLOBAL::RENDER::START_COLOR);
  cellShape.setOrigin(-offsetX, -offsetY);
}

void MazeRenderer::draw(sf::RenderWindow &window) {
  for (int y = 0; y < maze.getHeight(); ++y) {
    for (int x = 0; x < maze.getWidth(); ++x) {
      Position cellPosition(x, y);
      CellType cellType = maze.getCellType(cellPosition);

      drawCellBackground(window, cellPosition, cellType);
      drawCellWalls(window, cellPosition);
    }
  }
}

void MazeRenderer::drawCellBackground(sf::RenderWindow &window, Position cellPosition, CellType cellType) {
  auto topLeftCornerPosX = getTopLeftCornerPositionX(cellPosition);
  auto topLeftCornerPosY = getTopLeftCornerPositionY(cellPosition);
  cellShape.setPosition(topLeftCornerPosX, topLeftCornerPosY);

  if (cellType == CellType::START) {
    cellShape.setFillColor(GLOBAL::RENDER::START_COLOR);
  } else if (cellType == CellType::GOAL) {
    cellShape.setFillColor(GLOBAL::RENDER::GOAL_COLOR);
  } else {
    return;
  }

  window.draw(cellShape);
}

void MazeRenderer::drawCellWalls(sf::RenderWindow &window, Position cellPosition) {
  auto wallThickness = GLOBAL::RENDER::WALL_THICKNESS;
  auto cellSize = GLOBAL::RENDER::CELL_SIZE;

  auto topLeftCornerPosX = getTopLeftCornerPositionX(cellPosition);
  auto topLeftCornerPosY = getTopLeftCornerPositionY(cellPosition);

  if (maze.isWall(cellPosition, Direction::NORTH)) {
    horizontalWallShape.setPosition(topLeftCornerPosX, topLeftCornerPosY);
    window.draw(horizontalWallShape);
  }
  if (maze.isWall(cellPosition, Direction::EAST)) {
    verticalWallShape.setPosition(topLeftCornerPosX + cellSize - wallThickness, topLeftCornerPosY);
    window.draw(verticalWallShape);
  }
  if (maze.isWall(cellPosition, Direction::SOUTH)) {
    horizontalWallShape.setPosition(topLeftCornerPosX, topLeftCornerPosY + cellSize - wallThickness);
    window.draw(horizontalWallShape);
  }
  if (maze.isWall(cellPosition, Direction::WEST)) {
    verticalWallShape.setPosition(topLeftCornerPosX, topLeftCornerPosY);
    window.draw(verticalWallShape);
  }
}

float MazeRenderer::getTopLeftCornerPositionX(Position cellPosition) {
  return (float) cellPosition.getX() * (GLOBAL::RENDER::CELL_SIZE - GLOBAL::RENDER::WALL_THICKNESS);
}
float MazeRenderer::getTopLeftCornerPositionY(Position cellPosition) {
  return (float) cellPosition.getY() * (GLOBAL::RENDER::CELL_SIZE - GLOBAL::RENDER::WALL_THICKNESS);
}