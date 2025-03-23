#ifndef MAZE_DFS_H
#define MAZE_DFS_H
#include <SDL.h>
#include "1_maze.h"

using namespace std;

class maze_dfs : public type_maze{
public:
    void generate_maze(maze& Maze, int row, int col) override;
};

#endif
