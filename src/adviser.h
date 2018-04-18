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

	std::string getAdvice(); // generates advice on asset movements for the current day

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

std::string Adviser::getAdvice() {
	return std::string();
}


/*
DISCLAIMER!
The logic behind the generateSentiment method may be confusing but just know that
a 1 - 5 value is return based on the future price of the stock and the accuracy 
of the adviser. 1 is very bad sentiment and 5 is very good sentiment.
*/
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
	
	// So one minus the adviser accuracay will be the propability that the advisers sentiment value changes by 1
	// one half of one minus the adviser accuracy will be the probability that the advisers sentiment value changes by 2
	
	if(((double) rand() / (RAND_MAX)) < (1-accuracy)/4)
	{
		//sentiment changes by 3
		if(initSent == 4 || initSent == 5)
			return initSent-3
		else if(initSent == 3)
			return 1;
		else if(initSent == 2 || initSent == 1)
			return 5;
	}
	else if(((double) rand() / (RAND_MAX)) < (1-accuracy)/2)
	{
		//sentiment changes by 2
		if(initSent == 5 || initSent == 4)
			return iniSent-2;
		else if(initSent == 1 || initSent == 2)
			return initSent+2;
		else
		{
			if(((double) rand() / (RAND_MAX)) > 0.5)
				return initSent+2;
			else
				return initSent-2
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

