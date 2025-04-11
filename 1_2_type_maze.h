#ifndef TYPE_MAZE_H
#define TYPE_MAZE_H

#include <vector>
#include <algorithm>
#include <SDL.h>
#include "4_Const_SDL_Color.h"
#include "4_Const_Maze_size.h"

using namespace std;

class maze;

class type_maze{
public:
    virtual void generate_maze(maze& Maze, int row, int col) = 0;
    virtual~type_maze() = default;
};

#endif // TYPE_MAZE_H
