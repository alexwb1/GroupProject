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
    return name;
}

int Game::getCapital() {
    return capital;
}

void Game::setCapital(int capital) {
    this->capital = capital;
}

Brokerage* Game::getBrokerage() {
    return brokerage;
}

void Game::setBrokerage(string name) {

}

Adviser *Game::getAdviser() {
    return adviser;
}

void Game::setAdviser(string name) {

}

bool Game::buyAsset(string name) {
    return false;
}

bool Game::sellAsset(string name) {
    return false;
}
