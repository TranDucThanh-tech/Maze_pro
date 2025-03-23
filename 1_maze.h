#ifndef MAZE_H
#define MAZE_H
#include <bits/stdc++.h>
#include <SDL.h>
#include "SDL_Color.h"
using namespace std;

class maze;

class type_maze{
public:
    virtual void generate_maze(maze& Maze, int row, int col) = 0;
    virtual~type_maze() = default;
};

class maze{
public:
    int row_size, col_size, cell_size;
    int row, col;
    vector<vector<int>>way;
    vector<vector<bool>>visited;
    type_maze* Type_maze;
    SDL_Renderer* renderer;
public:
    maze() = default;
    maze(int row_size, int col_size, int cell_size, SDL_Renderer* renderer);
    ~maze();

    void break_wall(int row, int col,
                    int new_row, int new_col);
    void draw_cell(SDL_Renderer* renderer, int row, int col,
                   const SDL_Color& color, int cell_size);
    void set_generate(type_maze* type);

    void generate_maze_();

    bool check_next_index(int next_row, int next_col);

    bool check_new_index(int new_row, int new_col);

    bool solve_maze(int row, int col);

    void reset();
};

#endif // MAZE_H
