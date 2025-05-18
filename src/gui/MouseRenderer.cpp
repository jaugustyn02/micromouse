#include "../../include/core/mouse/Micromouse.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "../../include/gui/MouseRenderer.h"
#include "../../include/core/GlobalConfig.h"

MouseRenderer::MouseRenderer(Micromouse &mouse) : mouse(mouse) {
  float cellSize = GLOBAL::RENDER::MAZE::CELL_SIZE;
  float mouseRadius = GLOBAL::RENDER::MOUSE::MOUSE_SIZE / 2;
  float mouseOriginX = mouseRadius - cellSize / 2 - GLOBAL::RENDER::MAZE::MARGIN_LEFT;
  float mouseOriginY = mouseRadius - cellSize / 2 - GLOBAL::RENDER::MAZE::MARGIN_TOP;

  mouseShape.setRadius(GLOBAL::RENDER::MOUSE::MOUSE_SIZE / 2);
  mouseShape.setFillColor(GLOBAL::COLORS::MOUSE_COLOR);
  mouseShape.setOrigin(mouseOriginX, mouseOriginY);
}

void MouseRenderer::draw(sf::RenderWindow &window) {
  constexpr float wallThickness = GLOBAL::RENDER::MAZE::WALL_THICKNESS;
  constexpr float cellSize = GLOBAL::RENDER::MAZE::CELL_SIZE;
  const float posX = static_cast<float>(mouse.getX()) * (cellSize - wallThickness);
  const float posY = static_cast<float>(mouse.getY()) * (cellSize - wallThickness);

  mouseShape.setPosition(posX, posY);
  window.draw(mouseShape);
}
