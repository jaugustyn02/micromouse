#ifndef MICROMOUSE_FLOODINGEXPLORATIONSTRATEGY_H_
#define MICROMOUSE_FLOODINGEXPLORATIONSTRATEGY_H_

#include <set>
#include "../../../../../model/Position.h"
#include "../../../../../model/Direction.h"
#include "../MouseDecisionStrategy.h"
#include "../../../../GlobalConfig.h"

class FloodingExplorationStrategy final : public MouseDecisionStrategy {
public:
    FloodingExplorationStrategy();

    Direction decideMove(Position position, SensorReadings readings) override;

    void updateMazeMap(Position position, const SensorReadings &readings);

    bool isBestMoveLegal(Position position) const;

    Direction getBestMove(Position position) const;

    void calculateDistances();

    bool isVisited(Position position) const;

    bool isWallBetween(Position source, Position destination) const;

    static Direction getDirectionToNeighbourCell(Position source, Position destination);

    int getDistance(Position position) const;

    void setDistance(Position position, int distance);

    void reset() override {
        mazeMap.clear();
        clearDistance();
    }

    void clearDistance();

private:
    const int empty = -1;
    const int mazeWidth = GLOBAL::SIMULATION::MAZE_WIDTH;
    const int mazeHeight = GLOBAL::SIMULATION::MAZE_HEIGHT;
    std::map<Position, SensorReadings> mazeMap;
    std::vector<std::vector<int> > cellDistance = std::vector(mazeHeight, std::vector(mazeWidth, empty));
    std::array<Position, 4> goalPositions{
        Position(mazeWidth / 2 - 1, mazeHeight / 2 - 1),
        Position(mazeWidth / 2 - 1, mazeHeight / 2),
        Position(mazeWidth / 2, mazeHeight / 2 - 1),
        Position(mazeWidth / 2, mazeHeight / 2),
    };
};

#endif //MICROMOUSE_FLOODINGEXPLORATIONSTRATEGY_H_
