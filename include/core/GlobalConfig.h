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
inline constexpr int MAZE_WIDTH = 16;
inline constexpr int MAZE_HEIGHT = 16;
}

namespace RENDER {
static constexpr const float CELL_SIZE = 40.0f;
inline constexpr const float WALL_THICKNESS = 10.0f;
inline constexpr const float MOUSE_SIZE = 16.0f;
inline constexpr const float OFFSET_X = CELL_SIZE;
inline constexpr const float OFFSET_Y = 0.0f;
inline const sf::Color BACKGROUND_COLOR = tgui::Color{255, 255, 255, 255};
inline const sf::Color WALL_COLOR = sf::Color::Black;
inline const sf::Color MOUSE_COLOR = sf::Color::Blue;
}
}

#endif //MICROMOUSE_INCLUDE_CORE_GLOBALCONFIG_H_
