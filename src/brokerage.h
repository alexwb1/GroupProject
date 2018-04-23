#pragma once

#include <string>

/*
 The Brokerage class is used to hold data associated with various brokerages that a user can work with during the game.
 The class has two main member variables: name (string) and fee (int). The name variable is used to hold the brokerage's
 name, while the fee is used to hold the fee that charged to user per trade. In real world trading, each brokerage has
 a fee per trade that is charged to the user. This has been copied in this game to make it lifelike as possible. The
 names of the brokerages used in this game are also those of real brokerages.
*/

class Brokerage
{
    std::string name; // a string value that represents the name of the brokerage
    int fee; // a double value that represents the fee per trade charged by the brokerage

public:

    Brokerage(std::string name); // constructor for the Brokerage class; takes in the name of the brokerage
    std::string getName(); // gets the name of the brokerage
    int getFee(); // gets the fee of the brokerage

private:

    void generateFee(); // generates an int value that represents the fee per trade charged by the brokerage

};

Brokerage::Brokerage(std::string name) {
    // sets the name variable to the value passed in the constructor
    this->name = name;

    // generates the fee associated with this brokerage
    generateFee();
}

std::string Brokerage::getName()
{
    return name;
}

int Brokerage::getFee()
{
    return fee;
}

void Brokerage::generateFee()
{
    fee = (rand()%10)/200 + ((double) rand() / (RAND_MAX))*10;

}