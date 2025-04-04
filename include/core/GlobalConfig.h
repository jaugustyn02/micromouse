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
inline constexpr int STEP_DURATION_MS = 200;
inline constexpr std::chrono::microseconds STEP_DURATION = std::chrono::microseconds(STEP_DURATION_MS * 1000);
inline constexpr int MAZE_WIDTH = 16;
inline constexpr int MAZE_HEIGHT = 16;
inline constexpr int START_POSITION_X = 0;
inline constexpr int START_POSITION_Y = 0;
}

namespace RENDER {
inline constexpr const float CELL_SIZE = 40.0f;
inline constexpr const float WALL_THICKNESS = 10.0f;
inline constexpr const float MOUSE_SIZE = 16.0f;
inline constexpr const float OFFSET_X = CELL_SIZE;
inline constexpr const float OFFSET_Y = 0.0f;
inline const sf::Color BACKGROUND_COLOR = tgui::Color::White;
inline const sf::Color WALL_COLOR = sf::Color::Black;
inline const sf::Color MOUSE_COLOR = sf::Color{0, 76, 255};
inline const sf::Color GOAL_COLOR = sf::Color{163, 232, 160};
inline const sf::Color START_COLOR = sf::Color::White;
}

namespace RANDOM {
inline constexpr const bool USE_RANDOM_SEED = true;
inline constexpr const long long SEED = 0;
}

namespace CONSTANTS {
constexpr std::array<Direction, 4> DIRECTIONS = {NORTH, EAST, SOUTH, WEST};
}

}

#endif //MICROMOUSE_INCLUDE_CORE_GLOBALCONFIG_H_
