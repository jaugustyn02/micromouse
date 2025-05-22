#ifndef EXPLORATION_STRATEGY_H
#define EXPLORATION_STRATEGY_H
#include "core/mouse/brain/strategy//MouseMovementProvider.h"

/**
 * @class ExplorationStrategy
 * @brief Base class for exploration strategies.
 *
 * Extends MouseMovementProvider but doesn't implement logic directly—acts as a tag.
 */
class ExplorationStrategy : public MouseMovementProvider {
};

#endif //EXPLORATION_STRATEGY_H
