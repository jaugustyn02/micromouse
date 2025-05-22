#ifndef BUTTONSPROVIDER_H
#define BUTTONSPROVIDER_H

#include <complex.h>
#include <functional>
#include <string>

#include "core/GlobalConfig.h"
#include "model/Position.h"
#include "TGUI/Backend/SFML-Graphics.hpp"
#include "TGUI/Widgets/Button.hpp"
#include "TGUI/Widgets/Label.hpp"
#include "TGUI/Widgets/Slider.hpp"
#include "TGUI/Widgets/ToggleButton.hpp"

/**
 * @brief The UIControlsManager class is responsible for managing the UI controls in the GUI.
 * It provides methods to create and add buttons, toggle buttons, and sliders to the GUI.
 */
class UIControlsManager {
 public:
  /**
   * @brief Constructor for UIControlsManager.
   * @param gui Reference to the TGUI GUI object.
   */
  explicit UIControlsManager(tgui::SFML_GRAPHICS::Gui &gui);

  /**
   * @brief Adds a styled button with specified attributes to the GUI.
   * @param position The position of the button.
   * @param label The label of the button.
   * @param onPress The callback function to be called when the button is pressed.
   * @return A pointer to the created button.
   */
  tgui::Button::Ptr addButton(Position position, const std::string &label,
                              const std::function<void()> &onPress) const;

  /**
   * @brief Adds a styled toggle button with specified attributes to the GUI.
   * @param position The position of the toggle button.
   * @param label The label of the toggle button.
   * @param onToggle The callback function to be called when the toggle button is toggled.
   * @return A pointer to the created toggle button.
   */
  tgui::ToggleButton::Ptr addToggleButton(
      Position position,
      const std::string &label,
      const std::function<void(
          const tgui::ToggleButton::Ptr &button,
          bool checked)> &onToggle) const;

  /**
   * @brief Adds two toggle buttons with specified attributes to the GUI.
   * This function creates two toggle buttons that can be used to represent a switch.
   * @param position The position of the toggle button.
   * @param label1 The label of the first toggle button.
   * @param label2 The label of the second toggle button.
   * @param onPress1 The callback function to be called when the first toggle button is pressed.
   * @param onPress2 The callback function to be called when the second toggle button is pressed.
   * @return A pair of pointers to the created toggle buttons.
   */
  std::pair<tgui::ToggleButton::Ptr, tgui::ToggleButton::Ptr> addTwoStateToggleButtons(Position position,
                                                                                       const std::string &label1,
                                                                                       const std::string &label2,
                                                                                       const std::function<void()> &onPress1,
                                                                                       const std::function<void()> &onPress2) const;

  /**
   * @brief Adds two toggle labels with specified attributes to the GUI.
   * This function creates two labels that can be used to represent a read-only switch.
   * @param position The position of the label.
   * @param label1 The label of the first label.
   * @param label2 The label of the second label.
   * @return A pair of pointers to the created labels.
   */
  [[nodiscard]]
  std::pair<tgui::Label::Ptr, tgui::Label::Ptr> addTwoStateDisplayLabels(
      const Position &position,
      const std::string &label1,
      const std::string &label2) const;

  /**
   * @brief Sets one of the toggle labels as selected and the other as unselected.
   * This function is used to update state of the labels.
   * @param selected The label to be displayed when selected.
   * @param unselected The label to be displayed when unselected.
   */
  static void setTwoStateDisplaySelection(
      const tgui::Label::Ptr &selected, const tgui::Label::Ptr &unselected);

  /**
   * @brief Adds a slider with a label and a value display to the GUI.
   * @param position The position of the slider.
   * @param minValue The minimum value of the slider.
   * @param maxValue The maximum value of the slider.
   * @param defaultValue The default value of the slider.
   * @param step The step size of the slider.
   * @param onChange The callback function to be called when the slider value changes.
   * @return
   */
  std::pair<tgui::Slider::Ptr, tgui::Label::Ptr> addSliderWithValue(const Position &position, float minValue,
                                                                    float maxValue,
                                                                    float defaultValue, float step,
                                                                    const std::function<void(float)> &onChange) const;

 private:
  tgui::Gui &gui;
  tgui::Button::Ptr baseButton = tgui::Button::create();
  tgui::ToggleButton::Ptr baseToggleButton = tgui::ToggleButton::create();
  const float buttonWidth{GLOBAL::RENDER::CONTROL_PANEL::BUTTON_WIDTH};
  const float buttonHeight{GLOBAL::RENDER::CONTROL_PANEL::BUTTON_HEIGHT};
  const float spaceBetweenButtons{GLOBAL::RENDER::CONTROL_PANEL::SPACE_BETWEEN_BUTTONS};

  void createBaseButton() const;

  void createBaseToggleButton() const;
};

#endif //BUTTONSPROVIDER_H
