#include <stack>
#include "../../include/model/Cell.h"
#include "../../include/model/Maze.h"
#include "../../include/utils/Randomizer.h"

Maze::Maze(int width, int height) : width(width), height(height) {
  initializeGrid();
}

void Maze::generate() {
  resetGrid();

  std::stack<Cell *> stack;
  Cell *currentCell = &grid[0][0];
  currentCell->visited = true;
  stack.push(currentCell);

  while (!stack.empty()) {
    std::vector<Cell *> neighbors;
    int x = currentCell->x;
    int y = currentCell->y;

    if (x > 0 && !grid[y][x - 1].visited) {
      neighbors.push_back(&grid[y][x - 1]);
    }
    if (y > 0 && !grid[y - 1][x].visited) {
      neighbors.push_back(&grid[y - 1][x]);
    }
    if (x < width - 1 && !grid[y][x + 1].visited) {
      neighbors.push_back(&grid[y][x + 1]);
    }
    if (y < height - 1 && !grid[y + 1][x].visited) {
      neighbors.push_back(&grid[y + 1][x]);
    }

    if (!neighbors.empty()) {
      Cell *nextCell = neighbors[Randomizer::GetRandom(0, (int) neighbors.size() - 1)];
      stack.push(nextCell);

      if (nextCell->x < currentCell->x) {
        currentCell->leftWall = false;
        nextCell->rightWall = false;
      } else if (nextCell->x > currentCell->x) {
        currentCell->rightWall = false;
        nextCell->leftWall = false;
      } else if (nextCell->y < currentCell->y) {
        currentCell->topWall = false;
        nextCell->bottomWall = false;
      } else if (nextCell->y > currentCell->y) {
        currentCell->bottomWall = false;
        nextCell->topWall = false;
      }

      currentCell = nextCell;
      currentCell->visited = true;
    } else {
      currentCell = stack.top();
      stack.pop();
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