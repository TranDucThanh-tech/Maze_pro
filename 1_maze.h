#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include "1_2_type_maze.h"
#include "2_1_maze_dfs.h"
#include "2_2_maze_prim.h"
#include "2_3_maze_kruskal.h"
#include "3_Button.h"
#include "3_Sound.h"
#include "4_Const_SDL_Color.h"
#include "4_Const_Maze_size.h"
#include "4_Const_Maze_step.h"
#include "4_Const_Maze_tick.h"
class maze{
public:
    SDL_Renderer* renderer;
    TTF_Font* font;
    SoundEffect* Sound;
    int row, col;
    bool is_finish;
    type_maze* Type_maze;
    vector<vector<int>>way;
    Button* DFS;
    Button* PRIM;
    Button* KRUSKAL;
    Button* BACK;
public:
    maze() = default;
    maze(SDL_Renderer* renderer, TTF_Font* font, SoundEffect* Sound);
    ~maze();

    bool is_finish_() const;

    void draw_cell(SDL_Renderer* renderer, int row, int col,
                   const SDL_Color& color) const;

    bool check_next_index(int const next_row, int const next_col,
                          int const mid_row, int const mid_col) const;

    bool check_new_index(int const new_row, int const new_col) const;

    void set_generate( type_maze* type);

    void generate_maze_();

    bool solve_maze(int row, int col, int mid_row, int mid_col);

    void clear_();

    void handle_event(SDL_Event& event);

};

#endif // MAZE_H
