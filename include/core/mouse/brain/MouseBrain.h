#ifndef MICROMOUSE_INCLUDE_MODEL_MOUSEBRAIN_H_
#define MICROMOUSE_INCLUDE_MODEL_MOUSEBRAIN_H_

#include "strategy/MouseMovementProvider.h"
#include "../../GlobalConfig.h"
#include "../../../model/MouseMode.h"
#include "../MouseSensor.h"
#include <utility>

#include "strategy/exploration/ExplorationStrategy.h"
#include "strategy/fastest_path/FastestPathStrategy.h"

class MouseBrain {
public:
    MouseBrain(std::unique_ptr<ExplorationStrategy> explorationStrategy,
               std::unique_ptr<FastestPathStrategy> pathfindingStrategy);

    void setMode(MouseMode mode); // TODO: make private

    void nextMode();

    [[nodiscard]] MouseMode getMode() const { return activeMode; }

    Direction getNextMove(Position currentPosition, const SensorReadings &readings);

    [[nodiscard]] bool isDestinationReached(Position position) const;

    void reset();

private:
    std::unique_ptr<ExplorationStrategy> explorationStrategy;
    std::unique_ptr<FastestPathStrategy> pathfindingStrategy;
    MouseMovementProvider *currentStrategy;
    MouseMode activeMode{EXPLORATION};
    std::map<Position, SensorReadings> mazeMap;

    void validateMove(Position position, Direction move) const;

    [[nodiscard]] bool isMoveLegal(Position position, Direction move) const;

    [[nodiscard]] MouseMode getNextMode() const;
};

#endif //MICROMOUSE_INCLUDE_MODEL_MOUSEBRAIN_H_
