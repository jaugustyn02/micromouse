#include <stack>
#include "core/maze/Maze.h"
#include "core/GlobalConfig.h"
#include "utils/Randomizer.h"

Maze::Maze(const int columns, const int rows) : columns(columns), rows(rows) {
  initializeGrid();
}

void Maze::generate() {
  std::cout << "[Maze]: Generating new maze" << std::endl;

  resetGrid();

  std::stack<Position> stack;
  std::set<Position> visited;

  stack.push(start);
  visited.insert(start);

  setStart();
  setGoal(visited);

  while (!stack.empty()) {
    auto currentPosition = stack.top();
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

  removeRandomWalls(GLOBAL::MAZE::REMOVED_WALLS);
}

void Maze::resetGrid() {
  for (int i = 0; i < columns; ++i) {
    for (int j = 0; j < rows; ++j) {
      for (const auto direction : GLOBAL::CONSTANTS::DIRECTIONS) {
        grid[j][i].addWall(direction);
      }
    }
  }
}

void Maze::initializeGrid() {
  grid.reserve(rows);
  auto type = CellType::PATH;

  for (int y = 0; y < rows; ++y) {
    std::vector<Cell> row;
    row.reserve(columns);
    for (int x = 0; x < columns; ++x) {
      Position position(x, y);
      row.emplace_back(position, type);
    }
    grid.push_back(std::move(row));
  }
}

void Maze::removeRandomWalls(int numOfWalls) {
  while (numOfWalls--) {
    while (true) {
      Cell &cell = getRandomCell();
      auto removableWalls = getCellRemovableWalls(cell);
      if (cell.getType() != CellType::GOAL && !removableWalls.empty()) {
        const auto removeWallInDirection = Randomizer::GetRandomElement(removableWalls);
        auto neighbourCellPosition = cell.getLocation().translated(removeWallInDirection);
        removeWallsBetweenNeighbourCells(cell.getLocation(), neighbourCellPosition);
        break;
      }
    }
  }
}

std::vector<Direction> Maze::getCellRemovableWalls(const Cell &cell) const {
  std::vector<Direction> walls;
  const auto position = Position(cell.getLocation());
  for (auto direction : GLOBAL::CONSTANTS::DIRECTIONS) {
    if (cell.hasWall(direction) && !isEdgeWall(position, direction) && !isGoalWall(position, direction)) {
      walls.push_back(direction);
    }
  }
  return walls;
}

bool Maze::isGoalWall(const Position position, const Direction direction) const {
  const auto translatedPosition = position.translated(direction);
  if (translatedPosition.isOutOfBounds(columns, rows)) {
    return false;
  }
  const auto neighbourCell = grid[translatedPosition.getY()][translatedPosition.getX()];
  return neighbourCell.getType() == CellType::GOAL;
}

bool Maze::isEdgeWall(const Position position, const Direction direction) const {
  const auto translatedPosition = position.translated(direction);
  return translatedPosition.isOutOfBounds(columns, rows);
}

Cell &Maze::getRandomCell() {
  auto &randomRow = Randomizer::GetRandomElement(grid);
  return Randomizer::GetRandomElement(randomRow);
}

void Maze::setStart() {
  grid[start.getY()][start.getX()].setType(CellType::START);
}

void Maze::setGoal(std::set<Position> &visited) {
  Cell &northwestCell = getCell(GLOBAL::MAZE::NORTHWEST_GOAL);
  Cell &southwestCell = getCell(GLOBAL::MAZE::SOUTHWEST_GOAL);
  Cell &northeastCell = getCell(GLOBAL::MAZE::NORTHEAST_GOAL);
  Cell &southeastCell = getCell(GLOBAL::MAZE::SOUTHEAST_GOAL);
  std::vector goalCells({&northwestCell, &southwestCell, &northeastCell, &southeastCell});

  for (const auto cell : goalCells) {
    cell->setType(CellType::GOAL);
    visited.insert(cell->getLocation());
  }

  northwestCell.removeWall(SOUTH);
  northwestCell.removeWall(EAST);

  southwestCell.removeWall(NORTH);
  southwestCell.removeWall(EAST);

  northeastCell.removeWall(SOUTH);
  northeastCell.removeWall(WEST);

  southeastCell.removeWall(NORTH);
  southeastCell.removeWall(WEST);

  setRandomGoalEntrance(goalCells);
}

Cell &Maze::getCell(Position position) {
  return grid[position.getY()][position.getX()];
}

void Maze::setRandomGoalEntrance(std::vector<Cell *> goalCells) {
  const auto entryCell = Randomizer::GetRandomElement(goalCells);
  auto removableWalls = getCellRemovableWalls(*entryCell);
  const auto removeWallInDirection = Randomizer::GetRandomElement(removableWalls);
  const auto neighbourCellPosition = entryCell->getLocation().translated(removeWallInDirection);
  removeWallsBetweenNeighbourCells(entryCell->getLocation(), neighbourCellPosition);
}

void Maze::removeWallsBetweenNeighbourCells(const Position &firstPosition, const Position &secondPosition) {
  auto &firstCell = grid[firstPosition.getY()][firstPosition.getX()];
  auto &secondCell = grid[secondPosition.getY()][secondPosition.getX()];
  const int xDiff = secondPosition.getX() - firstPosition.getX();
  const int yDiff = secondPosition.getY() - firstPosition.getY();

  if (xDiff == 1) {
    firstCell.removeWall(EAST);
    secondCell.removeWall(WEST);
  } else if (xDiff == -1) {
    firstCell.removeWall(WEST);
    secondCell.removeWall(EAST);
  } else if (yDiff == 1) {
    firstCell.removeWall(SOUTH);
    secondCell.removeWall(NORTH);
  } else if (yDiff == -1) {
    firstCell.removeWall(NORTH);
    secondCell.removeWall(SOUTH);
  }
}

std::vector<Position> Maze::getUnvisitedNeighbors(const Position &position, const std::set<Position> &visited) const {
  const auto neighbors = position.getNeighborCellPositions(columns, rows);
  std::vector<Position> unvisitedNeighbors;
  for (const auto &neighbor : neighbors) {
    if (visited.find(neighbor) == visited.end()) {
      unvisitedNeighbors.push_back(neighbor);
    }
  }
  return unvisitedNeighbors;
}
