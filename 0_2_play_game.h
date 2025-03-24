#ifndef PLAY_GAME_H
#define PLAY_GAME_H
#include "0_1_menu.h"

class play_game : public game_state{
private:
    menu* Menu;
    maze* Maze;
    player* Player;
public:
    void handle_event(SDL_Event& event) override;
    virtual void update() override;
    virtual void render(SDL_Renderer* renderer) override;
};
#endif // PLAY_GAME_H
