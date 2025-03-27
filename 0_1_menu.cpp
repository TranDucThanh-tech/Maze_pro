#include "0_1_menu.h"

menu::menu(SDL_Renderer* renderer) : play_clicked(false) {
    this->renderer = renderer;
    Play = new Button((310-200)/2, (310-50)/2, 200, 50, renderer, yellow);
}

menu::~menu() {
    delete Play;
}

bool menu::play_clicked_() {
    return play_clicked;
}

void menu::render() {
    if (Play) {
        Play->render_button("Play");
    }
    SDL_RenderPresent(renderer);
}

void menu::handle_event(SDL_Event& event) {
    switch (event.type) {
        case SDL_MOUSEMOTION:
            if (Play) {
                bool was_hovered = Play->is_hovered_();
                Play->check_button_hover(event.motion.x, event.motion.y);
                if (was_hovered != Play->is_hovered_()) {
                    Play->render_button("Play");
                }
            }
            break;

        case SDL_MOUSEBUTTONDOWN:
            if (Play && Play->is_hovered_() && event.button.button == SDL_BUTTON_LEFT) {
                play_clicked = true;
            }
            break;
    }
}
