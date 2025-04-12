#include "2_2_maze_prim.h"

void maze_prim :: generate_maze(maze& Maze, int row, int col)
{
    Maze.way[row][col] = way;
    Maze.draw_cell(Maze.renderer, row, col, red);
    SDL_RenderPresent(Maze.renderer);

    for (int i = 0; i < 4 ;i++){
        int new_row = row + drow[i];
        int new_col = col + dcol[i];
        if ( Maze.check_new_index(new_row, new_col)){
            section new_edge = section(row, col, new_row, new_col);
            Edge.push_back(new_edge);
        }
    }

    while (!Edge.empty()){
        int rand_edge = rand() % Edge.size();
        section edge = Edge[rand_edge];
        Edge.erase(Edge.begin() + rand_edge);

        if ( Maze.way[edge.end_row][edge.end_col] == way) continue;

        int mid_row = (edge.start_row + edge.end_row) >> 1;
        int mid_col = (edge.start_col + edge.end_col) >> 1;
        Maze.way[edge.end_row][edge.end_col] = way;
        Maze.way[mid_row][mid_col] = way;

        Maze.draw_cell(Maze.renderer, edge.start_row, edge.start_col, black);
        Maze.draw_cell( Maze.renderer, mid_row, mid_col, black);
        Maze.draw_cell( Maze.renderer, edge.end_row, edge.end_col, red);
        SDL_RenderPresent( Maze.renderer);
        SDL_Delay(10);
        Maze.draw_cell( Maze.renderer, edge.end_row, edge.end_col, black);

        for (int i = 0; i < 4; i++){
            int new_row = edge.end_row + drow[i];
            int new_col = edge.end_col + dcol[i];
            if( Maze.check_new_index(new_row, new_col)){
                section new_edge = section(edge.end_row, edge.end_col, new_row, new_col);
                Edge.push_back(new_edge);
            }
        }
    }

}
