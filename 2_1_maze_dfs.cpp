#include "2_1_maze_dfs.h"

void maze_dfs :: generate_maze(maze& Maze, int row, int col)
{
    Maze.visited[row][col] = true;
    Maze.way[row][col] = 1;

    Maze.draw_cell(Maze.renderer, row, col, black, Maze.cell_size);

    vector<int>delta_row = {0,0,-2,2};
    vector<int>delta_col = {-2,2,0,0};
    vector<int>random_index = {0,1,2,3};
    random_shuffle(random_index.begin(), random_index.end());

    for (int i = 0; i < 4; i++){
        int new_row = row + delta_row[random_index[i]];
        int new_col = col + delta_col[random_index[i]];
        if (Maze.check_new_index(new_row, new_col)){
            Maze.break_wall(row, col, new_row, new_col);

            Maze.draw_cell( Maze.renderer, (row+new_row)/2, (col + new_col)/2, black,  Maze.cell_size);
            Maze.draw_cell( Maze.renderer, new_row, new_col, red,  Maze.cell_size);
            SDL_RenderPresent( Maze.renderer);
            SDL_Delay(5);

           generate_maze(Maze,new_row, new_col);
        }
    }
}

