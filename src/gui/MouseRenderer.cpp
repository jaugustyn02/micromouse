#include "../../include/model/Micromouse.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "../../include/gui/MouseRenderer.h"
#include "../../include/core/GlobalConfig.h"

MouseRenderer::MouseRenderer(Micromouse &mouse) : mouse(mouse) {
  float cellSize = GLOBAL::RENDER::CELL_SIZE;
  float mouseRadius = GLOBAL::RENDER::MOUSE_SIZE / 2;
  float mouseOriginX = mouseRadius - cellSize / 2 - GLOBAL::RENDER::OFFSET_X;
  float mouseOriginY = mouseRadius - cellSize / 2 - GLOBAL::RENDER::OFFSET_Y;

  mouseShape.setRadius(GLOBAL::RENDER::MOUSE_SIZE / 2);
  mouseShape.setFillColor(GLOBAL::RENDER::MOUSE_COLOR);
  mouseShape.setOrigin(mouseOriginX, mouseOriginY);
}

void MouseRenderer::draw(sf::RenderWindow &window) {
  float cellSize = GLOBAL::RENDER::CELL_SIZE;
  float positionX = (float) mouse.getX() * cellSize;
  float positionY = (float) mouse.getY() * cellSize;
  
  mouseShape.setPosition(positionX, positionY);
  window.draw(mouseShape);
}
