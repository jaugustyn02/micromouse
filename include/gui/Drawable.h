#ifndef MICROMOUSE_INCLUDE_GUI_DRAWABLE_H_
#define MICROMOUSE_INCLUDE_GUI_DRAWABLE_H_

#include "SFML/Graphics/RenderWindow.hpp"
#include "TGUI/Backend/SFML-Graphics.hpp"

class Drawable {
 public:
    virtual ~Drawable() = default;

    virtual void draw(sf::RenderWindow &window) = 0;
};

#endif //MICROMOUSE_INCLUDE_GUI_DRAWABLE_H_
