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

    auto currentPosition = Position(GLOBAL::SIMULATION::START_POSITION_X,
                                    GLOBAL::SIMULATION::START_POSITION_Y);
    stack.push(currentPosition);
    visited.insert(currentPosition);

    setStart();
    setGoal(visited);

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

    removeRandomWalls(GLOBAL::SIMULATION::REMOVED_WALLS);
}

void Maze::resetGrid() {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            grid[j][i].addWall(NORTH);
            grid[j][i].addWall(EAST);
            grid[j][i].addWall(SOUTH);
            grid[j][i].addWall(WEST);
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
    if (isOutOfBounds(translatedPosition)) {
        return false;
    }
    const auto neighbourCell = grid[translatedPosition.getY()][translatedPosition.getX()];
    return neighbourCell.getType() == CellType::GOAL;
}

bool Maze::isEdgeWall(const Position position, const Direction direction) const {
    const auto translatedPosition = position.translated(direction);
    return isOutOfBounds(translatedPosition);
}

bool Maze::isOutOfBounds(const Position position) const {
    return (position.getX() < 0) || (position.getX() >= width) || (position.getY() < 0) || (position.getY() >= height);
}

Cell &Maze::getRandomCell() {
    auto &randomRow = Randomizer::GetRandomElement(grid);
    return Randomizer::GetRandomElement(randomRow);
}

void Maze::setStart() {
    grid[0][0].setType(CellType::START);
}

void Maze::setGoal(std::set<Position> &visited) {
    Cell &leftUpperCell = grid[northeastCenter.getY()][northeastCenter.getX()];
    Cell &leftLowerCell = grid[northeastCenter.getY() + 1][northeastCenter.getX()];
    Cell &rightUpperCell = grid[northeastCenter.getY()][northeastCenter.getX() + 1];
    Cell &rightLowerCell = grid[northeastCenter.getY() + 1][northeastCenter.getX() + 1];

    leftLowerCell.setType(CellType::GOAL);
    leftUpperCell.setType(CellType::GOAL);
    rightLowerCell.setType(CellType::GOAL);
    rightUpperCell.setType(CellType::GOAL);

    leftLowerCell.removeWall(NORTH);
    leftLowerCell.removeWall(EAST);
    leftUpperCell.removeWall(SOUTH);
    leftUpperCell.removeWall(EAST);

    rightUpperCell.removeWall(SOUTH);
    rightUpperCell.removeWall(WEST);
    rightLowerCell.removeWall(NORTH);
    rightLowerCell.removeWall(WEST);
    rightLowerCell.removeWall(EAST);

    grid[northeastCenter.getY() + 1][northeastCenter.getX() + 2].removeWall(WEST);

    visited.insert(leftLowerCell.getLocation());
    visited.insert(leftUpperCell.getLocation());
    visited.insert(rightLowerCell.getLocation());
    visited.insert(rightUpperCell.getLocation());
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
    const std::vector<Position> neighbors = getCellNeighbors(position);
    std::vector<Position> unvisitedNeighbors;
    for (const auto &neighbor: neighbors) {
        if (visited.find(neighbor) == visited.end()) {
            unvisitedNeighbors.push_back(neighbor);
        }
    }
    return unvisitedNeighbors;
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
