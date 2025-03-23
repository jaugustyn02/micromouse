#include "../../include/model/MouseSensor.h"

MouseSensor::MouseSensor(Position &position, Maze &maze) : position(position), maze(maze) {}

bool MouseSensor::isWallInDirection(Direction direction) {
  int x = position.getX();
  int y = position.getY();
  switch (direction) {
    case Direction::NORTH:return maze.getCell(x, y).topWall;
    case Direction::EAST:return maze.getCell(x, y).rightWall;
    case Direction::SOUTH:return maze.getCell(x, y).bottomWall;
    case Direction::WEST:return maze.getCell(x, y).leftWall;
  }
  return false;
}