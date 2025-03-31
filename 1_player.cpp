#include "1_player.h"

player::player(int x, int y, maze* Maze, SDL_Renderer* renderer)
    : x(x), y(y), Maze(Maze), renderer(renderer) {
    now_playing = false;
    solved = false;
}

void player :: move_player(string direction){
    SDL_Color white = { 255, 255, 255, 255 };
    SDL_Color black = {0, 0, 0, 255 };
    Maze -> draw_cell(renderer, x, y, black, Maze -> cell_size);
    int new_row = x, new_col = y;
    if(direction == "right") new_col +=2;
    else if(direction == "left") new_col -=2;
    else if(direction == "down") new_row +=2;
    else if (direction == "up") new_row -=2;

    if (new_row >= 0 && new_row < row_size &&
        new_col >= 0 && new_col < col_size &&
        Maze -> way[new_row][new_col] == 1 &&
        Maze -> way[(new_row+x)/2][(new_col+y)/2] != 0){

        x = new_row;
        y = new_col;
    }
    Maze -> draw_cell(renderer, x, y, white, Maze -> cell_size);
    SDL_RenderPresent(renderer);
}

void player :: reset(){
    x = 0;
    y = 0;
}

bool player :: is_end(){
    return (x == row_size-1 && y == col_size-1);
}


void player::handle_event(SDL_Event& event) {
    if (!now_playing && Maze -> now_playing_())
        Maze -> draw_cell(renderer, x, y, white, Maze -> cell_size);
    if (event.type == SDL_KEYDOWN){
        if(event.key.repeat != 0) return;
        if (solved) return;
        switch (event.key.keysym.sym) {
            case SDLK_RIGHT: move_player("right"); now_playing = true; return;
            case SDLK_LEFT: move_player("left");now_playing = true; return;
            case SDLK_DOWN: move_player("down");now_playing = true; return;
            case SDLK_UP: move_player("up");now_playing = true; return;
            case SDLK_RETURN:
                Maze -> draw_cell(renderer, x, y, black, Maze -> cell_size);
                SDL_RenderPresent(renderer);
                Maze -> solve_maze(0, 0);
                solved = true;
                return;
            case SDLK_HOME:
                Maze -> draw_cell(renderer, x, y, black, Maze -> cell_size);
                SDL_RenderPresent(renderer);
                reset();
                Maze -> draw_cell(renderer, x, y, white, Maze -> cell_size);
                return;
            default:
                return;
        }
    }
    if (is_end() && !solved){
        Maze -> solve_maze(0, 0);
        solved = true;
    }
}
