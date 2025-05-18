#include "../../include/core/maze/Maze.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "../../include/gui/MazeRenderer.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "../../include/core/GlobalConfig.h"

MazeRenderer::MazeRenderer(MazeReader &maze) : maze(maze) {
  const sf::Color wallColor = GLOBAL::COLORS::WALL_COLOR;
  constexpr float wallThickness = GLOBAL::RENDER::MAZE::WALL_THICKNESS;
  constexpr float cellSize = GLOBAL::RENDER::MAZE::CELL_SIZE;
  constexpr float offsetX = GLOBAL::RENDER::MAZE::MARGIN_LEFT;
  constexpr float offsetY = GLOBAL::RENDER::MAZE::MARGIN_TOP;

  horizontalWallShape.setSize(sf::Vector2f(cellSize, wallThickness));
  horizontalWallShape.setFillColor(wallColor);
  horizontalWallShape.setOrigin(-offsetX, -offsetY);

  verticalWallShape.setSize(sf::Vector2f(wallThickness, cellSize));
  verticalWallShape.setFillColor(wallColor);
  verticalWallShape.setOrigin(-offsetX, -offsetY);

  cellShape.setSize(sf::Vector2f(cellSize, cellSize));
  cellShape.setFillColor(GLOBAL::COLORS::START_COLOR);
  cellShape.setOrigin(-offsetX, -offsetY);
}

void MazeRenderer::draw(sf::RenderWindow &window) {
  colorCells(window);
  drawWalls(window);
}

void MazeRenderer::colorCells(sf::RenderWindow &window) {
  for (int y = 0; y < maze.getHeight(); ++y) {
    for (int x = 0; x < maze.getWidth(); ++x) {
      const Position cellPosition(x, y);
      const CellType cellType = maze.getCellType(cellPosition);
      drawCellBackground(window, cellPosition, cellType);
    }
  }
}

void MazeRenderer::drawWalls(sf::RenderWindow &window) {
  for (int y = 0; y < maze.getHeight(); ++y) {
    for (int x = 0; x < maze.getWidth(); ++x) {
      const Position cellPosition(x, y);
      drawCellWalls(window, cellPosition);
    }
  }
}

void MazeRenderer::drawCellBackground(sf::RenderWindow &window, const Position cellPosition, const CellType cellType) {
  const auto topLeftCornerPosX = getTopLeftCornerPositionX(cellPosition);
  const auto topLeftCornerPosY = getTopLeftCornerPositionY(cellPosition);
  cellShape.setPosition(topLeftCornerPosX, topLeftCornerPosY);

  if (cellType == CellType::START) {
    cellShape.setFillColor(GLOBAL::COLORS::START_COLOR);
  } else if (cellType == CellType::GOAL) {
    cellShape.setFillColor(GLOBAL::COLORS::GOAL_COLOR);
  } else {
    return;
  }

  window.draw(cellShape);
}

void MazeRenderer::drawCellWalls(sf::RenderWindow &window, const Position cellPosition) {
  constexpr auto wallThickness = GLOBAL::RENDER::MAZE::WALL_THICKNESS;
  constexpr auto cellSize = GLOBAL::RENDER::MAZE::CELL_SIZE;

  const auto topLeftCornerPosX = getTopLeftCornerPositionX(cellPosition);
  const auto topLeftCornerPosY = getTopLeftCornerPositionY(cellPosition);

  if (maze.isWall(cellPosition, NORTH)) {
    horizontalWallShape.setPosition(topLeftCornerPosX, topLeftCornerPosY);
    window.draw(horizontalWallShape);
  }
  if (maze.isWall(cellPosition, EAST)) {
    verticalWallShape.setPosition(topLeftCornerPosX + cellSize - wallThickness, topLeftCornerPosY);
    window.draw(verticalWallShape);
  }
  if (maze.isWall(cellPosition, SOUTH)) {
    horizontalWallShape.setPosition(topLeftCornerPosX, topLeftCornerPosY + cellSize - wallThickness);
    window.draw(horizontalWallShape);
  }
  if (maze.isWall(cellPosition, WEST)) {
    verticalWallShape.setPosition(topLeftCornerPosX, topLeftCornerPosY);
    window.draw(verticalWallShape);
  }
}

float MazeRenderer::getTopLeftCornerPositionX(const Position cellPosition) {
  return static_cast<float>(cellPosition.getX()) * (
           GLOBAL::RENDER::MAZE::CELL_SIZE - GLOBAL::RENDER::MAZE::WALL_THICKNESS);
}

float MazeRenderer::getTopLeftCornerPositionY(const Position cellPosition) {
  return static_cast<float>(cellPosition.getY()) * (
           GLOBAL::RENDER::MAZE::CELL_SIZE - GLOBAL::RENDER::MAZE::WALL_THICKNESS);
}
