#ifndef MICROMOUSE_INCLUDE_CORE_MOUSEBRAINPROVIDER_H_
#define MICROMOUSE_INCLUDE_CORE_MOUSEBRAINPROVIDER_H_

#include "MouseBrain.h"
#include "strategy/exploration/RandomExplorationStrategy.h"
#include "strategy/fastest_path/DijkstraFastestPathStrategy.h"
#include "strategy/exploration/BFSExplorationStrategy.h"
#include "strategy/fastest_path/RandomFastestPathStrategy.h"
#include "../../../model/MouseBrainType.h"

class MouseBrainProvider {
 public:
  MouseBrainProvider() = default;
  static MouseBrain getMouseBrainInstance(MouseBrainType type) {
    switch (type) {
      case RANDOM: return getRandomBrainInstance();
      case ADVANCED: return getAdvancedBrainInstance();
      default: throw std::invalid_argument("Invalid MouseBrainType");
    }
  }

 private:
  static MouseBrain getRandomBrainInstance() {
    auto randomExplorationStrategy = std::make_unique<RandomExplorationStrategy>();
    auto randomFastestPathStrategy = std::make_unique<RandomFastestPathStrategy>();
    return {std::move(randomExplorationStrategy), std::move(randomFastestPathStrategy)};
  }
  static MouseBrain getAdvancedBrainInstance() {
    auto bfsExplorationStrategy = std::make_unique<BFSExplorationStrategy>();
    auto dijkstraFastestPathStrategy = std::make_unique<DijkstraFastestPathStrategy>();
    return {std::move(bfsExplorationStrategy), std::move(dijkstraFastestPathStrategy)};
  }
};

#endif //MICROMOUSE_INCLUDE_CORE_MOUSEBRAINPROVIDER_H_
