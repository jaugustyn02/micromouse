#include "SFML/Graphics/RenderWindow.hpp"
#include "TGUI/Backend/SFML-Graphics.hpp"
#include "../../include/gui/GUIManager.h"
#include "../../include/core/GlobalConfig.h"

GUIManager::GUIManager(Maze &maze, Micromouse &mouse)
    : window(sf::VideoMode(GLOBAL::SCREEN::WIDTH, GLOBAL::SCREEN::HEIGHT), GLOBAL::SCREEN::TITLE),
      gui(window),
      mazeRenderer(maze),
      mouseRenderer(mouse) {
}

void GUIManager::run() {
  while (window.isOpen()) {
    handleEvents();
    render();
  }
}

void GUIManager::handleEvents() {
  sf::Event event{};
  while (window.pollEvent(event)) {
    gui.handleEvent(event);
    if (event.type == sf::Event::Closed) {
      window.close();
    }
  }
}

void GUIManager::render() {
  window.clear(GLOBAL::RENDER::BACKGROUND_COLOR);
  mazeRenderer.draw(window);
  mouseRenderer.draw(window);
  gui.draw();
  window.display();
}
