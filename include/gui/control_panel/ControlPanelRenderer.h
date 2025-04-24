#ifndef MICROMOUSE_INCLUDE_GUI_CONTROLPANELRENDERER_H_
#define MICROMOUSE_INCLUDE_GUI_CONTROLPANELRENDERER_H_

#include "ButtonsManager.h"
#include "../../core/SimulationController.h"
#include "TGUI/Backend/SFML-Graphics.hpp"

class ControlPanelRenderer {
public:
    ControlPanelRenderer(SimulationController &simulationController, tgui::Gui &gui);

    void draw();

    void update() const;

    void updateStartStopToggleButton() const;

    void updateChangeMouseModeButtons() const;

private:
    SimulationController &simulationController;
    tgui::Gui &gui;
    ButtonsManager buttonsManager;
    tgui::ToggleButton::Ptr startStopButton;
    tgui::Button::Ptr resetButton;
    tgui::Button::Ptr generateMazeButton;
    tgui::ToggleButton::Ptr mouseExplorationModeButton;
    tgui::ToggleButton::Ptr mouseFastestPathModeButton;
    tgui::ToggleButton::Ptr mouseRandomBrainButton;
    tgui::ToggleButton::Ptr mouseAdvancedBrainModeButton;

    void addStartStopToggleButton();

    void addChangeMouseModeButtons();

    void addChangeMouseBrainButtons();
};

#endif //MICROMOUSE_INCLUDE_GUI_CONTROLPANELRENDERER_H_
