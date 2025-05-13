//
// Created by Jan on 4/24/2025.
//

#ifndef BUTTONSPROVIDER_H
#define BUTTONSPROVIDER_H
#include <complex.h>
#include <functional>
#include <string>
#include "../../model/Position.h"
#include "TGUI/Backend/SFML-Graphics.hpp"
#include "TGUI/Widgets/Button.hpp"
#include "TGUI/Widgets/Label.hpp"
#include "TGUI/Widgets/Slider.hpp"
#include "TGUI/Widgets/ToggleButton.hpp"

class UIControlsManager {
public:
    explicit UIControlsManager(tgui::SFML_GRAPHICS::Gui &gui);

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
        const std::function<void()> &onPress2, int buttonsGap) const;

    [[nodiscard]] std::pair<tgui::Label::Ptr, tgui::Label::Ptr> addTwoStateDisplayLabels(
        const Position &position,
        const std::string &label1,
        const std::string &label2) const;

    static void setTwoStateDisplaySelection(
        const tgui::Label::Ptr &selected, const tgui::Label::Ptr &unselected);

    std::pair<tgui::Slider::Ptr, tgui::Label::Ptr> addSliderWithValue(const Position &position, float minValue,
                                                                      float maxValue,
                                                                      float defaultValue, float step,
                                                                      const std::function<void(float)> &onChange,
                                                                      int labelGap) const;

private:
    tgui::Gui &gui;
    tgui::Button::Ptr baseButton = tgui::Button::create();
    tgui::ToggleButton::Ptr baseToggleButton = tgui::ToggleButton::create();

    void createBaseButton() const;

    void createBaseToggleButton() const;
};

#endif //BUTTONSPROVIDER_H
