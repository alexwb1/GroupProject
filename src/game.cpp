#include "game.h"

Game::Game(int initialCapital, string name) {
    capital = initialCapital;
    this->name = name;
}

bool Game::nextWeek() {
    if (week < FINAL_WEEK) {
        week++;
        return true;
    }
    else {
        return false;
    }
}

string Game::getName() {
    return std::string();
}

int Game::getCapital() {
    return 0;
}

void Game::setCapital(int capital) {

}

Brokerage *Game::getBrokerage() {
    return nullptr;
}

void Game::setBrokerage(string name) {

}

Adviser *Game::getAdviser() {
    return nullptr;
}

void Game::setAdviser(string name) {

}

bool Game::buyAsset(string name) {
    return false;
}

bool Game::sellAsset(string name) {
    return false;
}
