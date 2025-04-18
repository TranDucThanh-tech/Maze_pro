#include "3_Time.h"

Time :: Time(SDL_Renderer* renderer, TTF_Font* font):
     renderer(renderer), font(font),  start_time(0), current_time(0){
    ifstream inFile("highscore.txt");
    if (inFile.is_open()) {
        inFile >> best_time;
        inFile.close();
    }
}


void Time:: start() {
    start_time = SDL_GetTicks();
}

void Time:: stop() {
    start_time = 0;
}

bool Time::update_best_time() {
    if (current_time < best_time) {
        best_time = current_time;
        ofstream outFile("highscore.txt");
        if (outFile.is_open()) {
            outFile << best_time;
            outFile.close();
        }
        return true;
    }
    return false;
}



void Time:: update_current_time(){
    current_time = (SDL_GetTicks() - start_time) / 1000;
}


void Time :: render_current_time(const int x,const int y) const {
    string timeStr = "Time:" + to_string(current_time) + "s";

    SDL_Surface* surface = TTF_RenderText_Solid(font, timeStr.c_str(), white);
    if (!surface) {
        printf("can not init surface: %s\n", TTF_GetError());
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        printf("can not init texture: %s\n", SDL_GetError());
        SDL_FreeSurface(surface);
        return;
    }
    SDL_Rect rect = {x, y, surface->w, surface->h};
    SDL_SetRenderDrawColor(renderer, purple.r, purple.g, purple.b, purple.a);
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderCopy(renderer, texture, nullptr, &rect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

void Time :: render_best_time(const int x,const int y) const{
    string timeStr = "record:" + to_string(best_time) + "s";
    SDL_Surface* surface = TTF_RenderText_Solid(font, timeStr.c_str(), white);
    if (!surface) {
        printf("can not init surface: %s\n", TTF_GetError());
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        printf("can not init texture: %s\n", SDL_GetError());
        SDL_FreeSurface(surface);
        return;
    }
    SDL_Rect rect = {x, y, surface->w, surface->h};
    SDL_SetRenderDrawColor(renderer, purple.r, purple.g, purple.b, purple.a);
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderCopy(renderer, texture, nullptr, &rect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

