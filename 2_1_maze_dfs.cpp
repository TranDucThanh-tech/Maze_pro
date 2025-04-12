#include "2_1_maze_dfs.h"


void maze_dfs :: generate_maze(maze& Maze, int row, int col)
{
    Maze.way[row][col] = way;
    Maze.draw_cell(Maze.renderer, row, col, black);

    vector<int>random_index = {0,1,2,3};
    random_device rd;
    mt19937 g(rd());
    shuffle(random_index.begin(), random_index.end(), g);

    for (int i = 0; i < 4; i++){
        int new_row = row + drow[random_index[i]];
        int new_col = col + dcol[random_index[i]];
        if (Maze.check_new_index(new_row, new_col)){
            int mid_row = (row + new_row) >> 1;
            int mid_col = (col +new_col) >> 1;
            Maze.way[mid_row][mid_col] = way;
            Maze.draw_cell( Maze.renderer, mid_row, mid_col, black);
            Maze.draw_cell( Maze.renderer, new_row, new_col, red);
            SDL_RenderPresent( Maze.renderer);
            SDL_Delay(10);

            generate_maze(Maze, new_row, new_col);
        }
    }
}

