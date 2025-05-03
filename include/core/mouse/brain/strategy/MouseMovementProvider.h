#ifndef MICROMOUSE_INCLUDE_MODEL_MOUSE_MOVEMENT_PROVIDER_H_
#define MICROMOUSE_INCLUDE_MODEL_MOUSE_MOVEMENT_PROVIDER_H_

#include "../../../GlobalConfig.h"
#include "../../../../model/Direction.h"
#include "../../../../model/Position.h"
#include "../../../../model/SensorReadings.h"
#include <utility>
#include <vector>

class MouseMovementProvider {
public:
    virtual ~MouseMovementProvider() = default;

    virtual Direction decideMove(Position position, SensorReadings readings) = 0;

    virtual void reset() {
    };

    void setDestination(const std::set<Position> &_destination) {
        destination = _destination;
    }

    [[nodiscard]] std::set<Position> getDestination() const {
        return destination;
    }

    void setStartPosition(const Position &_start) {
        start = _start;
    }

protected:
    const int mazeWidth = GLOBAL::SIMULATION::MAZE_WIDTH;
    const int mazeHeight = GLOBAL::SIMULATION::MAZE_HEIGHT;
    Position start{GLOBAL::SIMULATION::START};
    std::set<Position> destination = GLOBAL::CONSTANTS::GOAL_POSITIONS;
};

#endif //MICROMOUSE_INCLUDE_MODEL_MOUSE_MOVEMENT_PROVIDER_H_
