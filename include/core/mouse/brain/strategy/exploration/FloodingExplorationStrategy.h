#ifndef MICROMOUSE_FLOODINGEXPLORATIONSTRATEGY_H_
#define MICROMOUSE_FLOODINGEXPLORATIONSTRATEGY_H_

#include "../../../../../model/Position.h"
#include "../../../../../model/Direction.h"
#include "ExplorationStrategy.h"

class FloodingExplorationStrategy final : public ExplorationStrategy {
public:
    FloodingExplorationStrategy();

    Direction decideMove(Position position, SensorReadings readings) override;

    void reset() override {
        mazeMap.clear();
        clearDistance();
    }

private:
    const int empty = -1;
    std::map<Position, SensorReadings> mazeMap;
    std::vector<std::vector<int> > cellDistance = std::vector(mazeHeight, std::vector(mazeWidth, empty));

    void updateMazeMap(Position position, const SensorReadings &readings);

    void calculateDistances();

    Direction getBestMove(Position position) const;

    bool isBestMoveLegal(Position position) const;

    bool isVisited(Position position) const;

    bool isWallBetween(Position source, Position destination) const;

    static Direction getDirectionToNeighbourCell(Position source, Position destination);

    int getDistance(Position position) const;

    void setDistance(Position position, int distance);

    void clearDistance();
};

#endif //MICROMOUSE_FLOODINGEXPLORATIONSTRATEGY_H_
