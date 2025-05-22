#ifndef MICROMOUSE_INCLUDE_CORE_MAZEREADER_H_
#define MICROMOUSE_INCLUDE_CORE_MAZEREADER_H_

#include "model/Cell.h"

/**
 * @class MazeReader
 * @brief Interface for reading maze cell and wall data.
 *
 * This abstract class defines a contract for accessing the structure of a maze,
 * including wall presence, cell types, and maze dimensions.
 */
class MazeReader {
 public:
  /**
   * @brief Default constructor.
   */
  virtual ~MazeReader() = default;

  /**
   * @brief Checks if there is a wall in the given direction from a specific position.
   * @param position The position in the maze.
   * @param direction The direction from the given position.
   * @return true if a wall exists, false otherwise.
   */
  virtual bool isWall(Position position, Direction direction) const = 0;

  /**
   * @brief Returns the type of cell at the specified position.
   * @param position The position of the cell.
   * @return The cell type (e.g., START, GOAL, PATH).
   */
  virtual CellType getCellType(Position position) const = 0;

  /**
   * @brief Returns the number of columns of the maze.
   * @return The number of columns.
   */
  virtual int getNumOfColumns() const = 0;

  /**
   * @brief Returns the number of rows of the maze.
   * @return The number of rows.
   */
  virtual int getNumOfRows() const = 0;
};

#endif //MICROMOUSE_INCLUDE_CORE_MAZEREADER_H_
