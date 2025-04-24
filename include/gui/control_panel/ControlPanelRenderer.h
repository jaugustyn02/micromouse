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

private:
    SimulationController &simulationController;
    tgui::Gui &gui;
    ButtonsManager buttonsManager;
    tgui::ToggleButton::Ptr startStopButton;
    tgui::Button::Ptr resetButton;
    tgui::Button::Ptr generateMazeButton;
    std::pair<tgui::Button::Ptr, tgui::Button::Ptr> mouseModeToggle;
    std::pair<tgui::Button::Ptr, tgui::Button::Ptr> mouseBrainToggle;

    void addStartStopToggleButton();

    void addChangeMouseModeButtons() const;

    void addChangeMouseBrainButtons() const;
};

#endif //MICROMOUSE_INCLUDE_GUI_CONTROLPANELRENDERER_H_
