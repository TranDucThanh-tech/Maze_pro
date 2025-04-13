#ifndef PLAY_GAME_H
#define PLAY_GAME_H

#include "0_0_game_state.h"
#include "1_maze.h"
#include "1_player.h"
#include "4_Const_Maze_size.h"

using namespace std;

class play_game : public game_state{
private:
    maze* Maze;
    player* Player;

public:
    play_game(SDL_Renderer* renderer, TTF_Font* font, SoundEffect* Sound);
    ~play_game();
    void handle_event(SDL_Event& event) override;
};
#endif // PLAY_GAME_H
