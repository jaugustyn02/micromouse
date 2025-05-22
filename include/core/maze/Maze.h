#ifndef MICROMOUSE_INCLUDE_GUI_MAZE_H_
#define MICROMOUSE_INCLUDE_GUI_MAZE_H_

#include <vector>
#include "MazeReader.h"
#include <set>

#include "core/GlobalConfig.h"

/**
 * @class Maze
 * @brief Represents a 2D maze used in the micromouse simulation.
 *
 * Inherits from MazeReader and implements maze generation, wall management,
 * and cell state tracking. The maze consists of a grid of Cell objects.
 */
class Maze final : public MazeReader {
 public:
  /**
   * @brief Constructs a Maze with the given dimensions.
   * @param columns Number of columns in the maze.
   * @param rows Number of rows in the maze.
   */
  Maze(int columns, int rows);

  /**
  * @brief Generates a new random maze layout.
  */
  void generate();

  /// @copydoc MazeReader::isWall
  [[nodiscard]] bool isWall(const Position position, const Direction direction) const override {
    return grid[position.getY()][position.getX()].hasWall(direction);
  };

  /// @copydoc MazeReader::getCellType
  [[nodiscard]] CellType getCellType(const Position position) const override {
    return grid[position.getY()][position.getX()].getType();
  };

  /// @copydoc MazeReader::getNumOfColumns
  [[nodiscard]] int getNumOfColumns() const override { return columns; };

  /// @copydoc MazeReader::getNumOfRows
  [[nodiscard]] int getNumOfRows() const override { return rows; };

 private:
  const int columns;
  const int rows;
  const Position start = GLOBAL::MAZE::START_POSITION;
  std::vector<std::vector<Cell> > grid;

  void initializeGrid();

  void resetGrid();

  void removeRandomWalls(int numOfWalls);

  [[nodiscard]] std::vector<Direction> getCellRemovableWalls(const Cell &cell) const;

  [[nodiscard]] bool isGoalWall(Position position, Direction direction) const;

  [[nodiscard]] bool isEdgeWall(Position position, Direction direction) const;

  Cell &getRandomCell();

  [[nodiscard]] std::vector<Position> getUnvisitedNeighbors(const Position &position,
                                                            const std::set<Position> &visited) const;
  void removeWallsBetweenNeighbourCells(const Position &firstPosition, const Position &secondPosition);

  void setGoal(std::set<Position> &visited);

  void setRandomGoalEntrance(std::vector<Cell *> goalCells);

  void setStart();

  Cell &getCell(Position position);
};

#endif //MICROMOUSE_INCLUDE_GUI_MAZE_H_
