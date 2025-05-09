#include "0_3_setting.h"

setting :: setting(SDL_Renderer* renderer,TTF_Font* font, MusicTheme* Music, SoundEffect* Sound) :
    renderer(renderer),font(font), Music(Music), Sound(Sound) {
    SOUNDS = new Button((win_width-200)/2, (win_hight-50)/2 - 55, 200, 50, renderer, purple);
    MUSIC = new Button((win_width-200)/2, (win_hight-50)/2 , 200, 50, renderer, purple);
    BACK = new Button((win_width-200)/2, (win_hight-50)/2 + 55, 200, 50, renderer, purple);
    Sound -> loadFromFile("click.wav");
}

setting :: ~setting(){
    if(SOUNDS){
        delete SOUNDS;
        SOUNDS = nullptr;
    }
    if(MUSIC){
        delete MUSIC;
        MUSIC = nullptr;
    }
    if(BACK){
        delete BACK;
        BACK = nullptr;
    }
}

void setting ::  handle_event(SDL_Event& event){

    SOUNDS->render_button_music("SOUNDS", font, Sound -> is_off_());
    MUSIC->render_button_music("MUSIC", font, Music -> is_off_());
    BACK -> render_button("BACK", font);

    if (event.type == SDL_MOUSEMOTION) {
        SOUNDS->check_button_hover(event.motion.x, event.motion.y);
        BACK ->check_button_hover(event.motion.x, event.motion.y);
        MUSIC->check_button_hover(event.motion.x, event.motion.y);
        return;
    }


    if (event.type == SDL_MOUSEBUTTONDOWN){
        if (MUSIC && MUSIC -> is_hovered_()
            && event.button.button == SDL_BUTTON_LEFT){
            Sound -> play();
            while (Mix_Playing(-1)) {
                SDL_Delay(10);
            }
            Music -> pause_resume();
        }
        else if (SOUNDS && SOUNDS -> is_hovered_()
            && event.button.button == SDL_BUTTON_LEFT) {
            Sound -> play();
            while (Mix_Playing(-1)) {
                SDL_Delay(10);
            }
            Sound -> pause_resume();
        }
        else if (BACK && BACK -> is_hovered_()){

            Sound->play();
            while (Mix_Playing(-1)) {
                SDL_Delay(10);
            }
            SDL_Event event;
            event.type = SDL_KEYDOWN;
            event.key.keysym.sym = SDLK_m;
            event.key.state = SDL_PRESSED;
            event.key.repeat = 0;
            SDL_PushEvent(&event);
        }
        return;
    }
}




