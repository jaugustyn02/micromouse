#include "../../../include/gui/control_panel/ButtonsManager.h"
#include "../../../include/core/GlobalConfig.h"

ButtonsManager::ButtonsManager(tgui::Gui &gui): gui(gui) {
    createBaseButton();
    createBaseToggleButton();
}

void ButtonsManager::createBaseButton() const {
    baseButton->setSize(140, 40);
    const auto renderer = baseButton->getRenderer();
    renderer->setBackgroundColor(GLOBAL::COLORS::PRIMARY);
    renderer->setBackgroundColorHover(GLOBAL::COLORS::PRIMARY_DARK);
    renderer->setBackgroundColorDown(GLOBAL::COLORS::PRIMARY_DARK);
    renderer->setTextColor(sf::Color::White);
    renderer->setTextColorHover(sf::Color::White);
    renderer->setTextColorDown(sf::Color::White);
    renderer->setBorderColor(GLOBAL::COLORS::DARK);
    renderer->setBorders(0);
    renderer->setRoundedBorderRadius(100);
    renderer->setTextStyle(tgui::TextStyle::Bold);
}

void ButtonsManager::createBaseToggleButton() const {
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
    renderer->setRoundedBorderRadius(100);
    renderer->setTextStyle(tgui::TextStyle::Bold);
    renderer->setBackgroundColorDisabled(GLOBAL::COLORS::PRIMARY_DARK);
    renderer->setTextColorDisabled(sf::Color::White);
}

tgui::Button::Ptr ButtonsManager::addButton(const Position position,
                                            const std::string &label,
                                            const std::function<void()> &onPress) const {
    const auto button = tgui::Button::copy(baseButton);
    button->setText(label);
    button->setPosition(position.getX(), position.getY());
    button->onClick(onPress);

    gui.add(button);
    return button;
}

tgui::ToggleButton::Ptr ButtonsManager::addToggleButton(const Position position,
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

void ButtonsManager::addTwoStateToggleButtons(const Position position,
                                              const std::string &label1,
                                              const std::string &label2,
                                              const std::function<void()> &onPress1,
                                              const std::function<void()> &onPress2) const {
    const auto button1 = tgui::ToggleButton::copy(baseToggleButton);
    const auto button2 = tgui::ToggleButton::copy(baseToggleButton);
    button1->setText(label1);
    button2->setText(label2);
    button1->setPosition(position.getX(), position.getY());
    button2->setPosition(position.getX() + 145, position.getY());

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
}
