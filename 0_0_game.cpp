#include"0_0_game.h"
#include"3_Time.h"
game::game() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL Initialization Error: " << SDL_GetError() << endl;
        return;
    }
    if (TTF_Init() < 0){
       cout << "SDL_ttf can not init " << TTF_GetError() << endl;
       return;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return;
    }
    window = SDL_CreateWindow(
        "Maze Generator",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        win_width, win_hight,
        SDL_WINDOW_SHOWN
    );
    if (!window) {
        cout << "Window Creation Error:" << SDL_GetError() << endl;
        SDL_Quit();
        return ;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        cout << "Renderer Creation Error: " << SDL_GetError() << endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return ;
    }
    font = TTF_OpenFont("Arial.ttf", 24);
    if (!font){
     cout << "Font Creation Error:" << TTF_GetError() << endl;
     SDL_Quit();
     return ;
    }
    is_playing = new bool;
    *is_playing = false;
    running = true;
    Music = new MusicTheme();
    Sound = new SoundEffect();
    Game_state = new menu(renderer,font, Sound);
    time = new Time(renderer, font);
}

game::~game() {
    if (Game_state) {
        delete Game_state;
        Game_state = nullptr;
    }
    if (Music) {
        Music->stop();
        delete Music;
        Music = nullptr;
    }
    if (Sound){
        Sound -> stop();
        delete Sound;
        Sound = nullptr;
    }
    if (time){
        delete time;
        time = nullptr;
    }
    if(is_playing){
        delete is_playing;
        is_playing = nullptr;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    Mix_Quit();
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();

}

void game::set_state(game_state* state) {
    if (Game_state != nullptr) {
        delete Game_state;
        Game_state = nullptr;
    }
    this->Game_state = state;
}

void game::handle_event(SDL_Event& event) {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
            break;
        }
        Game_state->handle_event(event);

        if (auto Menu = dynamic_cast<menu*>(Game_state)) {
            if (Menu->play_clicked_())
                set_state(new play_game(renderer, font, Sound, time, is_playing));
            else if (Menu->setting_clicked_())
                set_state(new setting(renderer, font, Music, Sound));
        }
        if (dynamic_cast<setting*>(Game_state)) {
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_m)
                set_state(new menu(renderer, font, Sound));
        }
        if (dynamic_cast<play_game*>(Game_state)) {
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_m) {
                set_state(new menu(renderer, font, Sound));
            }
        }
    }
}

void game::run() {
    Mix_VolumeMusic(30);
    Music->play("Theme.mp3");
    SDL_Event event;
    while (running){
        handle_event(event);
        SDL_RenderPresent(renderer);
        if(!(*is_playing)) continue;
        time -> update_current_time();
        time -> render_current_time(30, win_hight - 50);
        time -> render_best_time(win_width - 250, win_hight - 50);
    }
}
