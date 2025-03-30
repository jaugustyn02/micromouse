#ifndef MICROMOUSE_INCLUDE_MODEL_MOUSEBRAIN_H_
#define MICROMOUSE_INCLUDE_MODEL_MOUSEBRAIN_H_

#include "MouseDecisionStrategy.h"
#include "../core/GlobalConfig.h"
#include "../model/MouseMode.h"
#include "MouseSensor.h"

class MouseBrain {
 public:
  MouseBrain(MouseDecisionStrategy &explorationStrategy, MouseDecisionStrategy &pathfindingStrategy)
      : explorationStrategy(explorationStrategy),
        pathfindingStrategy(pathfindingStrategy),
        currentStrategy(&explorationStrategy),
        mode(EXPLORATION) {
    reset();
  }

  void setMode(MouseMode _mode) {
    this->mode = _mode;
    currentStrategy = (mode == EXPLORATION) ? &explorationStrategy : &pathfindingStrategy;
  }

  Direction getNextMove(Position position, MouseSensor &sensor) {
    updateMap(position, sensor);
    return currentStrategy->decideMove(position, map);
  }

  void reset() {
//    map.reserve(GLOBAL::SIMULATION::MAZE_WIDTH);
//
//    for (int y = 0; y < GLOBAL::SIMULATION::MAZE_HEIGHT; ++y) {
//      std::vector<Cell> row;
//      row.reserve(GLOBAL::SIMULATION::MAZE_WIDTH);
//      for (int x = 0; x < GLOBAL::SIMULATION::MAZE_WIDTH; ++x) {
//        row.emplace_back(Position(x, y), CellType::UNVISITED);
//      }
//      map.push_back(std::move(row));
//    }
  }

 private:
  MouseDecisionStrategy &explorationStrategy;
  MouseDecisionStrategy &pathfindingStrategy;
  MouseDecisionStrategy *currentStrategy;
  MouseMode mode;
  std::vector<std::vector<Cell>> map;

  void updateMap(Position position, MouseSensor &sensor) {
//    Cell &cell = map[position.getY()][position.getX()];
//    cell.topWall = sensor.isWallInDirection(NORTH);
//    cell.bottomWall = sensor.isWallInDirection(SOUTH);
//    cell.rightWall = sensor.isWallInDirection(EAST);
//    cell.leftWall = sensor.isWallInDirection(WEST);
  }
};

#endif //MICROMOUSE_INCLUDE_MODEL_MOUSEBRAIN_H_
