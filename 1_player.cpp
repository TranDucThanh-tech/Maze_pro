#include "1_player.h"

player::player(maze* Maze, SDL_Renderer* renderer, TTF_Font* font, SoundEffect* Sound, Time* time, bool* is_playing)
    : Maze(Maze), renderer(renderer), font(font), Sound(Sound), time(time), is_playing(is_playing){
    x = START_ROW;
    y = START_COL;
    solved = false;
    result = UNDETERMINED;
    Win = new Button((win_width-300) >> 1, (win_hight-70) >> 1 , 300, 90, renderer, orange);
    Lose = new Button((win_width-300) >> 1, (win_hight-70) >> 1 , 300, 90, renderer, gray);
    Record = new Button((win_width-400) >> 1, (win_hight-120) >> 1 , 400, 120, renderer, orange);
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
    if(Record){
        delete Record;
        Record = nullptr;
    }
}


void player :: move_player(const string& direction){
    Maze -> draw_cell(renderer, x, y, black);
    int new_row = x, new_col = y;
    if(direction == "right") new_col +=2;
    else if(direction == "left") new_col -=2;
    else if(direction == "down") new_row +=2;
    else if (direction == "up") new_row -=2;

    if (new_row >= 0 && new_row < row_size &&
        new_col >= 0 && new_col < col_size &&
        Maze -> way[new_row][new_col] == 1 &&
        Maze -> way[(new_row+x) >> 1][(new_col+y) >> 1] != 0){

        x = new_row;
        y = new_col;
    }
    Maze -> draw_cell(renderer, x, y, white);
    SDL_RenderPresent(renderer);
}

void player :: reset(){
    Maze->draw_cell(renderer, x, y, black);
    x = START_ROW;
    y = START_COL;
    Maze->draw_cell(renderer, x, y, white);
}

bool player :: is_end() const{
    return (x == row_size-2 && y == col_size-2);
}


void player::handle_event(SDL_Event& event) {
    if (!Maze->is_finish_()) return;
    if (!solved) {
        bool playing = *is_playing;
        if (!playing)
            Maze->draw_cell(renderer, x, y, white);
        Maze->draw_cell(renderer, row_size - 2, col_size - 2, red);

        if (event.type == SDL_KEYDOWN) {
            if (event.key.repeat != 0) return;
            if (!playing) {
                time->start();
                *is_playing = true;
            }
            Sound->loadFromFile("move.wav");
            Sound->play();
            switch (event.key.keysym.sym) {
                case SDLK_RIGHT: move_player("right"); break;
                case SDLK_LEFT:  move_player("left");  break;
                case SDLK_DOWN:  move_player("down");  break;
                case SDLK_UP:    move_player("up");    break;
                case SDLK_HOME:  reset(); break;
                case SDLK_RETURN:
                    *is_playing = false;
                    solved = true;
                    result = LOSE;
                    time->stop();

                    Maze->draw_cell(renderer, x, y, black);
                    Maze->solve_maze(START_ROW, START_COL, START_ROW, START_COL);

                    Lose->render_button("YOU LOSE", font);
                    Sound->loadFromFile("lose.wav");
                    Sound->play();
                    break;

                default: break;
            }
            return;
        }

        if (is_end()) {
            time->stop();
            Maze->solve_maze(START_ROW, START_COL, START_ROW, START_COL);
            solved = true;
            *is_playing = false;
            Sound->loadFromFile("win.wav");
            Sound->play();

            if(time -> update_best_time()){
                result = RECORD;
                Record -> render_button("NEW RECORD", font);
            }
            else{
                result = WIN;
                Win->render_button("YOU WIN", font);
            }
            return;
        }
    }
    else {
        if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
            Button* current = nullptr;
            const char* text = "";
            switch (result) {
                case WIN:
                    current = Win;
                    text = "YOU WIN";
                    break;
                case LOSE:
                    current = Lose;
                    text = "YOU LOSE";
                    break;
                case RECORD:
                    current = Record;
                    text = "NEW RECORD";
                    break;
                default:
                    break;
            }
            current->check_button_hover(event.motion.x, event.motion.y);
            current->render_button(text, font);
            if (current->is_hovered_() && event.button.button == SDL_BUTTON_LEFT) {
                Sound->loadFromFile("click.wav");
                Sound->play();
                while (Mix_Playing(-1)) {
                    SDL_Delay(10);
                }
                SDL_Event new_event;
                new_event.type = SDL_KEYDOWN;
                new_event.key.keysym.sym = SDLK_m;
                new_event.key.state = SDL_PRESSED;
                new_event.key.repeat = 0;
                SDL_PushEvent(&new_event);
            }
        }
    }
}
