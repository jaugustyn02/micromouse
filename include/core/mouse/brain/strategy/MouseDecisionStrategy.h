#ifndef MICROMOUSE_INCLUDE_MODEL_MOUSEDECISIONSTRATEGY_H_
#define MICROMOUSE_INCLUDE_MODEL_MOUSEDECISIONSTRATEGY_H_

#include "../../../GlobalConfig.h"
#include "../../../../model/Direction.h"
#include "../../../../model/Position.h"
#include "../../../../model/SensorReadings.h"
#include <utility>
#include <vector>

class MouseDecisionStrategy {
public:
    virtual ~MouseDecisionStrategy() = default;

    virtual Direction decideMove(Position position, SensorReadings readings) = 0;

    virtual void reset() = 0;

    void setDestination(const std::set<Position> &positions) {
        goalPositions = positions;
    }

    std::set<Position> getDestination() const {
        return goalPositions;
    }

protected:
    const int mazeWidth = GLOBAL::SIMULATION::MAZE_WIDTH;
    const int mazeHeight = GLOBAL::SIMULATION::MAZE_HEIGHT;
    std::set<Position> goalPositions = GLOBAL::CONSTANTS::GOAL_POSITIONS;
};

#endif //MICROMOUSE_INCLUDE_MODEL_MOUSEDECISIONSTRATEGY_H_
