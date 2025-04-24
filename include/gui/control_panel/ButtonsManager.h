//
// Created by Jan on 4/24/2025.
//

#ifndef BUTTONSPROVIDER_H
#define BUTTONSPROVIDER_H
#include <functional>
#include <string>
#include "../../model/Position.h"
#include "TGUI/Backend/SFML-Graphics.hpp"
#include "../../model/Position.h"
#include "TGUI/Widgets/Button.hpp"
#include "TGUI/Widgets/ToggleButton.hpp"

class ButtonsManager {
public:
    ButtonsManager(tgui::SFML_GRAPHICS::Gui &gui);

    tgui::Button::Ptr addButton(Position position, const std::string &label,
                                const std::function<void()> &onPress) const;

    tgui::ToggleButton::Ptr addToggleButton(
        Position position,
        const std::string &label,
        const std::function<void(
            const tgui::ToggleButton::Ptr &button,
            bool checked)> &onToggle) const;

    std::pair<tgui::ToggleButton::Ptr, tgui::ToggleButton::Ptr> addTwoStateToggleButtons(Position position,
        const std::string &label1,
        const std::string &label2,
        const std::function<void()> &onPress1,
        const std::function<void()> &onPress2) const;

private:
    tgui::Gui &gui;
    tgui::Button::Ptr baseButton = tgui::Button::create();
    tgui::ToggleButton::Ptr baseToggleButton = tgui::ToggleButton::create();

    void createBaseButton() const;

    void createBaseToggleButton() const;
};

#endif //BUTTONSPROVIDER_H
