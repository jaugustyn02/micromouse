#ifndef MICROMOUSE_INCLUDE_MODEL_POSITION_H_
#define MICROMOUSE_INCLUDE_MODEL_POSITION_H_

#include <iostream>
#include "Direction.h"
#include <vector>

/**
 * @brief The Position class represents a position in a 2D grid.
 * It is used to indicate the position of the micromouse in the maze.
 */
class Position {
 public:
  /**
   * @brief Default constructor for Position.
   * @param x The x-coordinate of the position.
   * @param y The y-coordinate of the position.
   */
  Position(const int x, const int y) : x(x), y(y) {
  }

  /**
   * @brief Default copy constructor for Position.
   * Initializes the position to the same values as the given position.
   * @param position The position to copy.
   */
  Position(const Position &position) = default;

  /**
   * @brief Translates the position in the given direction.
   * This modifies the current position.
   * @param direction The direction to translate the position.
   */
  void translate(Direction direction);

  /**
   * @brief Gets a new position translated in the given direction.
   * @param direction The direction to translate the position.
   * @return A new Position object representing the translated position.
   */
  [[nodiscard]]
  Position translated(Direction direction) const;

  /**
   * @brief Gets the neighboring cell positions based on the current position and grid bounds.
   * @param gridWidth The width of the grid.
   * @param gridHeight The height of the grid.
   * @return A vector of Position objects representing the neighboring cell positions.
   */
  [[nodiscard]] std::vector<Position> getNeighborCellPositions(int gridWidth, int gridHeight) const;

  /**
   * @brief Gets the direction to the neighboring position.
   * @param destination The destination position.
   * @return The direction to the neighboring position.
   */
  [[nodiscard]] Direction getDirectionToNeighbourPosition(Position destination) const;

  /**
   * @brief Less than operator for comparing two positions.
   * Necessary for using Position in STL containers.
   * @param other The other position to compare with.
   * @return True if the current position is less than the other position, false otherwise.
   */
  bool operator<(const Position &other) const {
    return (x == other.x) ? (y < other.y) : (x < other.x);
  }

  /**
   * @brief Equality operator for comparing two positions.
   * Necessary for using Position in STL containers.
   * @param other The other position to compare with.
   * @return True if the current position is equal to the other position, false otherwise.
   */
  [[nodiscard]]
  bool operator==(const Position &other) const {
    return x == other.x && y == other.y;
  }

  /**
   * @brief Inequality operator for comparing two positions.
   * Necessary for using Position in STL containers.
   * @param other The other position to compare with.
   * @return True if the current position is not equal to the other position, false otherwise.
   */
  [[nodiscard]]
  bool operator!=(const Position &start) const {
    return !(*this == start);
  }

  /**
   * @brief Gets the x-coordinate of the position.
   * @return The x-coordinate of the position.
   */
  [[nodiscard]]
  int getX() const { return x; }

  /**
   * @brief Gets the y-coordinate of the position.
   * @return The y-coordinate of the position.
   */
  [[nodiscard]]
  int getY() const { return y; }

  /**
   * @brief Checks if the position is out of bounds based on the grid dimensions.
   * @param gridWidth The width of the grid.
   * @param gridHeight The height of the grid.
   * @return True if the position is out of bounds, false otherwise.
   */
  [[nodiscard]]
  bool isOutOfBounds(const int gridWidth, const int gridHeight) const {
    return x < 0 || x >= gridWidth || y < 0 || y >= gridHeight;
  }

  /**
   * @brief Converts the position to a string representation.
   * @return A string representation of the position.
   */
  [[nodiscard]]
  std::string toString() const {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
  }

 private:
  int x, y;
};

#endif // MICROMOUSE_INCLUDE_MODEL_POSITION_H_
