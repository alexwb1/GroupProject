#pragma once

#include <string>

class Adviser
{
	std::string name; // string representing the adviser's name
    int fee; // int representing the adviser's weekly fee
    double accuracy; // double representing accuracy of the adviser's predictions; value in range [0 - 1]

public:

    explicit Adviser(std::string name);

    std::string getName(); // returns the adviser's name

	double getFee(); // returns daily adviser fee

	std::string generateAdvice(); // generates advice on asset movements for the current day

private:

    double generateAccuracy(int fee); // generates adviser's predictions (value is 0-1)

    int generateFee(); // generates daily adviser fee

    int generateSentiment(double currentPrice, double nextPrice);
};

// Definition of Adviser methods

Adviser::Adviser(std::string name)
{
    this->name = name;
    this->fee = generateFee();
    this->accuracy = generateAccuracy(this->fee);
}

std::string Adviser::getName() {
    return name;
}

double Adviser::getFee() {
    return fee;
}

int Adviser::generateFee()
{
    return 0;
}

double Adviser::generateAccuracy(int fee)
{
	accuracy = ((double) rand() / (RAND_MAX));
}

std::string Adviser::generateAdvice() {
	return std::string();
}

int Adviser::generateSentiment(double currentPrice, double nextPrice) {

    double change = (nextPrice - currentPrice) / currentPrice;


    int initSent = 0;

    if(change >= -.005 && change <= .005)
        initSent = 3;
    else if(change > .005 && change <= 0.0125)
        initSent = 4;
    else if(change > 0.0125)
        initSent = 5;
    else if(change < -.005 && change >= -.0125)
        initSent = 2;
    else if(change < -.0125)
        initSent = 1;
    else
        initSent = 3;



    // Now initSent is the CORRECT sentiment for the the change in the price
    // Now initSent will be CHANGED according to the advisers accuracy.
}

