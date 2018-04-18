#include "../src/game.h"
#include "../src/game.cpp"
#include <string>

int main () {

    Game *game = new Game(1, "Bob");
    game->nextWeek();

    return 0;
}