#ifndef GROUPPROJECT_BROKERAGE_H
#define GROUPPROJECT_BROKERAGE_H

#include <adviser.h>

class Brokerage
{
    string name; // a string value that represents the name of the brokerage

    double fee; // a double value that represents the fee per trade charged by the brokerage

    vector<Adviser> advisers; // a list of advisers that are part of the brokerage

public:

    double getFee(); 

    double generateFee(); // generates a double value that represents the fee per trade charged by the brokerage

};

#endif //GROUPPROJECT_BROKERAGE_H
