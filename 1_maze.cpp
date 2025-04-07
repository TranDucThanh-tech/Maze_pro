#include "1_maze.h"


maze :: maze(int row_size, int col_size, int cell_size, SDL_Renderer* renderer, TTF_Font* font, SoundEffect* Sound):
    renderer(renderer),font(font), Sound(Sound), col_size(col_size), row_size(row_size),cell_size(cell_size){
    this->row = 20;
    this->col = 20;
    this->Type_maze = nullptr;
    now_playing = false;
    visited = vector<vector<bool>>(row_size, vector<bool>(col_size, false));
    way = vector<vector<int>>(row_size, vector<int>(col_size, 0));

    int y_offset = (win_hight - 200) / 2 - 65;
    DFS = new Button((win_width - 200) / 2, y_offset + 55 , 200, 50, renderer, purple);
    PRIM = new Button((win_width - 200) / 2, y_offset +  2*55, 200, 50, renderer, purple);
    KRUSKAL = new Button((win_width - 200) / 2, y_offset + 3*  55, 200, 50, renderer, purple);
    BACK = new Button((win_width - 200) / 2, y_offset + 4 * 55, 200, 50, renderer, purple);
}

maze :: ~maze(){
    if (Type_maze) delete Type_maze;
    if (DFS) delete DFS;
    if (PRIM) delete PRIM;
    if (KRUSKAL) delete KRUSKAL;
    if (BACK) delete BACK;
}

bool maze ::  now_playing_(){
    return now_playing;
}


void maze :: draw_cell(SDL_Renderer* renderer, int row, int col, const SDL_Color& color, int cell_size){
    SDL_Rect cell = { col * cell_size, row * cell_size, cell_size, cell_size };
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b,color.a);
    SDL_RenderFillRect(renderer, &cell);
}

void maze :: break_wall(int row, int col,
                int new_row, int new_col)
{
    int break_row = (new_row + row) / 2;
    int break_col = (new_col + col) / 2;
    way[break_row][break_col] = 1;
}


bool maze :: check_new_index(int new_row, int new_col){
    if (new_row >= row_size || new_col >= col_size ||
        new_row < 0 || new_col < 0 ||
        visited[new_row][new_col]){
        return false;
    }
    return true;
}

bool maze :: check_next_index(int next_row, int next_col){
    if (next_row >= row_size || next_col >= col_size || next_row < 0 || next_col < 0) return false;
    if (way[next_row][next_col] == 1){
        return true;
    }
    return false;
}

const vector<int>delta_row = {0,1,0,-1};
const vector<int>delta_col = {1,0,-1,0};
bool maze :: solve_maze(int row, int col){
    way[row][col] = 2;
    if(row == row_size-1 && col == col_size-1){
        draw_cell(renderer, row, col, yellow, cell_size);
        SDL_RenderPresent(renderer);
        return true;
    }
    draw_cell(renderer, row, col, yellow, cell_size);
    SDL_RenderPresent(renderer);
    for (int i =0; i < 4; i++){
        int next_row = row + delta_row[i];
        int next_col = col + delta_col[i];
        if (check_next_index(next_row, next_col)){
            if(solve_maze(next_row, next_col)){
                return true;
            }
            draw_cell(renderer, next_row, next_col, black, cell_size);
            SDL_RenderPresent(renderer);
            SDL_Delay(5);
        }
    }
    return false;
}

void maze :: reset(){
    SDL_SetRenderDrawColor(renderer,purple.r, purple.g, purple.b, purple.a);
    SDL_RenderClear(renderer);
    for (int i = 0; i < row_size; i++){
        for (int j = 0; j < col_size; j++){
            visited[i][j] = false;
            way[i][j] = 0;
        }
    }
    if (Type_maze != nullptr) {
        delete Type_maze;
        Type_maze = nullptr;
    }
}


void maze :: set_generate(type_maze* type) {
    if (Type_maze != nullptr) {
        delete Type_maze;
        Type_maze = nullptr;
    }
    Type_maze = type;
}


void maze :: generate_maze_(){
    if (Type_maze){
        Type_maze -> generate_maze(*this, row, col);
    }
}


void maze::handle_event(SDL_Event& event) {
    if (!now_playing) {
        DFS->render_button("DFS", font);
        PRIM->render_button("PRIM", font);
        KRUSKAL -> render_button("KRUSKAL", font);
        BACK->render_button("BACK", font);
    }
    if (event.type == SDL_MOUSEMOTION) {
        if (!now_playing){
            DFS->check_button_hover(event.motion.x, event.motion.y);
            PRIM->check_button_hover(event.motion.x, event.motion.y);
            KRUSKAL ->check_button_hover(event.motion.x, event.motion.y);
            BACK->check_button_hover(event.motion.x, event.motion.y);
        }
    }
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        Sound -> loadFromFile("click.wav");
        if (DFS && DFS->is_hovered_() && event.button.button == SDL_BUTTON_LEFT) {

            Sound -> play();
            SDL_Delay(100);

            reset();
            set_generate(new maze_dfs());
            generate_maze_();
            now_playing = true;
        }

        else if (PRIM && PRIM->is_hovered_() && event.button.button == SDL_BUTTON_LEFT) {

            Sound -> play();
            SDL_Delay(100);

            reset();
            set_generate(new maze_prim());
            generate_maze_();
            now_playing = true;
        }

        else if (KRUSKAL && KRUSKAL->is_hovered_() && event.button.button == SDL_BUTTON_LEFT) {

            Sound -> play();
            SDL_Delay(100);

            reset();
            set_generate(new kruskal_maze());
            generate_maze_();
            now_playing = true;
        }

        else if (BACK && BACK->is_hovered_() && event.button.button == SDL_BUTTON_LEFT){

            Sound -> play();
            SDL_Delay(100);

            SDL_Event event;
            event.type = SDL_KEYDOWN;
            event.key.keysym.sym = SDLK_m;
            event.key.state = SDL_PRESSED;
            event.key.repeat = 0;
            SDL_PushEvent(&event);
        }


        DFS -> set_hovered_(false);
        PRIM -> set_hovered_(false);
        KRUSKAL ->set_hovered_(false);
        BACK -> set_hovered_(false);
    }
}



