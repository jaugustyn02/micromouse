#include "../../include/core/Application.h"
#include "../../include/core/GlobalConfig.h"
#include "../../include/logic/RandomExplorationStrategy.h"

void Application::run() {
  Maze maze(GLOBAL::SIMULATION::MAZE_WIDTH, GLOBAL::SIMULATION::MAZE_HEIGHT);
  maze.generate();

  Position position(0, 0);
  MouseSensor sensor(maze);
  RandomExplorationStrategy explorationStrategy;
  RandomExplorationStrategy pathfindingStrategy;
  MouseBrain brain(explorationStrategy, pathfindingStrategy);
  Micromouse mouse(position, sensor, brain, Direction::NORTH);

  Simulation simulation(maze, mouse);
  GUIManager guiManager(maze, mouse, simulation);

  guiManager.mainLoop();
}