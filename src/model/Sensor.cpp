#include "../../include/model/Sensor.h"

Sensor::Sensor(int offsetX, int offsetY) : offsetX(offsetX), offsetY(offsetY) {}

bool Sensor::detectWall(const Maze &maze, int x, int y) const {
  int newX = x + offsetX;
  int newY = y + offsetY;
  if (newX < 0 || newX >= maze.getWidth() || newY < 0 || newY >= maze.getHeight()) {
    return true;
  }
  Cell &cell = maze.getCell(x, y);
  if (offsetY == -1) return cell.topWall;
  if (offsetX == 1) return cell.rightWall;
  if (offsetY == 1) return cell.bottomWall;
  if (offsetX == -1) return cell.leftWall;
  return false;
}