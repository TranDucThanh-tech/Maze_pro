#include "1_maze.h"


maze :: maze(SDL_Renderer* renderer, TTF_Font* font, SoundEffect* Sound):
    renderer(renderer),font(font), Sound(Sound){
    this->row = row_size/2;
    this->col = col_size/2;
    this->Type_maze = nullptr;
    is_finish = false;
    way = vector<vector<int>>(row_size, vector<int>(col_size, 0));

    int y_offset = win_hight / 2;
    DFS = new Button((win_width - 200) / 2, y_offset - 110 , 200, 50, renderer, purple);
    PRIM = new Button((win_width - 200) / 2, y_offset - 55, 200, 50, renderer, purple);
    KRUSKAL = new Button((win_width - 200) / 2, y_offset , 200, 50, renderer, purple);
    BACK = new Button((win_width - 200) / 2, y_offset + 55 , 200, 50, renderer, purple);
    Sound -> loadFromFile("click.wav");
}

maze :: ~maze(){
    if (Type_maze) {
        delete Type_maze;
        Type_maze = nullptr;
    }
    if (DFS) {
        delete DFS;
        DFS = nullptr;
    }
    if (PRIM){
        delete PRIM;
        PRIM = nullptr;
    }
    if (KRUSKAL) {
        delete KRUSKAL;
        KRUSKAL = nullptr;
    }
    if (BACK) {
        delete BACK;
        BACK = nullptr;
    }
}

bool maze ::  is_finish_(){
    return is_finish;
}


void maze :: draw_cell(SDL_Renderer* renderer, int row, int col, const SDL_Color& color){
    SDL_Rect cell = { col * cell_size, row * cell_size, cell_size, cell_size };
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b,color.a);
    SDL_RenderFillRect(renderer, &cell);
}


bool maze :: check_new_index(int new_row, int new_col){
    if (new_row >= row_size || new_col >= col_size ||
        new_row < 0 || new_col < 0 ||
        way[new_row][new_col] == 1){
        return false;
    }
    return true;
}

bool maze :: check_next_index(int next_row, int next_col, int mid_row, int mid_col){
    if (next_row >= row_size || next_col >= col_size || next_row < 0 || next_col < 0) return false;
    if (way[next_row][next_col] == 1 && way[mid_row][mid_col] == 1){
        return true;
    }
    return false;
}


bool maze :: solve_maze(int row, int col, int mid_row, int mid_col){
    way[row][col] = 2;
    if(row == row_size-1 && col == col_size-1){
        draw_cell(renderer, row, col, yellow);
        draw_cell(renderer, mid_row, mid_col, yellow);
        SDL_RenderPresent(renderer);
        return true;
    }
    draw_cell(renderer, row, col, yellow);
    draw_cell(renderer, mid_row, mid_col, yellow);
    SDL_RenderPresent(renderer);
    for (int i =0; i < 4; i++){
        int next_row = row + drow[i];
        int next_col = col + dcol[i];
        int new_mid_row = (next_row+row) >> 1;
        int new_mid_col = (next_col+col) >> 1;
        if (check_next_index(next_row, next_col, new_mid_row, new_mid_col)){
            if(solve_maze(next_row, next_col, new_mid_row, new_mid_col)){
                return true;
            }
            draw_cell(renderer, next_row, next_col, black);
            draw_cell(renderer, new_mid_row, new_mid_col, black);
            SDL_RenderPresent(renderer);
            SDL_Delay(5);
        }
    }
    return false;
}

void maze :: clear_(){
    SDL_SetRenderDrawColor(renderer,purple.r, purple.g, purple.b, purple.a);
    SDL_RenderClear(renderer);
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
    if (is_finish) return;
    DFS->render_button("DFS", font);
    PRIM->render_button("PRIM", font);
    KRUSKAL -> render_button("KRUSKAL", font);
    BACK->render_button("BACK", font);
    if (event.type == SDL_MOUSEMOTION) {
        DFS->check_button_hover(event.motion.x, event.motion.y);
        PRIM->check_button_hover(event.motion.x, event.motion.y);
        KRUSKAL ->check_button_hover(event.motion.x, event.motion.y);
        BACK->check_button_hover(event.motion.x, event.motion.y);
        return;
    }
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        if (DFS && DFS->is_hovered_() && event.button.button == SDL_BUTTON_LEFT) {
            Sound -> play();
            SDL_Delay(200);
            clear_();
            set_generate(new maze_dfs());
            generate_maze_();
            is_finish = true;
        }

        else if (PRIM && PRIM->is_hovered_() && event.button.button == SDL_BUTTON_LEFT) {
            Sound -> play();
            SDL_Delay(200);
            clear_();
            set_generate(new maze_prim());
            generate_maze_();
            is_finish = true;
        }

        else if (KRUSKAL && KRUSKAL->is_hovered_() && event.button.button == SDL_BUTTON_LEFT) {
            Sound -> play();
            SDL_Delay(200);
            clear_();
            set_generate(new kruskal_maze());
            generate_maze_();
            is_finish = true;
        }

        else if (BACK && BACK->is_hovered_() && event.button.button == SDL_BUTTON_LEFT){
            Sound -> play();
            SDL_Delay(200);
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



