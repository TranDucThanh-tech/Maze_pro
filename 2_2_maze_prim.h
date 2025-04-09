#ifndef MAZE_PRIM_H
#define MAZE_PRIM_H

#include <random>
#include "1_maze.h"
#include "section.h"


class maze_prim : public type_maze{
private:
    vector<section>Edge;
public:
    void generate_maze(maze& Maze, int row, int col) override;
};
#endif
