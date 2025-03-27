#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "0_0_game_state.h"
#include "Button.h"
#include "SDL_Color.h"

class menu : public game_state{
private:
    Button* Play;
    Button* Setting;
    SDL_Renderer* renderer;
    bool play_clicked;
public:

    menu(SDL_Renderer* renderer);
    ~menu();
    bool play_clicked_();
    void check_button_hover(Button* btn, int mouse_x, int mouse_y);
    void render() override;
    void handle_event(SDL_Event& event) override;
};
#endif // MENU_H
