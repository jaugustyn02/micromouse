#ifndef MICROMOUSE_INCLUDE_GUI_CONTROLPANELRENDERER_H_
#define MICROMOUSE_INCLUDE_GUI_CONTROLPANELRENDERER_H_

#include "UIControlsManager.h"
#include "../../core/SimulationController.h"
#include "TGUI/Backend/SFML-Graphics.hpp"
#include "TGUI/Widgets/Slider.hpp"

class ControlPanelRenderer {
public:
    ControlPanelRenderer(SimulationController &simulationController, tgui::Gui &gui);

    void draw();

    void addSimulationSection();

    void addSimulationSpeedSlider();

    void update() const;

private:
    Position drawPosition{0, 0};
    const int ySpacing = 5;
    const int xSpacing = 5;
    const int sectionSpacing = 10;
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
};

#endif //MICROMOUSE_INCLUDE_GUI_CONTROLPANELRENDERER_H_
