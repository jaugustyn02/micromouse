#include "../../include/model/Micromouse.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "../../include/gui/MouseRenderer.h"
#include "../../include/core/GlobalConfig.h"

MouseRenderer::MouseRenderer(Micromouse &mouse) : mouse(mouse) {}

void MouseRenderer::draw(sf::RenderWindow &window) {
  float cellSize = GLOBAL::RENDER::CELL_SIZE;

  sf::CircleShape mouseShape(cellSize / 3);
  mouseShape.setFillColor(GLOBAL::RENDER::MOUSE_COLOR);
  mouseShape.setPosition(mouse.getX() * cellSize + cellSize / 3,
                         mouse.getY() * cellSize + cellSize / 3);
  window.draw(mouseShape);
}
