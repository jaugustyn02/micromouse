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
                    uiControlsManager(gui) {
}

void ControlPanelRenderer::draw() {
  drawPosition = Position(GLOBAL::RENDER::CONTROL_PANEL::START_X, GLOBAL::RENDER::CONTROL_PANEL::START_Y);

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

  addSimulationSection();
  moveDrawPosition(0, sectionSpacing);

  addSectionLabel(GLOBAL::TEXT::SIMULATION_SPEED_SECTION);
  addSimulationSpeedSlider();
}

void ControlPanelRenderer::addSimulationSection() {
  addSectionLabel(GLOBAL::TEXT::SIMULATION_SECTION);
  addStartStopToggleButton();
  moveDrawPosition(static_cast<int>(startStopButton->getSize().x) + xSpacing, 0);
  addResetButton();
  moveDrawPosition(-(static_cast<int>(startStopButton->getSize().x) + xSpacing),
                   static_cast<int>(resetButton->getSize().y) + ySpacing);
}

void ControlPanelRenderer::addSimulationSpeedSlider() {
  const auto onSpeedValueChange = [this](const float value) {
    simulationController.setSpeed(static_cast<int>(value));
  };

  moveDrawPosition(0, 4);
  auto [slider, valueLabel] = uiControlsManager.addSliderWithValue(drawPosition, 1, GLOBAL::SIMULATION::MAX_SPEED,
                                                                   GLOBAL::SIMULATION::DEFAULT_SPEED, 1,
                                                                   onSpeedValueChange);
  simulationSpeedSlider = slider;
  simulationSpeedValueLabel = valueLabel;

  moveDrawPosition(0, static_cast<int>(simulationSpeedSlider->getSize().y) + ySpacing);
  moveDrawPosition(0, static_cast<int>(simulationSpeedValueLabel->getSize().y) - 6);
}

void ControlPanelRenderer::addResetButton() {
  const std::function onResetButtonPress = [this]() {
    simulationController.reset();
    update();
  };
  resetButton = uiControlsManager.addButton(drawPosition, GLOBAL::TEXT::RESET_BUTTON, onResetButtonPress);
}

void ControlPanelRenderer::addGenerateMazeButton() {
  const std::function onGenerateMazeButtonPress = [this]() {
    simulationController.generateMaze();
    update();
  };
  generateMazeButton = uiControlsManager.addButton(drawPosition, GLOBAL::TEXT::GENERATE_MAZE_BUTTON,
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
  startStopButton = uiControlsManager.addToggleButton(drawPosition, GLOBAL::TEXT::START_BUTTON, onToggle);
}

void ControlPanelRenderer::addChangeMouseBrainButtons() {
  const std::function onRandomBrainButtonPress = [this]() {
    simulationController.setMouseBrain(RANDOM);
  };
  const std::function onAdvancedBrainButtonPress = [this]() {
    simulationController.setMouseBrain(ADVANCED);
  };

  auto [advancedBrainButton, randomBrainButton] = uiControlsManager.addTwoStateToggleButtons(
    drawPosition, GLOBAL::TEXT::ADVANCED_BRAIN, GLOBAL::TEXT::RANDOM_BRAIN,
    onAdvancedBrainButtonPress, onRandomBrainButtonPress);
  mouseAdvancedBrainModeButton = advancedBrainButton;
  mouseRandomBrainButton = randomBrainButton;

  moveDrawPosition(0, static_cast<int>(mouseAdvancedBrainModeButton->getSize().y));
}

void ControlPanelRenderer::addMouseModeDisplay() {
  auto [exploration, fastestPath] = uiControlsManager.
      addTwoStateDisplayLabels(drawPosition, GLOBAL::TEXT::EXPLORATION_MODE, GLOBAL::TEXT::FASTEST_PATH_MODE);
  modeExplorationLabel = exploration;
  modeFastestPathLabel = fastestPath;
  moveDrawPosition(0, static_cast<int>(exploration->getSize().y));
}

void ControlPanelRenderer::addTargetDisplay() {
  auto [goalLabel, startLabel] = uiControlsManager.addTwoStateDisplayLabels(
    drawPosition, GLOBAL::TEXT::GOAL_TARGET, GLOBAL::TEXT::START_TARGET);
  targetGoalLabel = goalLabel;
  targetStartLabel = startLabel;
  moveDrawPosition(0, static_cast<int>(startLabel->getSize().y));
}

void ControlPanelRenderer::addSectionLabel(const std::string &text) {
  const auto label = tgui::Label::create(text);
  label->setPosition(drawPosition.getX() - 2, drawPosition.getY());
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

  UIControlsManager::setTwoStateDisplaySelection(
    isExploration ? modeExplorationLabel : modeFastestPathLabel,
    isExploration ? modeFastestPathLabel : modeExplorationLabel);
}

void ControlPanelRenderer::updateTargetDisplay() const {
  const auto mode = simulationController.getMouse().getMode();
  const bool isGoal = (mode == EXPLORATION || mode == FASTEST_PATH);

  UIControlsManager::setTwoStateDisplaySelection(
    isGoal ? targetGoalLabel : targetStartLabel,
    isGoal ? targetStartLabel : targetGoalLabel);
}


