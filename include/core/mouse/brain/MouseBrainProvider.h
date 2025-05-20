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
  static MouseBrain getMouseBrainInstance(const MouseBrainType type);

 private:
  static MouseBrain getRandomBrainInstance();

  static MouseBrain getAdvancedBrainInstance();
};

#endif //MICROMOUSE_INCLUDE_CORE_MOUSEBRAINPROVIDER_H_
