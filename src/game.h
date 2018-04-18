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

    string name; // name of the user
    int capital; // current amount of capital that a user does not have invested
    unsigned int week = 1; // unsigned integer value that represents the current week
    const int FINAL_WEEK = 27; // constant int value that represents the last week of available data

public:

    Game(int capital, string name); // the Game constructor takes in an initial capital value and

    bool nextWeek(); // increments the week by 1

    string getName(); // returns a string value representing the user's name

    int getCapital(); // returns an int value representing the capital that a user does not have invested

    void setCapital(int capital); // sets the capital member variable to a specified value

    Brokerage* getBrokerage(); // returns a pointer to the user-chosen brokerage

    void setBrokerage(string name); // sets the user-chosen brokerage

    Adviser* getAdviser(); // returns a pointer to the user-chosen adviser

    void setAdviser(string name); // sets the user-chosen adviser

    bool buyAsset(string name); // adds an asset to the user's portfolio and substracts the price from the user's capital; returns true if this action can be taken, false if not

    bool sellAsset(string name); // removes an asset from the user's portfolio and adds the price to the user's capital; returns true if this action can be taken, false if not
};

#endif //GROUPPROJECT_GAME_H
