#ifndef MICROMOUSE_INCLUDE_CORE_APPLICATION_H_
#define MICROMOUSE_INCLUDE_CORE_APPLICATION_H_

#include "gui/GUIManager.h"
#include "Simulation.h"

/**
 * @class Application
 * @brief Main entry point for running the Micromouse simulation application.
 *
 * This class provides the static method to start the simulation, including
 * initialization of GUI and simulation components.
 */
class Application {
 public:
  /**
   * @brief Starts the Micromouse simulation application.
   *
   * Initializes necessary components such as the GUI manager and simulation,
   * then enters the main loop to run the application.
   */
  static void run();
};

#endif // MICROMOUSE_INCLUDE_CORE_APPLICATION_H_
