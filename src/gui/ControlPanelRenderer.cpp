#include "../../include/gui/ControlPanelRenderer.h"
#include "TGUI/Widgets/Button.hpp"
#include "TGUI/Backend/SFML-Graphics.hpp"
#include "TGUI/Widgets/RadioButton.hpp"
#include "TGUI/Widgets/ToggleButton.hpp"

ControlPanelRenderer::ControlPanelRenderer(SimulationController &simulationController, tgui::Gui &gui) :
    simulationController(simulationController),
    gui(gui) {
  createBaseButton();
  createBaseToggleButton();
}

void ControlPanelRenderer::createBaseButton() {
  baseButton->setSize(150, 50);
  auto renderer = baseButton->getRenderer();
  renderer->setBackgroundColor(GLOBAL::COLORS::PRIMARY);
  renderer->setBackgroundColorHover(GLOBAL::COLORS::PRIMARY_DARK);
  renderer->setBackgroundColorDown(GLOBAL::COLORS::PRIMARY_DARK);
  renderer->setTextColor(sf::Color::White);
  renderer->setTextColorHover(sf::Color::White);
  renderer->setTextColorDown(sf::Color::White);
  renderer->setBorderColor(GLOBAL::COLORS::PRIMARY);
  renderer->setBorders(0);
  renderer->setRoundedBorderRadius(100);
  renderer->setTextStyle(tgui::TextStyle::Bold);
}

void ControlPanelRenderer::createBaseToggleButton() {
  baseToggleButton->setSize(150, 50);
  auto renderer = baseToggleButton->getRenderer();
  renderer->setBackgroundColor(GLOBAL::COLORS::PRIMARY);
  renderer->setBackgroundColorHover(GLOBAL::COLORS::PRIMARY_DARK);
  renderer->setBackgroundColorDown(GLOBAL::COLORS::PRIMARY_DARK);
  renderer->setTextColor(sf::Color::White);
  renderer->setTextColorHover(sf::Color::White);
  renderer->setTextColorDown(sf::Color::White);
  renderer->setBorderColor(GLOBAL::COLORS::PRIMARY);
  renderer->setBorders(0);
  renderer->setRoundedBorderRadius(100);
  renderer->setTextStyle(tgui::TextStyle::Bold);
  renderer->setBackgroundColorDisabled(GLOBAL::COLORS::PRIMARY_DARK);
  renderer->setTextColorDisabled(sf::Color::White);
}

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
  std::function < void() > onGenerateMazeButtonPress = [this]() {
    simulationController.generateMaze();
  };

  addButton(Position(560, 10), "Start", onStartButtonPress);
  addButton(Position(560, 70), "Stop", onStopButtonPress);
  addButton(Position(560, 130), "Reset", onResetButtonPress);
  addButton(Position(560, 190), "Generate Maze", onGenerateMazeButtonPress);
  // render speed slider
  // render algorithm dropdown
  // render maze dropdown
  // render mouse mode (exploration/fastest path) toggle button
  addChangeMouseModeButtons();
  // render mouse position
  // render mouse direction
  // render mouse speed
  // render mouse distance
}

void ControlPanelRenderer::addChangeMouseModeButtons() {
  std::function < void() > onExplorationModeButtonPress = [this]() {
    simulationController.setMouseMode(MouseMode::EXPLORATION);
  };
  std::function < void() > onFastestPathModeButtonPress = [this]() {
    simulationController.setMouseMode(MouseMode::FASTEST_PATH);
  };
  addTwoStateToggleButtons(Position(560, 250), "Exploration", "Fastest Path",
                           onExplorationModeButtonPress, onFastestPathModeButtonPress);
}

void ControlPanelRenderer::addButton(Position position,
                                     const std::string &label,
                                     const std::function<void()> &onPress) {
  auto button = tgui::Button::copy(baseButton);
  button->setText(label);
  button->setPosition(position.getX(), position.getY());
  button->onClick(onPress);
  gui.add(button);
}

void ControlPanelRenderer::addTwoStateToggleButtons(Position position,
                                                    const std::string &label1,
                                                    const std::string &label2,
                                                    const std::function<void()> &onPress1,
                                                    const std::function<void()> &onPress2) {
  auto button1 = tgui::ToggleButton::copy(baseToggleButton);
  auto button2 = tgui::ToggleButton::copy(baseToggleButton);
  button1->setText(label1);
  button2->setText(label2);
  button1->setPosition(position.getX(), position.getY());
  button2->setPosition(position.getX() + 160, position.getY());

  button1->setDown(true);
  button2->setDown(false);
  button1->setEnabled(false);

  button1->onToggle([=](bool checked) {
    if (checked) {
      onPress1();
      button2->setDown(false);
      button2->setEnabled(true);
      button1->setEnabled(false);
    }
  });
  button2->onToggle([=](bool checked) {
    if (checked) {
      onPress2();
      button1->setDown(false);
      button1->setEnabled(true);
      button2->setEnabled(false);
    }
  });

  gui.add(button1);
  gui.add(button2);
}