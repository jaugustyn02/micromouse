#include "core/mouse/brain/MouseBrainProvider.h"

MouseBrain MouseBrainProvider::getMouseBrainInstance(const MouseBrainType type) {
  switch (type) {
    case RANDOM: return getRandomBrainInstance();
    case ADVANCED: return getAdvancedBrainInstance();
    default: throw std::invalid_argument("[MouseBrainProvider] Invalid brain type");
  }
}

MouseBrain MouseBrainProvider::getRandomBrainInstance() {
  auto randomExplorationStrategy = std::make_unique<RandomExplorationStrategy>();
  auto randomFastestPathStrategy = std::make_unique<RandomFastestPathStrategy>();
  return {std::move(randomExplorationStrategy), std::move(randomFastestPathStrategy)};
}

MouseBrain MouseBrainProvider::getAdvancedBrainInstance() {
  auto floodingExplorationStrategy = std::make_unique<FloodingExplorationStrategy>();
  auto bfsFastestPathStrategy = std::make_unique<BFSFastestPathStrategy>();
  return {std::move(floodingExplorationStrategy), std::move(bfsFastestPathStrategy)};
}