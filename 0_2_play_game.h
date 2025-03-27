#ifndef PLAY_GAME_H
#define PLAY_GAME_H
#include "1_maze.h"
#include "1_player.h"
#include "0_0_game_state.h"
using namespace std;

class play_game : public game_state{
private:
    maze* Maze;
    player* Player;
    SDL_Renderer* renderer;
public:
    play_game(SDL_Renderer* renderer);
    ~play_game();
    void handle_event(SDL_Event& event) override;
    void render() override;
};
#endif // PLAY_GAME_H
