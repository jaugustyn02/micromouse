#ifndef MICROMOUSE_INCLUDE_MODEL_MOUSEDECISIONSTRATEGY_H_
#define MICROMOUSE_INCLUDE_MODEL_MOUSEDECISIONSTRATEGY_H_

#include "../../../GlobalConfig.h"
#include "../../../../model/Direction.h"
#include "../../../../model/Position.h"
#include "../../../../model/SensorReadings.h"
#include <vector>

class MouseDecisionStrategy {
public:
    virtual ~MouseDecisionStrategy() = default;

    virtual Direction decideMove(Position position, SensorReadings readings) = 0;

    virtual void reset() = 0;

    void setGoal(const std::vector<Position> &positions) {
        goalPositions = positions;
    };

protected:
    const int mazeWidth = GLOBAL::SIMULATION::MAZE_WIDTH;
    const int mazeHeight = GLOBAL::SIMULATION::MAZE_HEIGHT;
    std::vector<Position> goalPositions{
        Position(mazeWidth / 2 - 1, mazeHeight / 2 - 1),
        Position(mazeWidth / 2 - 1, mazeHeight / 2),
        Position(mazeWidth / 2, mazeHeight / 2 - 1),
        Position(mazeWidth / 2, mazeHeight / 2),
    };
};

#endif //MICROMOUSE_INCLUDE_MODEL_MOUSEDECISIONSTRATEGY_H_
