#include "../../include/core/Application.h"
#include "../../include/core/GlobalConfig.h"

void Application::run() {
  Maze maze(GLOBAL::SIMULATION::MAZE_WIDTH, GLOBAL::SIMULATION::MAZE_HEIGHT);
  maze.generate();

  Position position(0, 0);
  MouseSensor sensor(position, maze);
  Micromouse mouse(position, sensor, Direction::NORTH, MouseMode::EXPLORATION);

  Simulation simulation(maze, mouse);
  GUIManager guiManager(maze, mouse, simulation);

  guiManager.mainLoop();
}