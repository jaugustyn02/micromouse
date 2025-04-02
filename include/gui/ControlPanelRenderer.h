#ifndef MICROMOUSE_INCLUDE_GUI_CONTROLPANELRENDERER_H_
#define MICROMOUSE_INCLUDE_GUI_CONTROLPANELRENDERER_H_

#include "Drawable.h"
#include "../core/SimulationController.h"
#include "TGUI/Backend/SFML-Graphics.hpp"
#include "../model/Position.h"

class ControlPanelRenderer {
 public:
  ControlPanelRenderer(SimulationController &simulationController, tgui::Gui &gui);
  void draw();
 private:
  SimulationController &simulationController;
  tgui::Gui &gui;
  void addButton(Position position, const std::string &label, const std::function<void()> &onPress);
};

#endif //MICROMOUSE_INCLUDE_GUI_CONTROLPANELRENDERER_H_
