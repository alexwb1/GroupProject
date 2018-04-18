#include "game.h"

Game::Game(int initialCapital, string name) {
    capital = initialCapital;
    this->name = name;

    string line;
    string filename = "GroupProject/Data/stock_price_data.txt";
    inFile.open(fileName, ios::in);

    if(!inFile)
    {
        cerr << "\nThe file could not be opened.\n";
    }

    while(getline(inFile,line))
    {

        stringstream check1(line);
        data.clear();

        while(getline(check1, inter, ','))
        {
            data.push_back(inter);
            cout << inter << endl;
        }

        if(data[0] == name)
            break;
    }

    data.erase(data.begin()); // The first element of the vector before the erase is the symbol name

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
