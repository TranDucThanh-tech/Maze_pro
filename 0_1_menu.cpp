#include "0_1_menu.h"

menu::menu(SDL_Renderer* renderer) :  renderer(renderer), play_clicked(false),setting_clicked(false) {
    if (TTF_Init() == -1)
       cerr << "SDL_ttf can not init " << TTF_GetError() << endl;
    font = TTF_OpenFont("Arial.ttf", 24);
    Play = new Button((win_hight-200)/2, (win_width-50)/2 - 55, 200, 50, renderer, purple);
    Setting = new Button((win_hight-200)/2, (win_width-50)/2 , 200, 50, renderer, purple);
    Quit = new Button ((win_hight-200)/2, (win_width-50)/2 + 55, 200, 50, renderer, purple);
}

menu::~menu() {
    if (font) {
        TTF_CloseFont(font);
        font = nullptr;
    }
    if(Play) delete Play;
    if(Setting) delete Setting;
    if(Quit) delete Quit;
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
        if (Play && Play -> is_hovered_()
            && event.button.button == SDL_BUTTON_LEFT) {
            play_clicked = true;
            SDL_SetRenderDrawColor(renderer,0, 0, 0, 255);
            SDL_RenderClear(renderer);
            return;
            }
        if (Setting && Setting -> is_hovered_()
            && event.button.button == SDL_BUTTON_LEFT){
            setting_clicked = true;
            SDL_SetRenderDrawColor(renderer,0, 0, 0, 255);
            SDL_RenderClear(renderer);
            return;
            }
        if (Quit && Quit -> is_hovered_()
            && event.button.button == SDL_BUTTON_LEFT){
            SDL_Event event;
            event.type = SDL_QUIT;
            SDL_PushEvent(&event);
            return;
            }
    }
}




