#include "0_0_game.h"
#include "1_maze.h"
#include "1_player.h"

int main(int argc, char* argv[])
{
    srand(time(0));
    game Game;
    Game.run();
    return 0;
}
