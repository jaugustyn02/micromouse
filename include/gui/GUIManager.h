#ifndef MICROMOUSE_INCLUDE_MODEL_GUIMANAGER_H_
#define MICROMOUSE_INCLUDE_MODEL_GUIMANAGER_H_

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include "TGUI/Backend/SFML-Graphics.hpp"
#include "MazeRenderer.h"
#include "MouseRenderer.h"
#include "core/SimulationController.h"
#include "control_panel/ControlPanelRenderer.h"

class GUIManager {
 public:
  GUIManager(Maze &maze, Micromouse &mouse, SimulationController &simulationController);
  void mainLoop();

 private:
  sf::RenderWindow window;
  tgui::Gui gui;
  std::vector<std::unique_ptr<Drawable>> drawables;
  SimulationController &simulationController;
  ControlPanelRenderer controlPanelRenderer;
  void handleEvents();
  void render();
};

#endif //MICROMOUSE_INCLUDE_MODEL_GUIMANAGER_H_
