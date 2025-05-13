#ifndef MICROMOUSE_INCLUDE_CORE_GLOBALCONFIG_H_
#define MICROMOUSE_INCLUDE_CORE_GLOBALCONFIG_H_

#include <chrono>
#include <set>

#include "TGUI/Color.hpp"
#include "../model/Direction.h"
#include "../model/Position.h"

class Position;

namespace GLOBAL {
    namespace SCREEN {
        inline constexpr const char *TITLE = "Micromouse Simulator";
        inline constexpr int WIDTH = 900;
        inline constexpr int HEIGHT = 600;
        inline constexpr int FPS = 60;
        inline constexpr auto FRAME_DURATION = std::chrono::microseconds(1000000 / FPS);
    }

    namespace SIMULATION {
        inline constexpr int STEP_DURATION_MS = 200;
        inline constexpr auto STEP_DURATION = std::chrono::microseconds(STEP_DURATION_MS * 1000);
        inline constexpr int MAZE_WIDTH = 16;
        inline constexpr int MAZE_HEIGHT = 16;
        const Position START_POSITION{0, 0};
        const Position NORTHWEST_GOAL = {MAZE_WIDTH / 2 - 1, MAZE_HEIGHT / 2 - 1};
        const Position SOUTHWEST_GOAL = {MAZE_WIDTH / 2 - 1, MAZE_HEIGHT / 2};
        const Position NORTHEAST_GOAL = {MAZE_WIDTH / 2, MAZE_HEIGHT / 2 - 1};
        const Position SOUTHEAST_GOAL = {MAZE_WIDTH / 2, MAZE_HEIGHT / 2};
        inline constexpr int REMOVED_WALLS = 16;
    }

    namespace COLORS {
        inline const auto BACKGROUND = sf::Color{237, 232, 245};
        inline const auto SECONDARY = sf::Color{173, 187, 218};
        inline const auto SECONDARY_DARK = sf::Color{134, 151, 196};
        inline const auto PRIMARY = sf::Color{112, 145, 230};
        inline const auto PRIMARY_DARK = sf::Color{61, 82, 160};
        inline const auto DARK = sf::Color{24, 30, 41};
    }

    namespace RENDER {
        inline constexpr float CELL_SIZE = 40.0f;
        inline constexpr float WALL_THICKNESS = 8.0f; // 10
        inline constexpr float MOUSE_SIZE = 16.0f;
        inline constexpr float OFFSET_X = 20.0f;
        inline constexpr float OFFSET_Y = 0.0f;
        inline const sf::Color BACKGROUND_COLOR = COLORS::BACKGROUND;
        inline const sf::Color WALL_COLOR = COLORS::DARK;
        inline const sf::Color MOUSE_COLOR = COLORS::PRIMARY_DARK;
        inline const sf::Color GOAL_COLOR = COLORS::PRIMARY;
        inline const sf::Color START_COLOR = COLORS::BACKGROUND;
    }

    namespace TEXT {
        inline const std::string START_BUTTON = "Start";
        inline const std::string STOP_BUTTON = "Stop";
        inline const std::string RESET_BUTTON = "Reset";
        inline const std::string GENERATE_MAZE_BUTTON = "Generate";
        inline const std::string SIMULATION_SECTION = "Simulation";
        inline const std::string SIMULATION_SPEED_SECTION = "Simulation Speed";
        inline const std::string MAZE_SECTION = "Maze";
        inline const std::string ALGORITHM_SECTION = "Algorithm";
        inline const std::string TARGET_SECTION = "Target";
        inline const std::string MODE_SECTION = "Mouse Mode";
        inline const std::string ADVANCED_BRAIN = "Flooding + BFS";
        inline const std::string RANDOM_BRAIN = "Random";
        inline const std::string EXPLORATION_MODE = "Exploration";
        inline const std::string FASTEST_PATH_MODE = "Fastest Path";
        inline const std::string START_TARGET = "Start";
        inline const std::string GOAL_TARGET = "Goal";
        inline constexpr int SECTION_TEXT_SIZE = 18;
        inline constexpr int BUTTON_TEXT_SIZE = 12;
        inline constexpr int DISPLAY_TEXT_SIZE = 12;
        inline constexpr int SLIDER_VALUE_TEXT_SIZE = 16;
    }

    namespace RANDOM {
        inline constexpr bool USE_RANDOM_SEED = false;
        inline constexpr long long SEED = 0;
    }

    namespace CONSTANTS {
        constexpr std::array<Direction, 4> DIRECTIONS = {NORTH, EAST, SOUTH, WEST};
        const std::set GOAL_POSITIONS = {
            SIMULATION::NORTHWEST_GOAL,
            SIMULATION::SOUTHWEST_GOAL,
            SIMULATION::NORTHEAST_GOAL,
            SIMULATION::SOUTHEAST_GOAL
        };
    }
}

#endif //MICROMOUSE_INCLUDE_CORE_GLOBALCONFIG_H_
