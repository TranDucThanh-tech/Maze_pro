#include "1_player.h"
const int win = 1;
const int lose = 0;
const int undetermined = 2;

player::player(int x, int y, maze* Maze, SDL_Renderer* renderer, TTF_Font* font, SoundEffect* Sound)
    : x(x), y(y), Maze(Maze), renderer(renderer), font(font), Sound(Sound) {
    now_playing = false;
    solved = false;
    is_win = undetermined;
    Win = new Button((win_hight-300)/2, (win_width-70)/2 , 300, 70, renderer, orange);
    Lose = new Button((win_hight-300)/2, (win_width-70)/2  , 300, 70, renderer, gray);
}

player :: ~player(){
    if (Win) {
        delete Win;
        Win = nullptr;
    }
    if (Lose) {
        delete Lose;
        Lose = nullptr;
    }
}

void player :: move_player(string direction){
    SDL_Color white = { 255, 255, 255, 255 };
    SDL_Color black = {0, 0, 0, 255 };
    Maze -> draw_cell(renderer, x, y, black, cell_size);
    int new_row = x, new_col = y;
    if(direction == "right") new_col +=2;
    else if(direction == "left") new_col -=2;
    else if(direction == "down") new_row +=2;
    else if (direction == "up") new_row -=2;

    if (new_row >= 0 && new_row < row_size &&
        new_col >= 0 && new_col < col_size &&
        Maze -> way[new_row][new_col] == 1 &&
        Maze -> way[(new_row+x)/2][(new_col+y)/2] != 0){

        x = new_row;
        y = new_col;
    }
    Maze -> draw_cell(renderer, x, y, white, cell_size);
    SDL_RenderPresent(renderer);
}

void player :: reset(){
    x = 0;
    y = 0;
}

bool player :: is_end(){
    return (x == row_size-1 && y == col_size-1);
}


void player::handle_event(SDL_Event& event) {
    if (!Maze -> is_finish_()) return;
    if (!solved){
        if (!now_playing) Maze -> draw_cell(renderer, x, y, white, cell_size);
        Maze -> draw_cell(renderer, row_size - 1, col_size -1, red,  cell_size);
        if (event.type == SDL_KEYDOWN){
            if(event.key.repeat != 0) return;
            Sound -> loadFromFile("move.wav");
            switch (event.key.keysym.sym) {
                case SDLK_RIGHT:
                    Sound -> play();
                    SDL_Delay(50);
                    move_player("right");
                    now_playing = true;
                    return;
                case SDLK_LEFT:
                    Sound -> play();
                    SDL_Delay(50);
                    move_player("left");
                    now_playing = true;
                    return;
                case SDLK_DOWN:
                    Sound -> play();
                    SDL_Delay(50);
                    move_player("down");
                    now_playing = true;
                    return;
                case SDLK_UP:
                    Sound -> play();
                    SDL_Delay(50);
                    move_player("up");
                    now_playing = true;
                    return;

                case SDLK_HOME:
                    Sound -> play();
                    SDL_Delay(50);
                    Maze -> draw_cell(renderer, x, y, black, cell_size);
                    SDL_RenderPresent(renderer);
                    reset();
                    Maze -> draw_cell(renderer, x, y, white,  cell_size);
                    return;

                case SDLK_RETURN:
                    Maze -> draw_cell(renderer, x, y, black, cell_size);
                    SDL_RenderPresent(renderer);
                    Maze -> solve_maze(0, 0);
                    solved = true;
                    is_win = lose;
                    Lose -> render_button("YOU LOSE", font);
                    Sound -> loadFromFile("lose.wav");
                    Sound -> play();
                    SDL_Delay(100);
                    return;

                default:
                    return;
            }
        }
        if(is_end()){
            Maze -> solve_maze(0, 0);
            solved = true;
            is_win = win;
            Win -> render_button("YOU WIN", font);
            Sound -> loadFromFile("win.wav");
            Sound -> play();
            SDL_Delay(100);
            return;
        }
    }

    else{
        if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN){
            if (is_win == win){
                Win -> check_button_hover(event.motion.x, event.motion.y);
                Win -> render_button("YOU WIN", font);
                if (Win && Win->is_hovered_() && event.button.button == SDL_BUTTON_LEFT){
                    Sound -> loadFromFile("click.wav");
                    Sound -> play();
                    SDL_Delay(100);

                    SDL_Event event;
                    event.type = SDL_KEYDOWN;
                    event.key.keysym.sym = SDLK_m;
                    event.key.state = SDL_PRESSED;
                    event.key.repeat = 0;
                    SDL_PushEvent(&event);
                }
            }
            else if (is_win == lose){
                Lose -> check_button_hover(event.motion.x, event.motion.y);
                Lose -> render_button("YOU LOSE", font);
                if (Lose && Lose->is_hovered_() && event.button.button == SDL_BUTTON_LEFT){
                    Sound -> loadFromFile("click.wav");
                    Sound -> play();
                    SDL_Delay(100);

                    SDL_Event event;
                    event.type = SDL_KEYDOWN;
                    event.key.keysym.sym = SDLK_m;
                    event.key.state = SDL_PRESSED;
                    event.key.repeat = 0;
                    SDL_PushEvent(&event);
                }
            }
        }
    }
}
