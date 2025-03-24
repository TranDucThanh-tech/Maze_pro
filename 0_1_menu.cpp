#include "0_1_menu.h"

menu :: menu(bool player_hovered, bool setting_hovered,
            bool player_clicked, bool setting_clicked,
            SDL_Renderer* renderer) :
                player_hovered(player_hovered),
                setting_hovered(setting_hovered),
                player_clicked(player_clicked),
                setting_clicked(setting_clicked),
                renderer(renderer)
{
        TTF_Font* font = TTF_OpenFont("arial.ttf",48);
        if (!font) {
            printf("Failed to load font: %s\n", TTF_GetError());
            exit(1);
        }
}


bool menu :: is_mouse_in_rect(int x, int y, SDL_Rect rect){
        return(x >= rect.x && x <= rect.x + rect.w &&
               y >= rect.y && y <= rect.y + rect.h);
}

void menu :: handle_event(SDL_Event& event){

}


