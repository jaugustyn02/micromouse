#include "../../include/core/Application.h"

void Application::run() {
  Simulation simulation;
  GUIManager guiManager(simulation.getMaze(), simulation.getMouse(), simulation);

  guiManager.mainLoop();
}