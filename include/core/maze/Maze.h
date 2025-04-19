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

    bool isWall(const Position position, const Direction direction) const override {
        return grid[position.getY()][position.getX()].hasWall(direction);
    };

    CellType getCellType(const Position position) const override {
        return grid[position.getY()][position.getX()].getType();
    };
    int getWidth() const override { return width; };
    int getHeight() const override { return height; };

private:
    const int width;
    const int height;
    const Position start = Position(GLOBAL::SIMULATION::START_POSITION_X, GLOBAL::SIMULATION::START_POSITION_Y);
    const Position northwestCenter = Position(GLOBAL::SIMULATION::MAZE_WIDTH / 2 - 1,
                                              GLOBAL::SIMULATION::MAZE_HEIGHT / 2 - 1);
    std::vector<std::vector<Cell> > grid;

    void initializeGrid();

    void removeRandomWalls(int numOfWalls);

    std::vector<Direction> getCellRemovableWalls(const Cell &cell) const;

    bool isGoalWall(Position position, Direction direction) const;

    bool isOutOfBounds(Position position) const;

    bool isEdgeWall(Position position, Direction direction) const;

    Cell &getRandomCell();

    void resetGrid();

    std::vector<Position> getCellNeighbors(const Position &position) const;

    std::vector<Position> getUnvisitedNeighbors(const Position &position, const std::set<Position> &visited) const;

    void removeWallsBetweenNeighbourCells(const Position &firstPosition, const Position &secondPosition);

    void setGoal(std::set<Position> &visited);

    void setStart();
};

#endif //MICROMOUSE_INCLUDE_GUI_MAZE_H_
