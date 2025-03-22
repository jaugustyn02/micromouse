#ifndef MICROMOUSE_INCLUDE_CORE_GLOBALCONFIG_H_
#define MICROMOUSE_INCLUDE_CORE_GLOBALCONFIG_H_

#include <chrono>
#include "TGUI/Color.hpp"

namespace GLOBAL {
namespace SCREEN {
inline constexpr const char *TITLE = "Micromouse Simulator";
inline constexpr int WIDTH = 800;
inline constexpr int HEIGHT = 800;
inline constexpr int FPS = 60;
inline constexpr std::chrono::microseconds FRAME_DURATION = std::chrono::microseconds(1000000 / FPS);
}

namespace SIMULATION {
inline constexpr int STEPS_PER_SECOND = 1;
inline constexpr int MAZE_WIDTH = 20;
inline constexpr int MAZE_HEIGHT = 20;
}

namespace RENDER {
static constexpr const float CELL_SIZE = 30.0f;
inline constexpr const float WALL_THICKNESS = 1.0f;
inline constexpr const float MOUSE_SIZE = 20.0f;
inline constexpr const float OFFSET_X = 1.0f;
inline constexpr const float OFFSET_Y = 1.0f;
inline const sf::Color BACKGROUND_COLOR = tgui::Color{237, 225, 192, 255};
inline const sf::Color WALL_COLOR = sf::Color::Black;
inline const sf::Color MOUSE_COLOR = sf::Color::Red;
}
}

#endif //MICROMOUSE_INCLUDE_CORE_GLOBALCONFIG_H_
