#ifndef MICROMOUSE_INCLUDE_MODEL_MOUSERENDERER_H_
#define MICROMOUSE_INCLUDE_MODEL_MOUSERENDERER_H_

#include "core/mouse/Micromouse.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/CircleShape.hpp"
#include "Drawable.h"
#include "TGUI/Backend/SFML-Graphics.hpp"

/**
 * @brief The MouseRenderer class is responsible for rendering the micromouse on the screen.
 * It uses SFML to draw the micromouse as a circle.
 */
class MouseRenderer : public Drawable {
 public:
  /**
   * @brief Constructor for the MouseRenderer class.
   * @param mouse Reference to the Micromouse object.
   */
  explicit MouseRenderer(Micromouse &mouse);

  /**
   * @brief Draws the micromouse on the given window.
   * @param window The window to draw on.
   */
  void draw(sf::RenderWindow &window) override;

 private:
  Micromouse &mouse;
  sf::CircleShape mouseShape;
};

#endif //MICROMOUSE_INCLUDE_MODEL_MOUSERENDERER_H_
