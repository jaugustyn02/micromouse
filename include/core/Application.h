#include "../gui/GUIManager.h"
#include "Simulation.h"
#ifndef MICROMOUSE_INCLUDE_CORE_APPLICATION_H_
#define MICROMOUSE_INCLUDE_CORE_APPLICATION_H_

class Application {
 private:
  Simulation simulation;
  GUIManager guiManager;
};

#endif //MICROMOUSE_INCLUDE_CORE_APPLICATION_H_
