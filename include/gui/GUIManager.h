#ifndef MICROMOUSE_INCLUDE_MODEL_GUIMANAGER_H_
#define MICROMOUSE_INCLUDE_MODEL_GUIMANAGER_H_

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include "TGUI/Backend/SFML-Graphics.hpp"
#include "MazeRenderer.h"
#include "MouseRenderer.h"
#include "core/SimulationController.h"
#include "control_panel/ControlPanelRenderer.h"

/**
 * @brief The GUIManager class is responsible for managing the graphical user interface of the simulation.
 * It handles the rendering of the maze and the micromouse, as well as user interactions through the GUI.
 */
class GUIManager {
 public:
  /**
   * @brief Constructor for the GUIManager class.
   * @param maze Reference to the Maze object.
   * @param mouse Reference to the Micromouse object.
   * @param simulationController Reference to the SimulationController object.
   */
  GUIManager(Maze &maze, Micromouse &mouse, SimulationController &simulationController);

  /**
   * @brief Enters the main loop of the GUIManager.
   * This function handles events, updates the GUI, renders the window and invokes successive simulation steps in a
   * given time interval.
   */
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
