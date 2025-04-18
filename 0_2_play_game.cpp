#include "0_2_play_game.h"

play_game :: play_game(SDL_Renderer* renderer, TTF_Font* font, SoundEffect* Sound, Time* time, bool* is_playing){
    Maze = new maze(renderer, font, Sound);
    Player = new player(Maze,renderer, font, Sound, time, is_playing);
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



