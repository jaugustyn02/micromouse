#ifndef MICROMOUSE_INCLUDE_GUI_CONTROLPANELRENDERER_H_
#define MICROMOUSE_INCLUDE_GUI_CONTROLPANELRENDERER_H_

#include "UIControlsManager.h"
#include "core/SimulationController.h"
#include "TGUI/Backend/SFML-Graphics.hpp"
#include "TGUI/Widgets/Slider.hpp"

/**
 * @brief The ControlPanelRenderer class is responsible for rendering the control panel of the simulation.
 */
class ControlPanelRenderer {
 public:
  /**
   * @brief Constructor for ControlPanelRenderer.
   * @param simulationController Reference to the SimulationController object.
   * @param gui Reference to the TGUI GUI object.
   */
  ControlPanelRenderer(SimulationController &simulationController, tgui::Gui &gui);

  /**
   * @brief Destructor for ControlPanelRenderer.
   */
  void draw();

  /**
   * @brief Updates the control panel based on the current state of the simulation.
   */
  void update() const;

 private:
  Position drawPosition = Position(GLOBAL::RENDER::CONTROL_PANEL::START_X, GLOBAL::RENDER::CONTROL_PANEL::START_Y);
  const int ySpacing = GLOBAL::RENDER::CONTROL_PANEL::SPACE_BETWEEN_BUTTONS;
  const int xSpacing = GLOBAL::RENDER::CONTROL_PANEL::SPACE_BETWEEN_BUTTONS;
  const int sectionSpacing = GLOBAL::RENDER::CONTROL_PANEL::SPACE_BETWEEN_SECTIONS;
  SimulationController &simulationController;
  tgui::Gui &gui;
  UIControlsManager uiControlsManager;
  tgui::ToggleButton::Ptr startStopButton;
  tgui::Button::Ptr resetButton;
  tgui::Button::Ptr generateMazeButton;
  tgui::Label::Ptr modeExplorationLabel;
  tgui::Label::Ptr modeFastestPathLabel;
  tgui::Label::Ptr targetStartLabel;
  tgui::Label::Ptr targetGoalLabel;
  tgui::ToggleButton::Ptr mouseRandomBrainButton;
  tgui::ToggleButton::Ptr mouseAdvancedBrainModeButton;
  tgui::Slider::Ptr simulationSpeedSlider;
  tgui::Label::Ptr simulationSpeedValueLabel;

  void addStartStopToggleButton();

  void addMouseModeDisplay();

  void addTargetDisplay();

  void addChangeMouseBrainButtons();

  void updateStartStopToggleButton() const;

  void updateMouseModeDisplay() const;

  void updateTargetDisplay() const;

  void addSectionLabel(const std::string &text);

  void moveDrawPosition(int x, int y);

  void addResetButton();

  void addGenerateMazeButton();

  void addSimulationSection();

  void addSimulationSpeedSlider();
};

#endif //MICROMOUSE_INCLUDE_GUI_CONTROLPANELRENDERER_H_
