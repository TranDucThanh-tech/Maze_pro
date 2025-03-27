#include "0_2_play_game.h"

play_game :: play_game(SDL_Renderer* renderer){
    Maze = new maze(31,31,10,renderer);
    Player = new player(0, 0, Maze,renderer);
}

play_game :: ~play_game(){
    delete Maze;
    delete Player;
}
void play_game :: handle_event(SDL_Event& event){
     switch (event.type) {
        case SDL_KEYDOWN:
            Maze -> handle_event(event);
            Player -> handle_event(event);
    }
}

void play_game :: render(){
    cout << "hello";
}
