#include "0_1_menu.h"

menu::menu(SDL_Renderer* renderer) : play_clicked(false) {
    this->renderer = renderer;
    if (TTF_Init() == -1)
        std::cerr << "SDL_ttf can not init " << TTF_GetError() << endl;
    font = TTF_OpenFont("Arial.ttf", 24);
    Play = new Button((win_hight-200)/2, (win_width-50)/2, 200, 50, renderer, yellow);

}

menu::~menu() {
    delete Play;
    if (font) {
        TTF_CloseFont(font);
        font = nullptr;
    }
}

bool menu::play_clicked_() {
    return play_clicked;
}



void menu::render() {
    if (Play) {
        Play->render_button("Play", font);
    }
    SDL_RenderPresent(renderer);
}




void menu::handle_event(SDL_Event& event) {
    SDL_SetRenderDrawColor(renderer,0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    Play->render_button("Play", font);
    SDL_RenderPresent(renderer);
    if (event.type == SDL_MOUSEMOTION) {
        Play->check_button_hover(event.motion.x, event.motion.y);
        return;
    }

    if (event.type == SDL_MOUSEBUTTONDOWN){
        if (Play && Play -> is_hovered_()
            && event.button.button == SDL_BUTTON_LEFT) {
            play_clicked = true;
            SDL_SetRenderDrawColor(renderer,0, 0, 0, 0);
            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);
            }
        return;
    }
}




