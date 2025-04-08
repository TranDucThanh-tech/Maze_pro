#include "0_1_menu.h"

menu::menu(SDL_Renderer* renderer, TTF_Font* font, SoundEffect* Sound) :
    renderer(renderer),  font(font), Sound(Sound), play_clicked(false),setting_clicked(false) {
    Play = new Button((win_hight-200)/2, (win_width-50)/2 - 55, 200, 50, renderer, purple);
    Setting = new Button((win_hight-200)/2, (win_width-50)/2 , 200, 50, renderer, purple);
    Quit = new Button((win_hight-200)/2, (win_width-50)/2 + 55, 200, 50, renderer, purple);
}

menu::~menu() {
    if(Play){
        delete Play;
        Play = nullptr;
    }
    if(Setting){
        delete Setting;
        Setting = nullptr;
    }
    if(Quit) {
        delete Quit;
        Quit = nullptr;
    }
}

bool menu::play_clicked_() {
    return play_clicked;
}

bool menu::setting_clicked_(){
    return setting_clicked;
}


void menu::handle_event(SDL_Event& event) {

    SDL_SetRenderDrawColor(renderer,0, 0, 0, 255);
    SDL_RenderClear(renderer);

    Setting->render_button("SETTING", font);
    Play->render_button("PLAY", font);
    Quit->render_button("QUIT", font);

    if (event.type == SDL_MOUSEMOTION) {
        Play -> check_button_hover(event.motion.x, event.motion.y);
        Setting -> check_button_hover(event.motion.x, event.motion.y);
        Quit -> check_button_hover(event.motion.x, event.motion.y);
        return;
    }

    if (event.type == SDL_MOUSEBUTTONDOWN){
        Sound -> loadFromFile("click.wav");
        if (Play && Play -> is_hovered_()
            && event.button.button == SDL_BUTTON_LEFT) {
            Sound -> play();
            SDL_Delay(100);
            play_clicked = true;
            SDL_SetRenderDrawColor(renderer,0, 0, 0, 255);
            SDL_RenderClear(renderer);
        }
        else if (Setting && Setting -> is_hovered_()
            && event.button.button == SDL_BUTTON_LEFT){
            Sound -> play();
            SDL_Delay(100);
            setting_clicked = true;
            SDL_SetRenderDrawColor(renderer,0, 0, 0, 255);
            SDL_RenderClear(renderer);
        }
        else if (Quit && Quit -> is_hovered_()
            && event.button.button == SDL_BUTTON_LEFT){
            Sound -> play();
            SDL_Delay(500);
            SDL_Event event;
            event.type = SDL_QUIT;
            SDL_PushEvent(&event);
        }
    }
}




