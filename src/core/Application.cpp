#include "../../include/core/Application.h"
#include "../../include/core/GlobalConfig.h"
#include "../../include/logic/RandomExplorationStrategy.h"

void Application::run() {
  Maze maze(GLOBAL::SIMULATION::MAZE_WIDTH, GLOBAL::SIMULATION::MAZE_HEIGHT);
  maze.generate();

  MouseSensor sensor(maze);
  RandomExplorationStrategy randomExploration;
  RandomExplorationStrategy randomPathFinding;
  MouseBrain brain(randomExploration, randomPathFinding);

  Micromouse mouse(brain, sensor);

  Simulation simulation(maze, mouse);
  GUIManager guiManager(maze, mouse, simulation);

  guiManager.mainLoop();
}