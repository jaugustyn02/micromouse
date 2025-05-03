#ifndef MICROMOUSE_DFS_FASTEST_PATH_STRATEGY_H_
#define MICROMOUSE_DFS_FASTEST_PATH_STRATEGY_H_

#include <optional>
#include <deque>

#include "FastestPathStrategy.h"

class BFSFastestPathStrategy final : public FastestPathStrategy {
public:
    Direction decideMove(Position currentPosition, SensorReadings readings) override;

    void reset() override {
        path.reset();
    };

private:
    std::optional<std::deque<Direction>> path;

    void findFastestPath(Position start);

    Position getReachedDestination(const std::map<Position, int> &distance) const;

    Direction getBestMove(std::map<Position, int> &distance, Position position) const;

    std::map<Position, int> getDistanceMap(Position start) const;

    static bool isVisited(std::map<Position, int> distance, Position position);

    bool isWallBetween(Position source, Position destination) const;

    Direction getDirectionToNeighbourCell(Position source, Position destination);
};

#endif //MICROMOUSE_DFS_FASTEST_PATH_STRATEGY_H_
