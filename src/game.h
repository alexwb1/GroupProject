#ifndef GROUPPROJECT_GAME_H
#define GROUPPROJECT_GAME_H

#include <vector>
#include "adviser.h"
#include "asset.h"
#include "brokerage.h"

class Game {

    vector<Brokerage> brokerages;
    vector<Asset> assets;
    vector<Adviser> advisers; // a list of advisers

    unsigned int day;


public:

    void nextDay();



};

#endif //GROUPPROJECT_GAME_H
