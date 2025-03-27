#include "Button.h"
Button :: Button(int x, int y, int w, int h, SDL_Renderer* renderer, SDL_Color yellow){
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    this->renderer = renderer;
    color = yellow;
    is_hovered = false;
}

Button :: ~Button(){
    if (font) {
        TTF_CloseFont(font);
        font = nullptr;
    }
}


bool Button :: is_hovered_(){
     return is_hovered;
}

void Button :: check_button_hover(int mouse_x, int mouse_y){
    is_hovered = is_hovered = (mouse_x >= rect.x && mouse_x < rect.x + rect.w &&
              mouse_y >= rect.y && mouse_y < rect.y + rect.h);
}


void  Button :: render_button(const char* text){
    // Vẽ nền nút
    if (is_hovered) {
        SDL_SetRenderDrawColor(renderer,
                            color.r + 30,
                            color.g + 30,
                            color.b + 30,
                            color.a);
    } else {
        SDL_SetRenderDrawColor(renderer,
                            color.r,
                            color.g,
                            color.b,
                            color.a);
    }
    SDL_RenderFillRect(renderer, &rect);

    // Vẽ viền nút
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &rect);

    // Vẽ chữ trên nút
    if (font && text) {
        SDL_Color text_color = {255, 255, 255, 255};
        SDL_Surface* surface = TTF_RenderText_Solid(font, text, text_color);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

        SDL_Rect text_rect = {
            rect.x + (rect.w - surface->w) / 2,
            rect.y + (rect.h - surface->h) / 2,
            surface->w,
            surface->h
        };

        SDL_RenderCopy(renderer, texture, NULL, &text_rect);

        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }
}





