#include "../../../include/gui/control_panel/ControlPanelRenderer.h"
#include "TGUI/Widgets/Button.hpp"
#include "TGUI/Backend/SFML-Graphics.hpp"
#include "TGUI/Widgets/RadioButton.hpp"
#include "TGUI/Widgets/ToggleButton.hpp"
#include "../../../include/core/mouse/brain/MouseBrainProvider.h"

ControlPanelRenderer::ControlPanelRenderer(
  SimulationController &simulationController,
  tgui::Gui &gui) : simulationController(simulationController),
                    gui(gui),
                    buttonsManager(gui) {
}

void ControlPanelRenderer::draw() {
  const std::function onResetButtonPress = [this]() {
    simulationController.reset();
    update();
  };
  const std::function onGenerateMazeButtonPress = [this]() {
    simulationController.generateMaze();
    update();
  };

  resetButton = buttonsManager.addButton(Position(600, 110), GLOBAL::TEXT::RESET_BUTTON, onResetButtonPress);
  generateMazeButton = buttonsManager.addButton(Position(600, 160), GLOBAL::TEXT::GENERATE_MAZE_BUTTON,
                                                onGenerateMazeButtonPress);
  addStartStopToggleButton();
  addChangeMouseBrainButtons();
  addChangeMouseModeButtons();
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

  startStopButton = buttonsManager.addToggleButton({600, 10}, GLOBAL::TEXT::START_BUTTON, onToggle);
}

void ControlPanelRenderer::addChangeMouseBrainButtons() {
  const std::function onRandomBrainButtonPress = [this]() {
    simulationController.setMouseBrain(RANDOM);
  };
  const std::function onAdvancedBrainButtonPress = [this]() {
    simulationController.setMouseBrain(ADVANCED);
  };
  auto [randomBrainButton, advancedBrainButton] = buttonsManager.addTwoStateToggleButtons(
    {600, 210}, "Random", "Advanced",
    onRandomBrainButtonPress, onAdvancedBrainButtonPress);
  mouseRandomBrainButton = randomBrainButton;
  mouseAdvancedBrainModeButton = advancedBrainButton;
}

void ControlPanelRenderer::addChangeMouseModeButtons() {
  const std::function onExplorationModeButtonPress = [this]() {
    simulationController.setMouseMode(EXPLORATION);
  };
  const std::function onFastestPathModeButtonPress = [this]() {
    simulationController.setMouseMode(FASTEST_PATH);
  };
  auto [explorationModeButton, fastestPathModeButton] = buttonsManager.addTwoStateToggleButtons(
    {600, 260}, "Exploration", "Fastest Path",
    onExplorationModeButtonPress, onFastestPathModeButtonPress);
  mouseExplorationModeButton = explorationModeButton;
  mouseFastestPathModeButton = fastestPathModeButton;
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
