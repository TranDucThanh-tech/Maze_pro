#ifndef TYPE_MAZE_H
#define TYPE_MAZE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <SDL.h>
#include "SDL_Color.h"
#include "Maze_size.h"
using namespace std;

class maze;

class type_maze{
public:
    virtual void generate_maze(maze& Maze, int row, int col) = 0;
    virtual~type_maze() = default;
};

#endif // TYPE_MAZE_H
