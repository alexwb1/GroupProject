#ifndef GROUPPROJECT_GAME_H
#define GROUPPROJECT_GAME_H

#include <vector>
#include "adviser.h"
#include "asset.h"
#include "brokerage.h"

class Game {

    vector<Brokerage> brokerages; // vector that contains a list of the available brokerages
    vector<Adviser> advisers; // vector that contains a list of available assets
    vector<Asset> assets; // vector that contains a list of available assets

    Brokerage *brokerage; // pointer to the brokerage that the user chose
    Adviser *adviser; // pointer to the adviser that the user chose
    vector<Asset> portfolio; // vector that contains a list of assets in the user's portfolio

    string name; // ame of the user
    int capital; // current amount of capital that a user does not have invested
    unsigned int week; // unsigned integer value that represents the current week
    const int FINAL_WEEK = 27; // constant int value that represents the last week of available data

public:

    Game(int initialCapital, string name); // the Game constructor which

    bool nextWeek(); // increments the week by 1





};

#endif //GROUPPROJECT_GAME_H
