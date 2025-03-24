#include "0_game.h"

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
        31*10, 31*10,
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
    Maze = new maze(31,31,10,renderer);
    Player = new player(0, 0, Maze,renderer);
    cout << "thanhcong" << endl;
}

void game :: reset(){
    SDL_SetRenderDrawColor(renderer,0, 128, 128, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    Player -> reset();
    Maze -> reset();
}

game:: ~game(){
    delete Player;
    delete Maze;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void game::handle_event(SDL_Event& event) {
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;

            case SDL_KEYDOWN:
                Maze->handle_event(event);
                Player->handle_event(event);
                break;
        }
    }
}




void game :: run(){
    SDL_Event event;
    while(running){
        handle_event(event);
    }
}


