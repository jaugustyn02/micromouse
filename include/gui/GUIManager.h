#ifndef MICROMOUSE_INCLUDE_MODEL_GUIMANAGER_H_
#define MICROMOUSE_INCLUDE_MODEL_GUIMANAGER_H_

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include "TGUI/Backend/SFML-Graphics.hpp"
#include "MazeRenderer.h"
#include "MouseRenderer.h"

class GUIManager {
 public:
  GUIManager(Maze &maze, Micromouse &mouse);
  void run();

 private:
  sf::RenderWindow window;
  tgui::Gui gui;
  MazeRenderer mazeRenderer;
  MouseRenderer mouseRenderer;
  void handleEvents();
  void render();
};

#endif //MICROMOUSE_INCLUDE_MODEL_GUIMANAGER_H_
