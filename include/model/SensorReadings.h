#ifndef MICROMOUSE_INCLUDE_MODEL_SENSORREADINGS_H_
#define MICROMOUSE_INCLUDE_MODEL_SENSORREADINGS_H_

#include <array>
#include <map>
#include "Direction.h"
#include "CellType.h"

/**
 * @brief The SensorReadings class represents the sensor readings of the micromouse.
 * It is used to store the information about walls and cell types in the maze.
 */
class SensorReadings {
 public:
  /**
   * @brief Constructor for the SensorReadings class.
   * @param cellType The type of the cell (e.g., empty, wall, etc.).
   */
  explicit SensorReadings(CellType cellType) : cellType(cellType) {
  };

  /**
   * @brief Default constructor for the SensorReadings class.
   */
  SensorReadings() = default;

  /**
   * @brief Sets the wall status in the specified direction.
   * @param direction The direction to set the wall status.
   * @param isWall True if there is a wall, false otherwise.
   */
  void setWall(Direction direction, bool isWall);

  /**
   * @brief Checks if there is a wall in the specified direction.
   * @param direction The direction to check for a wall.
   * @return True if there is a wall, false otherwise.
   */
  [[nodiscard]] bool isWall(Direction direction) const;

  /**
   * @brief Gets the cell type.
   * @return The type of the cell.
   */
  CellType getCellType() const;

 private:
  std::map<Direction, bool> readings{{NORTH, false}, {EAST, false}, {SOUTH, false}, {WEST, false}};
  CellType cellType{CellType::PATH};
};

#endif //MICROMOUSE_INCLUDE_MODEL_SENSORREADINGS_H_
