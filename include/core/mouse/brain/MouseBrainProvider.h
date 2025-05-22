#ifndef MICROMOUSE_INCLUDE_CORE_MOUSEBRAINPROVIDER_H_
#define MICROMOUSE_INCLUDE_CORE_MOUSEBRAINPROVIDER_H_

#include "MouseBrain.h"
#include "strategy/exploration/RandomExplorationStrategy.h"
#include "strategy/fastest_path/BFSFastestPathStrategy.h"
#include "strategy/exploration/FloodingExplorationStrategy.h"
#include "strategy/fastest_path/RandomFastestPathStrategy.h"
#include "model/MouseBrainType.h"

/**
 * @class MouseBrainProvider
 * @brief Factory class for creating different types of MouseBrain instances.
 *
 * This class provides a static method to create instances of MouseBrain based on the specified type.
 * It encapsulates the logic for creating different strategies and configurations for the mouse brain.
 */
class MouseBrainProvider {
 public:
  /**
   * @brief Creates a MouseBrain instance based on the specified type.
   * @param type The type of MouseBrain to create.
   * @return A MouseBrain instance of the specified type.
   */
  static MouseBrain getMouseBrainInstance(MouseBrainType type);

 private:
  static MouseBrain getRandomBrainInstance();

  static MouseBrain getAdvancedBrainInstance();
};

#endif //MICROMOUSE_INCLUDE_CORE_MOUSEBRAINPROVIDER_H_
