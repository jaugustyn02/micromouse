#include <thread>
#include "SFML/Graphics/RenderWindow.hpp"
#include "TGUI/Backend/SFML-Graphics.hpp"
#include "gui/GUIManager.h"

GUIManager::GUIManager(Maze &maze, Micromouse &mouse, SimulationController &simulationController)
    : window(sf::VideoMode(GLOBAL::SCREEN::WIDTH, GLOBAL::SCREEN::HEIGHT), GLOBAL::TEXT::TITLE),
      gui(window),
      simulationController(simulationController),
      controlPanelRenderer(simulationController, gui) {
  drawables.push_back(std::make_unique<MazeRenderer>(maze));
  drawables.push_back(std::make_unique<MouseRenderer>(mouse));
}

void GUIManager::mainLoop() {
  controlPanelRenderer.draw();

  window.setFramerateLimit(GLOBAL::SCREEN::FPS);
  auto lastSimulationUpdate = std::chrono::high_resolution_clock::now();

  while (window.isOpen()) {
    handleEvents();

    const auto now = std::chrono::high_resolution_clock::now();
    const auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(now - lastSimulationUpdate);

    if (elapsed >= GLOBAL::SIMULATION::STEP_DURATION / simulationController.getSpeed()) {
      if (simulationController.getIsRunning()) {
        simulationController.nextStep();
        controlPanelRenderer.update();
        lastSimulationUpdate = now;
      }
    }

    render();
    std::this_thread::sleep_for(GLOBAL::SCREEN::FRAME_DURATION);
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
  window.clear(GLOBAL::COLORS::BACKGROUND_COLOR);

  for (const auto &drawable : drawables) {
    drawable->draw(window);
  }

  gui.draw();
  window.display();
}
