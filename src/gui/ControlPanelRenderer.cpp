#include "../../include/gui/ControlPanelRenderer.h"
#include "TGUI/Widgets/Button.hpp"
#include "TGUI/Backend/SFML-Graphics.hpp"

ControlPanelRenderer::ControlPanelRenderer(SimulationController &simulationController, tgui::Gui &gui) :
    simulationController(simulationController),
    gui(gui) {}

void ControlPanelRenderer::draw() {
  std::function < void() > onStartButtonPress = [this]() {
    simulationController.start();
  };
  std::function < void() > onStopButtonPress = [this]() {
    simulationController.stop();
  };
  std::function < void() > onResetButtonPress = [this]() {
    simulationController.reset();
  };

  addButton(Position(560, 0), "Start", onStartButtonPress);
  addButton(Position(560, 50), "Stop", onStopButtonPress);
  addButton(Position(560, 100), "Reset", onResetButtonPress);
  // render speed slider
  // render algorithm dropdown
  // render maze dropdown
  // render mouse dropdown
  // render mouse position
  // render mouse direction
  // render mouse speed
  // render mouse distance
}

void ControlPanelRenderer::addButton(Position position,
                                     const std::string &label,
                                     const std::function<void()> &onPress) {
  auto button = tgui::Button::create(label);
  button->setPosition(position.getX(), position.getY());
  button->setSize(100, 40);
  button->onClick(onPress);
  gui.add(button);
}
