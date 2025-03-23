#include "0_game.h"
#include "1_maze.h"
#include "1_player.h"

int main(int argc, char* argv[])
{
    //cout << "a" << endl;
    srand(time(0));
    game Game;
    Game.run();
    //Game();
}
