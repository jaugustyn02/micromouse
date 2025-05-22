#ifndef MICROMOUSE_INCLUDE_MODEL_DIRECTION_H_
#define MICROMOUSE_INCLUDE_MODEL_DIRECTION_H_

#include <stdexcept>
#include <string>

/**
 * @brief The Direction enum class represents the four cardinal directions.
 * It is used to indicate the direction of movement in the maze.
 */
enum Direction {
  NORTH,
  EAST,
  SOUTH,
  WEST
};

/**
 * @brief Converts a Direction enum value to its string representation.
 * @param direction The direction to convert.
 * @return The string representation of the direction.
 */
inline std::string toString(Direction direction) {
  switch (direction) {
    case NORTH: return "NORTH";
    case EAST: return "EAST";
    case SOUTH: return "SOUTH";
    case WEST: return "WEST";
    default: throw std::invalid_argument("Invalid direction");
  }
}

/**
 * @brief Gets the opposite direction of the given direction.
 * @param direction The direction to get the opposite of.
 * @return The opposite direction.
 */
inline Direction opposite(Direction direction) {
  switch (direction) {
    case NORTH: return SOUTH;
    case EAST: return WEST;
    case SOUTH: return NORTH;
    case WEST: return EAST;
    default: throw std::invalid_argument("Invalid direction");
  }
}

#endif //MICROMOUSE_INCLUDE_MODEL_DIRECTION_H_
