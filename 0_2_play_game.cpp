#include "0_2_play_game.h"

play_game :: play_game(SDL_Renderer* renderer){
    Maze = new maze(row_size ,col_size, cell_size ,renderer);
    Player = new player(0, 0, Maze,renderer);

}

play_game :: ~play_game(){
    delete Maze;
    delete Player;
}
void play_game :: handle_event(SDL_Event& event){
    Maze -> handle_event(event);
    Player -> handle_event(event);
}

void play_game :: render(){
    cout << "hello";
}


