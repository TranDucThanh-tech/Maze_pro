#ifndef MAZE_DFS_H
#define MAZE_DFS_H

#include "1_maze.h"

class maze_dfs : public type_maze{
public:
    void generate_maze(maze& Maze, int row, int col) override;
};

#endif
