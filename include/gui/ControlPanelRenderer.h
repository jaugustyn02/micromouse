#ifndef MICROMOUSE_INCLUDE_GUI_CONTROLPANELRENDERER_H_
#define MICROMOUSE_INCLUDE_GUI_CONTROLPANELRENDERER_H_

#include "Drawable.h"
#include "../core/SimulationController.h"
#include "TGUI/Backend/SFML-Graphics.hpp"
#include "../model/Position.h"
#include "TGUI/Widgets/Button.hpp"
#include "TGUI/Widgets/ToggleButton.hpp"

class ControlPanelRenderer {
 public:
  ControlPanelRenderer(SimulationController &simulationController, tgui::Gui &gui);
  void draw();
 private:
  SimulationController &simulationController;
  tgui::Gui &gui;
  tgui::Button::Ptr baseButton = tgui::Button::create();
  tgui::ToggleButton::Ptr baseToggleButton = tgui::ToggleButton::create();
  void addButton(Position position, const std::string &label, const std::function<void()> &onPress);
  void addTwoStateToggleButtons(Position position,
                                const std::string &label1,
                                const std::string &label2,
                                const std::function<void()> &onPress1,
                                const std::function<void()> &onPress2);
  void addChangeMouseModeButtons();
  void createBaseButton();
  void createBaseToggleButton();
};

#endif //MICROMOUSE_INCLUDE_GUI_CONTROLPANELRENDERER_H_
