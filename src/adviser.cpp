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




