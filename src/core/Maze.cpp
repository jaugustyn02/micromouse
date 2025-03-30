

#include <stack>
#include "../../include/core/Maze.h"
#include "../../include/utils/Randomizer.h"

Maze::Maze(int width, int height) : width(width), height(height) {
  initializeGrid();
}

std::vector<Position> Maze::getCellNeighbors(const Position &position) const {
  std::vector<Position> neighbors;
  neighbors.reserve(4);

  int x = position.getX();
  int y = position.getY();

  if (x > 0) {
    neighbors.emplace_back(x - 1, y);
  }
  if (y > 0) {
    neighbors.emplace_back(x, y - 1);
  }
  if (x < width - 1) {
    neighbors.emplace_back(x + 1, y);
  }
  if (y < height - 1) {
    neighbors.emplace_back(x, y + 1);
  }

  return neighbors;
}

std::vector<Position> Maze::getUnvisitedNeighbors(const Position &position, const std::set<Position> &visited) const {
  std::vector<Position> neighbors = getCellNeighbors(position);
  std::vector<Position> unvisitedNeighbors;
  for (const auto &neighbor : neighbors) {
    if (visited.find(neighbor) == visited.end()) {
      unvisitedNeighbors.push_back(neighbor);
    }
  }
  return unvisitedNeighbors;
}

void Maze::removeWallsBetweenNeighbourCells(const Position &firstPosition, const Position &secondPosition) {
  auto &firstCell = grid[firstPosition.getY()][firstPosition.getX()];
  auto &secondCell = grid[secondPosition.getY()][secondPosition.getX()];
  int xDiff = secondPosition.getX() - firstPosition.getX();
  int yDiff = secondPosition.getY() - firstPosition.getY();

  if (xDiff == 1) {
    firstCell.removeWall(Direction::EAST);
    secondCell.removeWall(Direction::WEST);
  } else if (xDiff == -1) {
    firstCell.removeWall(Direction::WEST);
    secondCell.removeWall(Direction::EAST);
  } else if (yDiff == 1) {
    firstCell.removeWall(Direction::SOUTH);
    secondCell.removeWall(Direction::NORTH);
  } else if (yDiff == -1) {
    firstCell.removeWall(Direction::NORTH);
    secondCell.removeWall(Direction::SOUTH);
  }
}

void Maze::generate() {
  resetGrid();

  std::stack<Position> stack;
  std::set<Position> visited;

  auto currentPosition = Position(0, 0);
  stack.push(currentPosition);
  visited.insert(currentPosition);

  while (!stack.empty()) {
    currentPosition = stack.top();
    auto unvisitedNeighbors = getUnvisitedNeighbors(currentPosition, visited);
    if (unvisitedNeighbors.empty()) {
      stack.pop();
      continue;
    }

    auto nextPosition = Randomizer::GetRandomElement(unvisitedNeighbors);
    removeWallsBetweenNeighbourCells(currentPosition, nextPosition);

    stack.push(nextPosition);
    visited.insert(nextPosition);
  }
}

void Maze::initializeGrid() {
  grid.reserve(height);
  CellType type = CellType::PATH;

  for (int y = 0; y < height; ++y) {
    std::vector<Cell> row;
    row.reserve(width);
    for (int x = 0; x < width; ++x) {
      Position position(x, y);
      row.emplace_back(position, type);
    }
    grid.push_back(std::move(row));
  }
}

void Maze::resetGrid() {
  for (int i = 0; i < width; ++i) {
    for (int j = 0; j < height; ++j) {
      grid[j][i].addWall(Direction::NORTH);
      grid[j][i].addWall(Direction::EAST);
      grid[j][i].addWall(Direction::SOUTH);
      grid[j][i].addWall(Direction::WEST);
    }
  }
}

int Maze::getWidth() const {
  return width;
}
int Maze::getHeight() const {
  return height;
}

bool Maze::isWall(Position position, Direction direction) const {
  return grid[position.getY()][position.getX()].hasWall(direction);
}

CellType Maze::getCellType(Position position) const {
  return grid[position.getY()][position.getX()].getType();
}
