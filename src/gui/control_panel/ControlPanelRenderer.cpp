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

  addSectionLabel(GLOBAL::TEXT::MAZE_SECTION);
  addGenerateMazeButton();
  moveDrawPosition(0, sectionSpacing);

  addSectionLabel(GLOBAL::TEXT::TARGET_SECTION);
  addTargetDisplay();
  moveDrawPosition(0, sectionSpacing);

  addSectionLabel(GLOBAL::TEXT::MODE_SECTION);
  addMouseModeDisplay();
  moveDrawPosition(0, sectionSpacing);

  addSectionLabel(GLOBAL::TEXT::ALGORITHM_SECTION);
  addChangeMouseBrainButtons();
  moveDrawPosition(0, sectionSpacing);

  addSectionLabel(GLOBAL::TEXT::SIMULATION_SECTION);
  addStartStopToggleButton();
  moveDrawPosition(0, ySpacing);
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

  auto [advancedBrainButton, randomBrainButton] = buttonsManager.addTwoStateToggleButtons(
    drawPosition, GLOBAL::TEXT::ADVANCED_BRAIN, GLOBAL::TEXT::RANDOM_BRAIN,
    onAdvancedBrainButtonPress, onRandomBrainButtonPress);
  mouseAdvancedBrainModeButton = advancedBrainButton;
  mouseRandomBrainButton = randomBrainButton;

  moveDrawPosition(0, static_cast<int>(mouseAdvancedBrainModeButton->getSize().y));
}

void ControlPanelRenderer::addMouseModeDisplay() {
  auto [exploration, fastestPath] = buttonsManager.
      addTwoStateDisplayLabels(drawPosition, GLOBAL::TEXT::EXPLORATION_MODE, GLOBAL::TEXT::FASTEST_PATH_MODE);
  modeExplorationLabel = exploration;
  modeFastestPathLabel = fastestPath;
  moveDrawPosition(0, static_cast<int>(exploration->getSize().y));
}

void ControlPanelRenderer::addTargetDisplay() {
  auto [goalLabel, startLabel] = buttonsManager.addTwoStateDisplayLabels(
    drawPosition, GLOBAL::TEXT::GOAL_TARGET, GLOBAL::TEXT::START_TARGET);
  targetGoalLabel = goalLabel;
  targetStartLabel = startLabel;
  moveDrawPosition(0, static_cast<int>(startLabel->getSize().y));
}

void ControlPanelRenderer::addSectionLabel(const std::string &text) {
  const auto label = tgui::Label::create(text);
  label->setPosition(drawPosition.getX() - 1, drawPosition.getY());
  label->setTextSize(GLOBAL::TEXT::SECTION_TEXT_SIZE);
  label->getRenderer()->setTextColor(GLOBAL::COLORS::PRIMARY_DARK);
  gui.add(label);

  moveDrawPosition(0, static_cast<int>(label->getSize().y) + ySpacing);
}

void ControlPanelRenderer::moveDrawPosition(const int x, const int y) {
  drawPosition = Position(drawPosition.getX() + x,
                          drawPosition.getY() + y);
}

void ControlPanelRenderer::update() const {
  updateStartStopToggleButton();
  updateMouseModeDisplay();
  updateTargetDisplay();
}

void ControlPanelRenderer::updateStartStopToggleButton() const {
  if (simulationController.getIsRunning()) {
    startStopButton->setDown(true);
  } else {
    startStopButton->setDown(false);
  }
}

void ControlPanelRenderer::updateMouseModeDisplay() const {
  const auto mode = simulationController.getMouse().getMode();
  const bool isExploration = (mode == EXPLORATION || mode == EXPLORATION_ON_RETURN);

  ButtonsManager::setTwoStateDisplaySelection(
    isExploration ? modeExplorationLabel : modeFastestPathLabel,
    isExploration ? modeFastestPathLabel : modeExplorationLabel);
}

void ControlPanelRenderer::updateTargetDisplay() const {
  const auto mode = simulationController.getMouse().getMode();
  const bool isGoal = (mode == EXPLORATION || mode == FASTEST_PATH);

  ButtonsManager::setTwoStateDisplaySelection(
    isGoal ? targetGoalLabel : targetStartLabel,
    isGoal ? targetStartLabel : targetGoalLabel);
}


