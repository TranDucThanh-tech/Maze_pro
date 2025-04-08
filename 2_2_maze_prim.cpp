#include "2_2_maze_prim.h"

const vector<int> drow = {0, 0, 2, -2};
const vector<int> dcol = {-2, 2, 0, 0};
void maze_prim :: generate_maze(maze& Maze, int row, int col)
{
    Maze.visited[row][col] = true;
    Maze.way[row][col] = 1;
    Maze.draw_cell(Maze.renderer, row, col, red, cell_size);
    SDL_RenderPresent(Maze.renderer);

    for (int i = 0; i < 4 ;i++){
        int new_row = row + drow[i];
        int new_col = col + dcol[i];
        if ( Maze.check_new_index(new_row, new_col)){
            section new_edge = section(row, col, new_row, new_col);
            edge.push_back(new_edge);
        }
    }

    while (!edge.empty()){
        int rand_edge = rand() % edge.size();
        section now_edge = edge[rand_edge];
        int start_row = now_edge.start_row;
        int start_col = now_edge.start_col;
        int end_row = now_edge.end_row;
        int end_col = now_edge.end_col;
        edge.erase(edge.begin() + rand_edge);

        if ( Maze.visited[end_row][end_col]) continue;

        Maze.visited[end_row][end_col] = true;
        Maze.way[end_row][end_col] = 1;
        Maze.break_wall(start_row, start_col, end_row, end_col);

        Maze.draw_cell(Maze.renderer, start_row, start_col, black,  cell_size);
        Maze.draw_cell( Maze.renderer, (start_row+end_row)/2, (start_col+end_col)/2, black,  cell_size);
        Maze.draw_cell( Maze.renderer, end_row, end_col, red,  cell_size);
        SDL_RenderPresent( Maze.renderer);
        SDL_Delay(10);
        Maze.draw_cell( Maze.renderer, end_row, end_col, black, cell_size);
        SDL_RenderPresent( Maze.renderer);

        for (int i = 0; i < 4; i++){
            int new_row = end_row + drow[i];
            int new_col = end_col + dcol[i];
            if( Maze.check_new_index(new_row, new_col)){
                section new_edge = section(end_row, end_col, new_row, new_col);
                edge.push_back(new_edge);
            }
        }
    }

}
