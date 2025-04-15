#include "../../include/core/mouse/Micromouse.h"
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
  float wallThickness = GLOBAL::RENDER::WALL_THICKNESS;
  float cellSize = GLOBAL::RENDER::CELL_SIZE;
  float posX = (float) mouse.getX() * (cellSize - wallThickness);
  float posY = (float) mouse.getY() * (cellSize - wallThickness);

  mouseShape.setPosition(posX, posY);
  window.draw(mouseShape);
}
