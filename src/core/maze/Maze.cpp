#include <stack>
#include "../../../include/core/maze/Maze.h"
#include "../../../include/utils/Randomizer.h"
#include "../../../include/core/GlobalConfig.h"

Maze::Maze(const int width, const int height) : width(width), height(height) {
    initializeGrid();
}

void Maze::generate() {
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

    removeRandomWalls(GLOBAL::SIMULATION::REMOVED_WALLS);
}

void Maze::resetGrid() {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            for (const auto direction: GLOBAL::CONSTANTS::DIRECTIONS) {
                grid[j][i].addWall(direction);
            }
        }
    }
}

void Maze::initializeGrid() {
    grid.reserve(height);
    auto type = CellType::PATH;

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
    for (auto direction: GLOBAL::CONSTANTS::DIRECTIONS) {
        if (cell.hasWall(direction) && !isEdgeWall(position, direction) && !isGoalWall(position, direction)) {
            walls.push_back(direction);
        }
    }
    return walls;
}

bool Maze::isGoalWall(const Position position, const Direction direction) const {
    const auto translatedPosition = position.translated(direction);
    if (translatedPosition.isOutOfBounds(width, height)) {
        return false;
    }
    const auto neighbourCell = grid[translatedPosition.getY()][translatedPosition.getX()];
    return neighbourCell.getType() == CellType::GOAL;
}

bool Maze::isEdgeWall(const Position position, const Direction direction) const {
    const auto translatedPosition = position.translated(direction);
    return translatedPosition.isOutOfBounds(width, height);
}

Cell &Maze::getRandomCell() {
    auto &randomRow = Randomizer::GetRandomElement(grid);
    return Randomizer::GetRandomElement(randomRow);
}

void Maze::setStart() {
    grid[start.getY()][start.getX()].setType(CellType::START);
}

void Maze::setGoal(std::set<Position> &visited) {
    Cell &northwestCell = grid[northwestCenter.getY()][northwestCenter.getX()];
    Cell &southwestCell = grid[northwestCenter.getY() + 1][northwestCenter.getX()];
    Cell &northeastCell = grid[northwestCenter.getY()][northwestCenter.getX() + 1];
    Cell &southeastCell = grid[northwestCenter.getY() + 1][northwestCenter.getX() + 1];
    std::vector goalCells({&northwestCell, &southwestCell, &northeastCell, &southeastCell});

    for (const auto cell: goalCells) {
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
    const auto neighbors = position.getNeighborCellPositions(width, height);
    std::vector<Position> unvisitedNeighbors;
    for (const auto &neighbor: neighbors) {
        if (visited.find(neighbor) == visited.end()) {
            unvisitedNeighbors.push_back(neighbor);
        }
    }
    return unvisitedNeighbors;
}
