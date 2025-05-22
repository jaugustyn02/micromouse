#ifndef MICROMOUSE_INCLUDE_GUI_DRAWABLE_H_
#define MICROMOUSE_INCLUDE_GUI_DRAWABLE_H_

#include "SFML/Graphics/RenderWindow.hpp"
#include "TGUI/Backend/SFML-Graphics.hpp"

/**
 * @brief The Drawable class is an abstract base class for all drawable objects in the GUI.
 * It defines a common interface for rendering objects on the screen.
 */
class Drawable {
 public:
  /**
   * @brief Destructor for the Drawable class.
   */
  virtual ~Drawable() = default;

  /**
   * @brief Performs the drawing operation on the given window.
   * @param window The window to draw on.
   */
  virtual void draw(sf::RenderWindow &window) = 0;
};

#endif //MICROMOUSE_INCLUDE_GUI_DRAWABLE_H_
