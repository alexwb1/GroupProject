#pragma once

#include <string>

class Brokerage
{
    std::string name; // a string value that represents the name of the brokerage
    double fee; // a double value that represents the fee per trade charged by the brokerage


public:

    Brokerage(std::string name);
    std::string getName();
    double getFee();

private:

    void generateFee(); // generates a double value that represents the fee per trade charged by the brokerage

};

// Definition of Brokerage methods

Brokerage::Brokerage(std::string name) {
    this->name = name;
    generateFee();
}

std::string Brokerage::getName() {
    return name;
}
// TODO: get bigAL code
double Brokerage::getFee() {
    return 0;
}

void Brokerage::generateFee() {
    fee = (rand()%10)/200 + ((double) rand() / (RAND_MAX))/100;

}

