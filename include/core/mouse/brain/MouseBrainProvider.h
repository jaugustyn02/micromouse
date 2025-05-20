#ifndef MICROMOUSE_INCLUDE_CORE_MOUSEBRAINPROVIDER_H_
#define MICROMOUSE_INCLUDE_CORE_MOUSEBRAINPROVIDER_H_

#include "MouseBrain.h"
#include "strategy/exploration/RandomExplorationStrategy.h"
#include "strategy/fastest_path/BFSFastestPathStrategy.h"
#include "strategy/exploration/FloodingExplorationStrategy.h"
#include "strategy/fastest_path/RandomFastestPathStrategy.h"
#include "model/MouseBrainType.h"

class MouseBrainProvider {
 public:
  static MouseBrain getMouseBrainInstance(const MouseBrainType type) {
    switch (type) {
      case RANDOM: return getRandomBrainInstance();
      case ADVANCED: return getAdvancedBrainInstance();
      default: throw std::invalid_argument("[MouseBrainProvider] Invalid brain type");
    }
  }

 private:
  static MouseBrain getRandomBrainInstance() {
    auto randomExplorationStrategy = std::make_unique<RandomExplorationStrategy>();
    auto randomFastestPathStrategy = std::make_unique<RandomFastestPathStrategy>();
    return {std::move(randomExplorationStrategy), std::move(randomFastestPathStrategy)};
  }

  static MouseBrain getAdvancedBrainInstance() {
    auto floodingExplorationStrategy = std::make_unique<FloodingExplorationStrategy>();
    auto bfsFastestPathStrategy = std::make_unique<BFSFastestPathStrategy>();
    return {std::move(floodingExplorationStrategy), std::move(bfsFastestPathStrategy)};
  }
};

#endif //MICROMOUSE_INCLUDE_CORE_MOUSEBRAINPROVIDER_H_
