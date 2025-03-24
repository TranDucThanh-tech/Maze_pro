#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include "0_0_game_state.h"

class menu : public game_state{
private:
    TTF_Font* font;
    SDL_Rect player_button;
    SDL_Rect setting_button;
    bool player_hovered, setting_hovered;
    bool player_clicked, setting_clicked;
    SDL_Renderer* renderer;
    SDL_Color setting_coler;
    SDL_Surface* setting_surface;
    SDL_Texture* setting_texture;

public:
    menu();
    menu(bool player_hovered, bool setting_hovered,
        bool player_clicked, bool setting_clicked,
        SDL_Renderer* renderer);
    ~menu();

    bool is_mouse_in_rect(int x, int y, SDL_Rect rect);

    void handle_event(SDL_Event& event) override;
    void update() override;
    void render(SDL_Renderer* renderer) override;
};


#endif // MENU_H
