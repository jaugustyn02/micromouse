#ifndef MICROMOUSE_INCLUDE_MODEL_MOUSEDECISIONSTRATEGY_H_
#define MICROMOUSE_INCLUDE_MODEL_MOUSEDECISIONSTRATEGY_H_

#include <vector>
#include "../../../../model/Direction.h"
#include "../../../../model/Position.h"
#include "../../../../model/Cell.h"
#include "../../../../model/SensorReadings.h"

class MouseDecisionStrategy {
public:
    virtual ~MouseDecisionStrategy() = default;

    virtual Direction decideMove(Position position, SensorReadings readings) = 0;

    virtual void reset() = 0;
};

#endif //MICROMOUSE_INCLUDE_MODEL_MOUSEDECISIONSTRATEGY_H_
