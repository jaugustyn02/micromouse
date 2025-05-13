#include "../../../include/gui/control_panel/UIControlsManager.h"
#include "../../../include/core/GlobalConfig.h"
#include "TGUI/Widgets/Slider.hpp"

UIControlsManager::UIControlsManager(tgui::Gui &gui): gui(gui) {
    createBaseButton();
    createBaseToggleButton();
}

void UIControlsManager::createBaseButton() const {
    baseButton->setSize(140, 40);
    const auto renderer = baseButton->getRenderer();
    renderer->setBackgroundColor(GLOBAL::COLORS::PRIMARY);
    renderer->setBackgroundColorHover(GLOBAL::COLORS::PRIMARY_DARK);
    renderer->setBackgroundColorDown(GLOBAL::COLORS::PRIMARY_DARK);
    renderer->setTextColor(sf::Color::White);
    renderer->setTextColorHover(sf::Color::White);
    renderer->setTextColorDown(sf::Color::White);
    renderer->setBorderColor(GLOBAL::COLORS::DARK);
    renderer->setTextSize(GLOBAL::TEXT::BUTTON_TEXT_SIZE);
    renderer->setBorders(0);
}

void UIControlsManager::createBaseToggleButton() const {
    baseToggleButton->setSize(140, 40);
    const auto renderer = baseToggleButton->getRenderer();
    renderer->setBackgroundColor(GLOBAL::COLORS::PRIMARY);
    renderer->setBackgroundColorHover(GLOBAL::COLORS::PRIMARY_DARK);
    renderer->setBackgroundColorDown(GLOBAL::COLORS::PRIMARY_DARK);
    renderer->setTextColor(sf::Color::White);
    renderer->setTextColorHover(sf::Color::White);
    renderer->setTextColorDown(sf::Color::White);
    renderer->setBorderColor(GLOBAL::COLORS::PRIMARY);
    renderer->setBorders(0);
    renderer->setBackgroundColorDisabled(GLOBAL::COLORS::PRIMARY_DARK);
    renderer->setTextColorDisabled(sf::Color::White);
    renderer->setTextSize(GLOBAL::TEXT::BUTTON_TEXT_SIZE);
}

tgui::Button::Ptr UIControlsManager::addButton(const Position position,
                                               const std::string &label,
                                               const std::function<void()> &onPress) const {
    const auto button = tgui::Button::copy(baseButton);
    button->setText(label);
    button->setPosition(position.getX(), position.getY());
    button->onClick(onPress);

    gui.add(button);
    return button;
}

tgui::ToggleButton::Ptr UIControlsManager::addToggleButton(const Position position,
                                                           const std::string &label,
                                                           const std::function<void(
                                                               const tgui::ToggleButton::Ptr &button, bool checked)> &
                                                           onToggle) const {
    const auto toggleButton = tgui::ToggleButton::copy(baseToggleButton);
    toggleButton->setText(label);
    toggleButton->setPosition(position.getX(), position.getY());

    toggleButton->onToggle([=](const bool checked) {
        onToggle(toggleButton, checked);
    });

    gui.add(toggleButton);
    return toggleButton;
}

std::pair<tgui::ToggleButton::Ptr, tgui::ToggleButton::Ptr> UIControlsManager::addTwoStateToggleButtons(
    const Position position,
    const std::string &label1,
    const std::string &label2,
    const std::function<void()> &onPress1,
    const std::function<void()> &onPress2,
    const int buttonsGap) const {
    const auto button1 = tgui::ToggleButton::copy(baseToggleButton);
    const auto button2 = tgui::ToggleButton::copy(baseToggleButton);

    button1->setText(label1);
    button2->setText(label2);

    button1->setPosition(position.getX(), position.getY());
    const auto offsetX = static_cast<int>(button1->getSize().x) + buttonsGap;
    button2->setPosition(position.getX() + offsetX, position.getY());

    button1->setDown(true);
    button2->setDown(false);
    button1->setEnabled(false);

    button1->onToggle([=](const bool checked) {
        if (checked) {
            onPress1();
            button2->setDown(false);
            button2->setEnabled(true);
            button1->setEnabled(false);
        }
    });
    button2->onToggle([=](const bool checked) {
        if (checked) {
            onPress2();
            button1->setDown(false);
            button1->setEnabled(true);
            button2->setEnabled(false);
        }
    });

    gui.add(button1);
    gui.add(button2);
    return {button1, button2};
}

