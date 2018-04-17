#include "advisor.h"
#include <cstdlib>

void Adviser::generateAccuracy()
{
	 accuracy = ((double) rand() / (RAND_MAX));
}



void Adviser::generateFee()
{
	
}




Adviser::Adviser(string name)
{
	this->name = name;
	
	generateAccuracy();
	generateFee();
}

/*
generateSentiment takes the current price and the next days price and generates an int 1 - 5
where 1 is very bad sentiment, 2 is bad sentiment, 3 is neutral sentiment, 4 is good sentiment
5 is very good sentiment. This 1 - 5 number will be based on the change of the price and the 
accuracy of the adviser.
*/

int generateSentiment(double curr, double next)
{
	double change = (next-curr)/curr;
	
	
	
	
	
}




