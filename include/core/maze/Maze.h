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
	const Position start = GLOBAL::SIMULATION::START_POSITION;
    std::vector<std::vector<Cell> > grid;

    void initializeGrid();

    void removeRandomWalls(int numOfWalls);

    std::vector<Direction> getCellRemovableWalls(const Cell &cell) const;

    bool isGoalWall(Position position, Direction direction) const;

    bool isOutOfBounds(Position position) const;

    bool isEdgeWall(Position position, Direction direction) const;

    Cell &getRandomCell();

    void resetGrid();

    std::vector<Position> getUnvisitedNeighbors(const Position &position, const std::set<Position> &visited) const;

    void removeWallsBetweenNeighbourCells(const Position &firstPosition, const Position &secondPosition);

    void setGoal(std::set<Position> &visited);

    void setRandomGoalEntrance(std::vector<Cell *> goalCells);

    void setStart();

    Cell& getCell(Position position);
};

#endif //MICROMOUSE_INCLUDE_GUI_MAZE_H_
