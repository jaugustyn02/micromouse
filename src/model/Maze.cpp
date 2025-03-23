#include <stack>
#include "../../include/model/Cell.h"
#include "../../include/model/Maze.h"
#include "../../include/utils/Randomizer.h"

Maze::Maze(int width, int height) : width(width), height(height) {
  initializeGrid();
}

void Maze::generate() {
  resetGrid();

  for (int i = 0; i < width; ++i) {
    for (int j = 0; j < height; ++j) {
      grid[j][i].topWall = Randomizer::GetRandomBool();
      grid[j][i].rightWall = Randomizer::GetRandomBool();
      grid[j][i].bottomWall = Randomizer::GetRandomBool();
      grid[j][i].leftWall = Randomizer::GetRandomBool();
    }
  }
}

Cell &Maze::getCell(int x, int y) const {
  return const_cast<Cell &>(grid[y][x]);
}

void Maze::initializeGrid() {
  grid.reserve(height);

  for (int y = 0; y < height; ++y) {
    std::vector<Cell> row;
    row.reserve(width);
    for (int x = 0; x < width; ++x) {
      row.emplace_back(x, y);
    }
    grid.push_back(std::move(row));
  }
}

void Maze::resetGrid() {
  for (int i = 0; i < width; ++i) {
    for (int j = 0; j < height; ++j) {
      grid[j][i].topWall = true;
      grid[j][i].rightWall = true;
      grid[j][i].bottomWall = true;
      grid[j][i].leftWall = true;
      grid[j][i].visited = false;
    }
  }
}