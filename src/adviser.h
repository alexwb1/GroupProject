#pragma once

#include <string>
#include <vector>
#include "asset.h"

class Adviser
{
	std::string name; // string representing the adviser's name
    double fee; // int representing the adviser's weekly fee
    double accuracy; // double representing accuracy of the adviser's predictions; value in range [0 - 1]

	//here are the sentiment diaglogues // this is kind of shitty coding but lol
	std::vector<std::string> sentiment1Dialogue{"I fear the worst!","The market is going to crash!","SELL SELL SELL!","IT'S A MOTHERF*CKING BEAR!","SELL ALL THE STOCKS!"};
	std::vector<std::string> sentiment2Dialogue{"I smell a bear.","I advise you to sell.","Investor confidence is at a low.","Prices are going to drop","Short the market!"};
	std::vector<std::string> sentiment3Dialogue{"I am predicting little to no change.","Volitility is low.","I forsee no change in price.","The price will remain stable.","The market is boring me."};
	std::vector<std::string> sentiment4Dialogue{"Don't hold your cash on the sidelines!","I advise you to buy.","Prices are going to rise.","Hold the market!","Investor confidence is rising!"};
	std::vector<std::string> sentiment5Dialogue{"BUY BUY BUY!","Prices are going to skyrocket!","Put all your money in!","HERE COMES A BIG PAYDAY!","BUY ALL THE STOCKS!"};

	std::vector<std::vector<std::string>> sentimentDialogue = {sentiment1Dialogue,sentiment2Dialogue,sentiment3Dialogue,sentiment4Dialogue,sentiment5Dialogue};

public:

    Adviser(std::string name);
    std::string getName(); // returns the adviser's name

	double getFee(); // returns daily adviser fee
	std::string* getAdvice(Asset*, int); // generates advice on asset movements for the current day

private:

    double generateAccuracy(int fee); // generates adviser's predictions (value is 0-1)
    void generateFee(); // generates daily adviser fee
    int generateSentiment(Asset, int);
};

// Definition of Adviser methods

Adviser::Adviser(std::string name)
{
    this->name = name;
    generateFee();
    generateAccuracy(this->fee);
}

std::string Adviser::getName() {
    return name;
}

double Adviser::getFee() {
    return fee;
}

void Adviser::generateFee()
{
	int intFee = rand()%10;
	fee = intFee/100 + ((double) rand() / (RAND_MAX))/100;
}

double Adviser::generateAccuracy(int fee)
{
	accuracy = ((double) rand() / (RAND_MAX));
	if(fee > 0.05)
		accuracy = accuracy + 0.02;
	else
		accuracy = accuracy - 0.01;
}

std::string* Adviser::getAdvice(Asset* asset, int week) {
	int sentiment = generateSentiment(*asset, week);
	return &sentimentDialogue[sentiment][rand()%5];

}


/*
DISCLAIMER!
The logic behind the generateSentiment method may be confusing but just know that
a 1 - 5 value is return based on the future price of the stock and the accuracy
of the adviser. 1 is very bad sentiment and 5 is very good sentiment.
*/
int Adviser::generateSentiment(Asset asset, int weekNum) {
	int currentPrice = asset.getPriceAtWeek(weekNum);
	int nextPrice = asset.getPriceAtWeek(weekNum);

    double change = (nextPrice - currentPrice) / currentPrice;

    int initSent = 0;

    if(change >= -.005 && change <= .005)
        initSent = 3; //neutral sentiment
    else if(change > .005 && change <= 0.0125)
        initSent = 4; //good sentiment
    else if(change > 0.0125)
        initSent = 5; //very good sentiment
    else if(change < -.005 && change >= -.0125)
        initSent = 2; //bad sentiment
    else if(change < -.0125)
        initSent = 1; //very bad sentiment
    else
        initSent = 3; //neutral sentiment

    // Now initSent is the CORRECT sentiment for the ACTUAL change in the price
    // Now initSent will be CHANGED according to the advisers accuracy.

	// So one minus the adviser accuracy will be the probability that the advisers sentiment value changes by 1
	// one half of one minus the adviser accuracy will be the probability that the advisers sentiment value changes by 2

	if(((double) rand() / (RAND_MAX)) < (1-accuracy)/4)
	{
		//sentiment changes by 3
		if(initSent == 4 || initSent == 5)
			return initSent-3;
		else if(initSent == 3)
			return 1; //very bad sentiment
		else if(initSent == 2 || initSent == 1)
			return 5;//very good sentiment
	}
	else if(((double) rand() / (RAND_MAX)) < (1-accuracy)/2)
	{
		//sentiment changes by 2
		if(initSent == 5 || initSent == 4)
			return initSent-2;
		else if(initSent == 1 || initSent == 2)
			return initSent+2;
		else
		{
			if(((double) rand() / (RAND_MAX)) > 0.5)
				return initSent+2;
			else
				return initSent-2;
		}
	}
	else if(((double) rand() / (RAND_MAX)) < (1-accuracy))
	{
		//sentiment changes by 1
		if(initSent == 5)
			return 4;
		else if(initSent == 1)
			return 2;
		else
		{
			if(((double) rand() / (RAND_MAX)) > 0.5)
				return initSent+1;
			else
				return initSent-1;
		}
	}
	else
	{
		//sentiment doesnt change
		return initSent;
	}
}
