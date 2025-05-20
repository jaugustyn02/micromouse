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
  const int columns; ///< Number of columns in the maze.
  const int rows; ///< Number of rows in the maze.
  const Position start = GLOBAL::MAZE::START_POSITION; ///< Starting position of the maze.
  std::vector<std::vector<Cell> > grid; ///< 2D vector representing the maze grid.

  /**
   * @brief Initializes the grid with default cell types and walls.
   */
  void initializeGrid();

  /**
   * @brief Resets all walls in the grid to the default state (all walls present).
   */
  void resetGrid();

  /**
   * @brief Removes random walls from the maze.
   * @param numOfWalls Number of walls to remove.
   */
  void removeRandomWalls(int numOfWalls);

  /**
   * @brief Returns the removable wall directions for a given cell.
   * @param cell The cell to evaluate.
   * @return A list of removable directions.
   */
  [[nodiscard]] std::vector<Direction> getCellRemovableWalls(const Cell &cell) const;

  /**
   * @brief Checks if the specified wall is a goal wall.
   * @param position The cell position.
   * @param direction The wall direction.
   * @return true if it is part of a goal cell boundary.
   */
  [[nodiscard]] bool isGoalWall(Position position, Direction direction) const;

  /**
   * @brief Checks if the specified wall is on the maze edge.
   * @param position The cell position.
   * @param direction The wall direction.
   * @return true if it is on the edge of the maze.
   */
  [[nodiscard]] bool isEdgeWall(Position position, Direction direction) const;

  /**
   * @brief Returns a reference to a randomly selected cell.
   * @return Reference to a random Cell object.
   */
  Cell &getRandomCell();

  /**
   * @brief Finds all unvisited neighbor positions from a given cell.
   * @param position The cell position.
   * @param visited A set of already visited positions.
   * @return A list of unvisited neighboring positions.
   */
  [[nodiscard]] std::vector<Position> getUnvisitedNeighbors(const Position &position,
                                                            const std::set<Position> &visited) const;

  /**
   * @brief Removes walls between two neighboring cells.
   * @param firstPosition First cell position.
   * @param secondPosition Second cell position.
   */
  void removeWallsBetweenNeighbourCells(const Position &firstPosition, const Position &secondPosition);

  /**
   * @brief Sets goal area in the maze.
   * @param visited A set of already visited positions.
   */
  void setGoal(std::set<Position> &visited);

  /**
   * @brief Removes random wall to create an entrance to the goal area.
   * @param goalCells A list of pointers to goal cell objects.
   */
  void setRandomGoalEntrance(std::vector<Cell *> goalCells);

  /**
   * @brief Marks the start cell in the maze.
   */
  void setStart();

  /**
   * @brief Returns a reference to the cell at the given position.
   * @param position The target position.
   * @return Reference to the corresponding Cell.
   */
  Cell &getCell(Position position);
};

#endif //MICROMOUSE_INCLUDE_GUI_MAZE_H_
