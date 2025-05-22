#ifndef MICROMOUSE_INCLUDE_GUI_SENSOR_H_
#define MICROMOUSE_INCLUDE_GUI_SENSOR_H_

#include "core/maze/Maze.h"
#include "model/Position.h"
#include "model/Direction.h"
#include "model/SensorReadings.h"

/*
 * @class MouseSensor
 * @brief Represents the sensors of the Micromouse robot.
 *
 * This class provides methods to retrieve sensor readings based on the current position of the
 * Micromouse in the maze. It uses a MazeReader to access the maze data.
 */
class MouseSensor {
 public:
  /**
   * @brief Constructs a MouseSensor instance with the specified maze reader.
   * @param mazeReader The MazeReader used to access the maze data.
   */
  MouseSensor(MazeReader &mazeReader) : maze(mazeReader) {};

  /**
   * @brief Retrieves the sensor readings for the specified position.
   * @param position The position of the Micromouse in the maze.
   * @return The sensor readings for the specified position.
   */
  [[nodiscard]]
  SensorReadings getSensorReadings(const Position &position) const;

 private:
  MazeReader &maze;
};

#endif //MICROMOUSE_INCLUDE_GUI_SENSOR_H_
