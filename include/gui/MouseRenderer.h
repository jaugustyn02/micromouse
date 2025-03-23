#ifndef MICROMOUSE_INCLUDE_MODEL_MOUSERENDERER_H_
#define MICROMOUSE_INCLUDE_MODEL_MOUSERENDERER_H_

#include "../model/Micromouse.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/CircleShape.hpp"
#include "Drawable.h"

class MouseRenderer : public Drawable {
 public:
  explicit MouseRenderer(Micromouse &mouse);
  void draw(sf::RenderWindow &window) override;

 private:
  Micromouse &mouse;
  sf::CircleShape mouseShape;
};

#endif //MICROMOUSE_INCLUDE_MODEL_MOUSERENDERER_H_
