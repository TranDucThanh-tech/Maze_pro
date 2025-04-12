#include "3_Button.h"
#include <iostream>
Button :: Button(int x, int y, int w, int h,
            SDL_Renderer* renderer, SDL_Color color) : renderer(renderer), color(color) {
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    is_hovered = false;
}

Button :: ~Button(){}


bool Button :: is_hovered_(){
     return is_hovered;
}


void Button :: check_button_hover(int mouse_x, int mouse_y){
    is_hovered = (mouse_x >= rect.x && mouse_x < rect.x + rect.w &&
              mouse_y >= rect.y && mouse_y < rect.y + rect.h);
}


void  Button :: render_button(const char* text, TTF_Font* font){

    if (is_hovered) {
        SDL_SetRenderDrawColor(renderer,
                            color.r + 50,
                            color.g + 50,
                            color.b,
                            color.a);
    }
    else {
        SDL_SetRenderDrawColor(renderer,
                            color.r,
                            color.g,
                            color.b,
                            color.a);
    }
    SDL_RenderFillRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &rect);

    if (font && text) {
        SDL_Color text_color = {0, 0, 0, 255};
        SDL_Surface* surface = TTF_RenderText_Solid(font, text, text_color);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

        SDL_Rect text_rect = {
            rect.x + ((rect.w - surface->w) >> 1),
            rect.y + ((rect.h - surface->h) >> 1),
            surface->w,
            surface->h
        };

        SDL_RenderCopy(renderer, texture, NULL, &text_rect);

        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }
}

void Button :: render_button_music(const char* text,  TTF_Font*font, bool is_off){
    SDL_Color current_color = is_off ? earthy_orange : purple;
    if (is_hovered) {
        SDL_SetRenderDrawColor(renderer,
                            current_color.r + 50,
                            current_color.g + 50,
                            current_color.b,
                            current_color.a);
    }
    else {
        SDL_SetRenderDrawColor(renderer,
                            current_color.r,
                            current_color.g,
                            current_color.b,
                            current_color.a);
    }
    SDL_RenderFillRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &rect);

    if (font && text) {
        SDL_Color text_color = {0, 0, 0, 255};
        SDL_Surface* surface = TTF_RenderText_Solid(font, text, text_color);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

        SDL_Rect text_rect = {
            rect.x + ((rect.w - surface->w) >> 1),
            rect.y + ((rect.h - surface->h) >> 1),
            surface->w,
            surface->h
        };

        SDL_RenderCopy(renderer, texture, NULL, &text_rect);

        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }
}










