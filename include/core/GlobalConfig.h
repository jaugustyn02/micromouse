#ifndef MICROMOUSE_INCLUDE_CORE_GLOBALCONFIG_H_
#define MICROMOUSE_INCLUDE_CORE_GLOBALCONFIG_H_

#include <chrono>
#include <set>

#include "TGUI/Color.hpp"
#include "model/Direction.h"
#include "model/Position.h"

class Position;

namespace GLOBAL {
namespace SIMULATION {
inline constexpr int DEFAULT_SPEED = 5;
inline constexpr int MAX_SPEED = 20;
inline constexpr int STEP_DURATION_MS = 200 * DEFAULT_SPEED;
inline constexpr auto STEP_DURATION = std::chrono::microseconds(STEP_DURATION_MS * 1000);
}

namespace MAZE {
inline constexpr int ROWS = 16;
inline constexpr int COLUMNS = 16;
inline constexpr int REMOVED_WALLS = (COLUMNS + ROWS) / 2;

const Position START_POSITION{0, 0};
const Position NORTHWEST_GOAL = {COLUMNS / 2 - 1, ROWS / 2 - 1};
const Position SOUTHWEST_GOAL = {COLUMNS / 2 - 1, ROWS / 2};
const Position NORTHEAST_GOAL = {COLUMNS / 2, ROWS / 2 - 1};
const Position SOUTHEAST_GOAL = {COLUMNS / 2, ROWS / 2};
}

namespace COLORS {
inline const auto BACKGROUND = sf::Color{237, 232, 245};
inline const auto SECONDARY = sf::Color{173, 187, 218};
inline const auto SECONDARY_DARK = sf::Color{134, 151, 196};
inline const auto PRIMARY = sf::Color{112, 145, 230};
inline const auto PRIMARY_DARK = sf::Color{61, 82, 160};
inline const auto DARK = sf::Color{24, 30, 41};

inline const sf::Color MOUSE_COLOR = PRIMARY_DARK;
inline const sf::Color WALL_COLOR = DARK;
inline const sf::Color GOAL_COLOR = PRIMARY;
inline const sf::Color START_COLOR = BACKGROUND;
inline const sf::Color BACKGROUND_COLOR = BACKGROUND;
}

namespace TEXT {
inline constexpr auto TITLE = "Micromouse Simulator";
inline const auto START_BUTTON = "Start";
inline const auto STOP_BUTTON = "Stop";
inline const auto RESET_BUTTON = "Reset";
inline const auto GENERATE_MAZE_BUTTON = "Generate";
inline const auto SIMULATION_SECTION = "Simulation";
inline const auto SIMULATION_SPEED_SECTION = "Simulation Speed";
inline const auto MAZE_SECTION = "Maze";
inline const auto ALGORITHM_SECTION = "Algorithm";
inline const auto TARGET_SECTION = "Target";
inline const auto MODE_SECTION = "Mouse Mode";
inline const auto ADVANCED_BRAIN = "Flooding + BFS";
inline const auto RANDOM_BRAIN = "Random";
inline const auto EXPLORATION_MODE = "Exploration";
inline const auto FASTEST_PATH_MODE = "Fastest Path";
inline const auto START_TARGET = "Start";
inline const auto GOAL_TARGET = "Goal";

inline constexpr int SECTION_TEXT_SIZE = 18;
inline constexpr int BUTTON_TEXT_SIZE = 12;
inline constexpr int DISPLAY_TEXT_SIZE = 12;
inline constexpr int SLIDER_VALUE_TEXT_SIZE = 16;
}

namespace RENDER {
namespace MOUSE {
inline constexpr float MOUSE_SIZE = 16.0f;
}

namespace MAZE {
inline constexpr float CELL_SIZE = 40.0f;
inline constexpr float WALL_THICKNESS = 8.0f;

inline constexpr float MARGIN_LEFT = 20.0f;
inline constexpr float MARGIN_RIGHT = 0.0f;
inline constexpr float MARGIN_TOP = 0.0f;
inline constexpr float MARGIN_BOTTOM = 20.0f;

inline constexpr float WIDTH = GLOBAL::MAZE::COLUMNS * (CELL_SIZE - WALL_THICKNESS) + WALL_THICKNESS;
inline constexpr float HEIGHT = GLOBAL::MAZE::ROWS * (CELL_SIZE - WALL_THICKNESS) + WALL_THICKNESS;
inline constexpr float END_X = MARGIN_LEFT + WIDTH + MARGIN_RIGHT;
inline constexpr float END_Y = MARGIN_TOP + HEIGHT + MARGIN_BOTTOM;
}

namespace CONTROL_PANEL {
inline constexpr float BUTTON_WIDTH = 140.0f;
inline constexpr float BUTTON_HEIGHT = 40.0f;
inline constexpr float SPACE_BETWEEN_BUTTONS = 5.0f;
inline constexpr float SPACE_BETWEEN_SECTIONS = 10.0f;

inline constexpr float MARGIN_LEFT = 20.0f;
inline constexpr float MARGIN_RIGHT = 20.0f;
inline constexpr float MARGIN_TOP = 5.0f;
inline constexpr float MARGIN_BOTTOM = 20.0f;

inline constexpr float START_X = MAZE::END_X + MARGIN_LEFT;
inline constexpr float START_Y = MARGIN_TOP;

inline constexpr float WIDTH = 2 * BUTTON_WIDTH + SPACE_BETWEEN_BUTTONS;
inline constexpr float SECTION_HEIGHT =
    BUTTON_HEIGHT + SPACE_BETWEEN_BUTTONS + SPACE_BETWEEN_SECTIONS + TEXT::SECTION_TEXT_SIZE + 3;
inline constexpr float HEIGHT = 6 * SECTION_HEIGHT + 10;
inline constexpr float END_X = START_X + WIDTH + MARGIN_RIGHT;
inline constexpr float END_Y = START_Y + HEIGHT + MARGIN_BOTTOM;
}
}

namespace SCREEN {
inline constexpr int WIDTH = RENDER::CONTROL_PANEL::END_X;
inline constexpr int HEIGHT = std::max(RENDER::MAZE::END_Y, RENDER::CONTROL_PANEL::END_Y);

inline constexpr int FPS = 60;
inline constexpr auto FRAME_DURATION = std::chrono::microseconds(1000000 / FPS);
}

namespace RANDOM {
inline constexpr bool USE_RANDOM_SEED = false;
inline constexpr long long SEED = 0;
}

namespace CONSTANTS {
constexpr std::array<Direction, 4> DIRECTIONS = {NORTH, EAST, SOUTH, WEST};
const std::set GOAL_POSITIONS = {
    MAZE::NORTHWEST_GOAL,
    MAZE::SOUTHWEST_GOAL,
    MAZE::NORTHEAST_GOAL,
    MAZE::SOUTHEAST_GOAL
};
}
}

#endif //MICROMOUSE_INCLUDE_CORE_GLOBALCONFIG_H_
