#ifndef MICROMOUSE_INCLUDE_GUI_CELL_H_
#define MICROMOUSE_INCLUDE_GUI_CELL_H_

#include "Direction.h"
#include "Position.h"
#include "CellType.h"
#include <map>

/**
 * @brief The Cell class represents a cell in the maze.
 * It contains information about the cell's location, type, and walls.
 */
class Cell {
 public:
  /**
   * @brief Constructor for the Cell class.
   * @param location The position of the cell in the maze.
   * @param type The type of the cell (e.g., empty, wall, etc.).
   */
  Cell(Position location, CellType type);

  /**
   * @brief Destructor for the Cell class.
   */
  void addWall(Direction direction);

  /**
   * @brief Removes a wall in the specified direction.
   * @param direction The direction to remove the wall.
   */
  void removeWall(Direction direction);

  /**
   * @brief Checks if there is a wall in the specified direction.
   * @param direction The direction to check for a wall.
   * @return True if there is a wall, false otherwise.
   */
  [[nodiscard]]
  bool hasWall(Direction direction) const;

  /**
   * @brief Checks if the cell is a wall.
   * @return True if the cell is a wall, false otherwise.
   */
  [[nodiscard]]
  Position getLocation() const;

  /**
   * @brief Gets the type of the cell.
   * @return The type of the cell.
   */
  [[nodiscard]]
  CellType getType() const;
  void setType(CellType type);

 private:
  std::map<Direction, bool> walls{{
                                      {Direction::NORTH, false},
                                      {Direction::EAST, false},
                                      {Direction::SOUTH, false},
                                      {Direction::WEST, false}
                                  }};
  Position location;
  CellType type;
};

#endif //MICROMOUSE_INCLUDE_GUI_CELL_H_
