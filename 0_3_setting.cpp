#include "0_3_setting.h"

setting :: setting(SDL_Renderer* renderer) : renderer(renderer) {
    SOUNDS = new Button((win_hight-200)/2, (win_width-50)/2 - 55, 200, 50, renderer, green);
    MUSIC = new Button((win_hight-200)/2, (win_width-50)/2 , 200, 50, renderer, green);
    BACK = new Button((win_hight-200)/2, (win_width-50)/2 + 55, 200, 50, renderer, green);

    if (TTF_Init() == -1)
        std::cerr << "SDL_ttf can not init " << TTF_GetError() << endl;

    font = TTF_OpenFont("Arial.ttf", 24);
}

setting :: ~setting(){
    if (font) {
        TTF_CloseFont(font);
        font = nullptr;
    }
    if(SOUNDS) delete SOUNDS;
    if(MUSIC) delete MUSIC;
    if(BACK) delete BACK;
}

void setting ::  handle_event(SDL_Event& event){
    SDL_SetRenderDrawColor(renderer,0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SOUNDS->render_button("SOUNDS", font);
    MUSIC->render_button("MUSIC", font);
    BACK -> render_button("BACK", font);

    if (event.type == SDL_MOUSEMOTION) {
        SOUNDS->check_button_hover(event.motion.x, event.motion.y);
        BACK ->check_button_hover(event.motion.x, event.motion.y);
        MUSIC->check_button_hover(event.motion.x, event.motion.y);
        return;
    }


    if (event.type == SDL_MOUSEBUTTONDOWN){
        /*if (SOUNDS && SOUNDS -> is_hovered_()
            && event.button.button == SDL_BUTTON_LEFT) {

            }
        else if (MUSIC && MUSIC -> is_hovered_()
            && event.button.button == SDL_BUTTON_LEFT){

            }
        return;*/
        if (BACK && BACK -> is_hovered_()){
            SDL_Event event;
            event.type = SDL_KEYDOWN;
            event.key.keysym.sym = SDLK_m;
            event.key.state = SDL_PRESSED;
            event.key.repeat = 0;
            SDL_PushEvent(&event);
        }
    }
}




