#ifndef MICROMOUSE_INCLUDE_CORE_GLOBALCONFIG_H_
#define MICROMOUSE_INCLUDE_CORE_GLOBALCONFIG_H_

#include <chrono>
#include "TGUI/Color.hpp"

namespace GLOBAL {
namespace SCREEN {
inline constexpr const char *TITLE = "Micromouse Simulator";
inline constexpr int WIDTH = 800;
inline constexpr int HEIGHT = 600;
inline constexpr int FPS = 60;
inline constexpr std::chrono::microseconds FRAME_DURATION = std::chrono::microseconds(1000000 / FPS);
}

namespace SIMULATION {
inline constexpr int STEPS_PER_SECOND = 1;
inline constexpr int MAZE_WIDTH = 20;
inline constexpr int MAZE_HEIGHT = 20;
}

namespace RENDER {
static constexpr const float CELL_SIZE = 20.0f;
inline constexpr const float WALL_THICKNESS = 1.0f;
inline constexpr const float MOUSE_SIZE = 10.0f;
inline const sf::Color WALL_COLOR = sf::Color::White;
inline const sf::Color MOUSE_COLOR = sf::Color::Blue;
}
}

#endif //MICROMOUSE_INCLUDE_CORE_GLOBALCONFIG_H_
