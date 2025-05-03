#ifndef MICROMOUSE_INCLUDE_LOGIC_DFSFASTESTPATHSTRATEGY_H_
#define MICROMOUSE_INCLUDE_LOGIC_DFSFASTESTPATHSTRATEGY_H_

#include <queue>

#include "FastestPathStrategy.h"

class BFSFastestPathStrategy : public FastestPathStrategy {
public:
    Direction decideMove(Position position, SensorReadings readings) override;

    void reset() override;

private:
    std::queue<Position> path;

    void findFastestPath();
};

#endif //MICROMOUSE_INCLUDE_LOGIC_DFSFASTESTPATHSTRATEGY_H_
