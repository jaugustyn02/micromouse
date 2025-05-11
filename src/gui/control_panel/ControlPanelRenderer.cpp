#include "../../../include/gui/control_panel/ControlPanelRenderer.h"
#include "TGUI/Widgets/Button.hpp"
#include "TGUI/Backend/SFML-Graphics.hpp"
#include "TGUI/Widgets/RadioButton.hpp"
#include "TGUI/Widgets/ToggleButton.hpp"
#include "../../../include/core/mouse/brain/MouseBrainProvider.h"
#include "TGUI/Widgets/Label.hpp"

ControlPanelRenderer::ControlPanelRenderer(
  SimulationController &simulationController,
  tgui::Gui &gui) : simulationController(simulationController),
                    gui(gui),
                    buttonsManager(gui) {
}

void ControlPanelRenderer::draw() {
  drawPosition = Position(560, 5);

  addSectionLabel("Maze");
  moveDrawPosition(0, spacing);
  addGenerateMazeButton();
  moveDrawPosition(0, sectionSpacing);

  addSectionLabel("Mouse");
  moveDrawPosition(0, spacing);
  addChangeMouseBrainButtons();
  moveDrawPosition(0, spacing);
  addChangeMouseModeButtons();
  moveDrawPosition(0, sectionSpacing);

  addSectionLabel("Simulation");
  moveDrawPosition(0, spacing);
  addStartStopToggleButton();
  moveDrawPosition(0, spacing);
  addResetButton();
}

void ControlPanelRenderer::addResetButton() {
  const std::function onResetButtonPress = [this]() {
    simulationController.reset();
    update();
  };
  resetButton = buttonsManager.addButton(drawPosition, GLOBAL::TEXT::RESET_BUTTON, onResetButtonPress);

  moveDrawPosition(0, static_cast<int>(resetButton->getSize().y));
}

void ControlPanelRenderer::addGenerateMazeButton() {
  const std::function onGenerateMazeButtonPress = [this]() {
    simulationController.generateMaze();
    update();
  };
  generateMazeButton = buttonsManager.addButton(drawPosition, GLOBAL::TEXT::GENERATE_MAZE_BUTTON,
                                                onGenerateMazeButtonPress);

  moveDrawPosition(0, static_cast<int>(generateMazeButton->getSize().y));
}

void ControlPanelRenderer::addStartStopToggleButton() {
  auto onToggle = ([=](const tgui::ToggleButton::Ptr &button, const bool checked) {
    if (checked) {
      simulationController.start();
      button->setText(GLOBAL::TEXT::STOP_BUTTON);
    } else {
      simulationController.stop();
      button->setText(GLOBAL::TEXT::START_BUTTON);
    }
  });

  startStopButton = buttonsManager.addToggleButton(drawPosition, GLOBAL::TEXT::START_BUTTON, onToggle);

  moveDrawPosition(0, static_cast<int>(startStopButton->getSize().y));
}

void ControlPanelRenderer::addChangeMouseBrainButtons() {
  const std::function onRandomBrainButtonPress = [this]() {
    simulationController.setMouseBrain(RANDOM);
  };
  const std::function onAdvancedBrainButtonPress = [this]() {
    simulationController.setMouseBrain(ADVANCED);
  };
  auto [randomBrainButton, advancedBrainButton] = buttonsManager.addTwoStateToggleButtons(
    drawPosition, "Random", "Advanced",
    onRandomBrainButtonPress, onAdvancedBrainButtonPress);
  mouseRandomBrainButton = randomBrainButton;
  mouseAdvancedBrainModeButton = advancedBrainButton;

  moveDrawPosition(0, static_cast<int>(mouseRandomBrainButton->getSize().y));
}

void ControlPanelRenderer::addChangeMouseModeButtons() {
  const std::function onExplorationModeButtonPress = [this]() {
    simulationController.setMouseMode(EXPLORATION);
  };
  const std::function onFastestPathModeButtonPress = [this]() {
    simulationController.setMouseMode(FASTEST_PATH);
  };
  auto [explorationModeButton, fastestPathModeButton] = buttonsManager.addTwoStateToggleButtons(
    drawPosition, "Exploration", "Fastest Path",
    onExplorationModeButtonPress, onFastestPathModeButtonPress);
  mouseExplorationModeButton = explorationModeButton;
  mouseFastestPathModeButton = fastestPathModeButton;

  moveDrawPosition(0, static_cast<int>(mouseExplorationModeButton->getSize().y));
}

void ControlPanelRenderer::addSectionLabel(const std::string &text) {
  const auto label = tgui::Label::create(text);
  label->setPosition(drawPosition.getX(), drawPosition.getY());
  label->setTextSize(18);
  label->getRenderer()->setTextColor(GLOBAL::COLORS::PRIMARY_DARK);
  label->getRenderer()->setTextStyle(tgui::TextStyle::Bold);
  gui.add(label);

  moveDrawPosition(0, static_cast<int>(label->getSize().y));
}

void ControlPanelRenderer::moveDrawPosition(const int x, const int y) {
  drawPosition = Position(drawPosition.getX() + x,
                          drawPosition.getY() + y);
}

void ControlPanelRenderer::update() const {
  updateStartStopToggleButton();
  updateChangeMouseModeButtons();
}

void ControlPanelRenderer::updateStartStopToggleButton() const {
  if (simulationController.getIsRunning()) {
    startStopButton->setDown(true);
  } else {
    startStopButton->setDown(false);
  }
}

void ControlPanelRenderer::updateChangeMouseModeButtons() const {
  if (const auto mouseMode = simulationController.getMouse().getMode();
    mouseMode == EXPLORATION || mouseMode == EXPLORATION_ON_RETURN) {
    mouseExplorationModeButton->setDown(true);
  } else if (mouseMode == FASTEST_PATH) {
    mouseFastestPathModeButton->setDown(true);
  }
}

