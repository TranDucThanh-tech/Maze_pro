#ifndef MENU_H
#define MENU_H

#include<iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "0_0_game_state.h"
#include "Button.h"
#include "SDL_Color.h"
#include "Maze_size.h"
#include "Music.h"

class menu : public game_state{
private:
    Button* Play;
    Button* Setting;
    Button* Quit;
    TTF_Font* font;
    SDL_Renderer* renderer;
    bool play_clicked;
    bool setting_clicked;
public:

    menu(SDL_Renderer* renderer);
    ~menu();
    bool play_clicked_();
    bool setting_clicked_();
    void check_button_hover(Button* btn, int mouse_x, int mouse_y);
    void handle_event(SDL_Event& event) override;
};
#endif // MENU_H
