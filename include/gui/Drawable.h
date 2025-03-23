#ifndef MICROMOUSE_INCLUDE_GUI_DRAWABLE_H_
#define MICROMOUSE_INCLUDE_GUI_DRAWABLE_H_

#include "SFML/Graphics/RenderWindow.hpp"
class Drawable {
 public:
  virtual void draw(sf::RenderWindow &window) = 0;
};

#endif //MICROMOUSE_INCLUDE_GUI_DRAWABLE_H_
