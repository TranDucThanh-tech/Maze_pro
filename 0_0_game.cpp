#include "0_0_game.h"
#include <iostream>
game :: game()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cerr << "SDL Initialization Error: " << SDL_GetError() << endl;
        exit(1);
    }
    window = SDL_CreateWindow(
        "Maze Generator",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        win_width, win_hight,
        SDL_WINDOW_SHOWN
    );
    if (!window) {
        cerr << "Window Creation Error:"<< SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        cerr << "Renderer Creation Error: " << SDL_GetError() << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(1);
    }

    running = true;

    Game_state = new menu(renderer);

    cout << "thanhcong" << endl;
}

void game :: reset(){
    SDL_SetRenderDrawColor(renderer,0, 128, 128, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

game:: ~game(){
    if (Game_state)
        delete Game_state;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


void game :: set_state(game_state* state){
    if (Game_state != nullptr){
        delete Game_state;
    }
    this->Game_state = state;
}


void game :: render(){
    if (Game_state == nullptr)
        return;
    Game_state -> render();
}

void game::handle_event(SDL_Event& event) {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
            break;

        }
        Game_state -> handle_event(event);

        if (auto Menu = dynamic_cast<menu*>(Game_state)){
            if ( Menu -> play_clicked_())
                set_state(new play_game(renderer));
            else if (Menu -> setting_clicked_())
                set_state(new setting(renderer));
        }

        else if (dynamic_cast<setting*>(Game_state)){
            if ( event.type == SDL_KEYDOWN &&
                event.key.keysym.sym == SDLK_m)
                set_state(new menu(renderer));
        }

        else if (dynamic_cast<play_game*>(Game_state)){
            if ( event.type == SDL_KEYDOWN &&
                event.key.keysym.sym == SDLK_m)
                set_state(new menu(renderer));
        }
        render();
        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
}


void game :: run(){
    SDL_Event event;
    while(running){
        handle_event(event);
    }
    cout <<"hello" << endl;
}




