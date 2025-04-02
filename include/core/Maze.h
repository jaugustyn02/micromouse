#ifndef MICROMOUSE_INCLUDE_GUI_MAZE_H_
#define MICROMOUSE_INCLUDE_GUI_MAZE_H_

#include <vector>
#include "MazeReader.h"
#include <set>

class Maze : public MazeReader {
 public:
  Maze(int width, int height);
  void generate();

  bool isWall(Position position, Direction direction) const override;
  CellType getCellType(Position position) const override;

  int getWidth() const override;
  int getHeight() const override;

 private:
  int width;
  int height;
  std::vector<std::vector<Cell>> grid;
  void initializeGrid();
  void resetGrid();
  std::vector<Position> getCellNeighbors(const Position &position) const;
  std::vector<Position> getUnvisitedNeighbors(const Position &position, const std::set<Position> &visited) const;
  void removeWallsBetweenNeighbourCells(const Position &firstPosition, const Position &secondPosition);
  void setGoal(std::set<Position> &visited);
  void setStart();
};

#endif //MICROMOUSE_INCLUDE_GUI_MAZE_H_
