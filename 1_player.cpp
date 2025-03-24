#include "1_player.h"

player::player(int x, int y, maze* Maze, SDL_Renderer* renderer)
    : x(x), y(y), Maze(Maze), renderer(renderer) {

}

void player :: move_player(string direction){
    SDL_Color white = { 255, 255, 255, 255 };
    SDL_Color black = {0, 0, 0, 255 };
    Maze -> draw_cell(renderer, x, y, black, Maze -> cell_size);
    int new_row = x, new_col = y;
    if(direction == "right") new_col ++;
    else if(direction == "left") new_col --;
    else if(direction == "down") new_row ++;
    else if (direction == "up") new_row --;

    if (new_row >= 0 && new_row < 31 &&
        new_col >= 0 && new_col < 31 &&
        Maze -> way[new_row][new_col] == 1){

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

void player::handle_event(SDL_Event& event) {
    if(event.key.repeat != 0) return;
    switch (event.key.keysym.sym) {
        case SDLK_RIGHT: move_player("right"); return;
        case SDLK_LEFT: move_player("left"); return;
        case SDLK_DOWN: move_player("down"); return;
        case SDLK_UP: move_player("up"); return;
        case SDLK_1:
        case SDLK_2:
        case SDLK_HOME:
            Maze -> draw_cell(renderer, x, y, black, Maze -> cell_size);
            SDL_RenderPresent(renderer);
            reset();
            return;
        default:
            return;
    }
}
