#include "game.h"

Game::Game(int initialCapital, string name) {
    capital = initialCapital;

}

bool Game::nextWeek() {
    if (day < FINAL_WEEK) {
        day++;
        return true;
    }
    else {
        return false;
    }
}
