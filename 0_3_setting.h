#ifndef SETIING_H
#define SETTING_H
#include "Button.h"
#include "0_0_game_state.h"
#include "Maze_size.h"

class setting : public game_state{
private:
    Button* SOUNDS;
    Button* MUSIC;
    SDL_Renderer* renderer;
    TTF_Font* font;
public:
    setting(SDL_Renderer* renderer);
    ~setting();
    void handle_event(SDL_Event& event) override;
    void render() override;
};

#endif // SETIING_H