std::pair<tgui::Label::Ptr, tgui::Label::Ptr> UIControlsManager::addTwoStateDisplayLabels(
    const Position &position,
    const std::string &label1,
    const std::string &label2) const {
    auto labelA = tgui::Label::create(label1);
    auto labelB = tgui::Label::create(label2);

    labelA->setPosition(position.getX(), position.getY());
    labelB->setPosition(position.getX() + 145, position.getY());

    for (auto &label: {labelA, labelB}) {
        label->setSize(140, 40);
        label->setTextSize(GLOBAL::TEXT::DISPLAY_TEXT_SIZE);
        label->setHorizontalAlignment(tgui::HorizontalAlignment::Center);
        label->setVerticalAlignment(tgui::VerticalAlignment::Center);

        const auto renderer = label->getRenderer();
        renderer->setBackgroundColor(GLOBAL::COLORS::SECONDARY);
        renderer->setTextColor(sf::Color::White);
        renderer->setBorders(0);
    }

    gui.add(labelA);
    gui.add(labelB);
    return {labelA, labelB};
}

void UIControlsManager::setTwoStateDisplaySelection(
    const tgui::Label::Ptr &selected,
    const tgui::Label::Ptr &unselected) {
    selected->getRenderer()->setBackgroundColor(GLOBAL::COLORS::SECONDARY_DARK);
    unselected->getRenderer()->setBackgroundColor(GLOBAL::COLORS::SECONDARY);
}

std::pair<tgui::Slider::Ptr, tgui::Label::Ptr> UIControlsManager::addSliderWithValue(
    const Position &position, const float minValue, const float maxValue,
    const float defaultValue, const float step,
    const std::function<void(float)> &onChange,
    const int labelGap) const {
    const auto slider = tgui::Slider::create(minValue, maxValue);
    slider->setStep(step);
    slider->setValue(defaultValue);
    slider->setSize(285, 18);
    slider->setPosition(position.getX(), position.getY());

    const auto valueLabel = tgui::Label::create(std::to_string(static_cast<int>(defaultValue)));
    valueLabel->setTextSize(GLOBAL::TEXT::SLIDER_VALUE_TEXT_SIZE);
    valueLabel->setPosition(position.getX(), position.getY() + static_cast<int>(slider->getSize().y) + labelGap);
    valueLabel->getRenderer()->setTextColor(GLOBAL::COLORS::PRIMARY_DARK);

    slider->onValueChange([=](const float value) {
        onChange(value);
        valueLabel->setText(std::to_string(static_cast<int>(value)));
    });

    const auto sliderRenderer = slider->getRenderer();
    sliderRenderer->setTrackColor(GLOBAL::COLORS::SECONDARY);
    sliderRenderer->setThumbColor(GLOBAL::COLORS::PRIMARY);
    sliderRenderer->setBorderColor(GLOBAL::COLORS::PRIMARY_DARK);
    sliderRenderer->setTrackColorHover(GLOBAL::COLORS::SECONDARY);
    sliderRenderer->setThumbColorHover(GLOBAL::COLORS::PRIMARY_DARK);
    sliderRenderer->setBorderColorHover(GLOBAL::COLORS::PRIMARY_DARK);
    sliderRenderer->setBorders(0);

    gui.add(slider);
    gui.add(valueLabel);

    return {slider, valueLabel};
}

