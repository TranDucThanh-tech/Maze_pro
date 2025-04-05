#include "0_2_play_game.h"

play_game :: play_game(SDL_Renderer* renderer){
    Maze = new maze(row_size ,col_size, cell_size ,renderer);
    Player = new player(0, 0, Maze,renderer);

}

play_game :: ~play_game(){
    if (Maze) {
        delete Maze;
        Maze = nullptr;
    }
    if (Player) {
        delete Player;
        Player = nullptr;
    }
}

void play_game :: handle_event(SDL_Event& event){
    Maze -> handle_event(event);
    Player -> handle_event(event);
}



