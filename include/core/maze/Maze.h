#ifndef MICROMOUSE_INCLUDE_GUI_MAZE_H_
#define MICROMOUSE_INCLUDE_GUI_MAZE_H_

#include <vector>
#include "MazeReader.h"
#include <set>

#include "../GlobalConfig.h"

class Maze final : public MazeReader {
public:
    Maze(int width, int height);

    void generate();

    [[nodiscard]] bool isWall(const Position position, const Direction direction) const override {
        return grid[position.getY()][position.getX()].hasWall(direction);
    };

    [[nodiscard]] CellType getCellType(const Position position) const override {
        return grid[position.getY()][position.getX()].getType();
    };

    [[nodiscard]] int getWidth() const override { return width; };

    [[nodiscard]] int getHeight() const override { return height; };

private:
    const int width;
    const int height;
    const Position start = GLOBAL::MAZE::START_POSITION;
    std::vector<std::vector<Cell> > grid;

    void initializeGrid();

    void removeRandomWalls(int numOfWalls);

    [[nodiscard]] std::vector<Direction> getCellRemovableWalls(const Cell &cell) const;

    [[nodiscard]] bool isGoalWall(Position position, Direction direction) const;

    [[nodiscard]] bool isEdgeWall(Position position, Direction direction) const;

    Cell &getRandomCell();

    void resetGrid();

    [[nodiscard]] std::vector<Position> getUnvisitedNeighbors(const Position &position,
                                                              const std::set<Position> &visited) const;

    void removeWallsBetweenNeighbourCells(const Position &firstPosition, const Position &secondPosition);

    void setGoal(std::set<Position> &visited);

    void setRandomGoalEntrance(std::vector<Cell *> goalCells);

    void setStart();

    Cell &getCell(Position position);
};

#endif //MICROMOUSE_INCLUDE_GUI_MAZE_H_
