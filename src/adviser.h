#ifndef GROUPPROJECT_ADVISOR_H
#define GROUPPROJECT_ADVISOR_H

#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

/*
 *
 * */

class Adviser
{
    string name; //adviser's name
    double fee; //daily adviser fee
    unsigned int accuracy; // accuracy of the adviser's predictions (value is 0-1)
	
private:

	void generateAccuracy(); // generates adviser's predictions (value is 0-1)
	void generateFee(); // generates daily adviser fee
	int generateSentiment(int, int);
	
public:

    Adviser(string name);
    double getFee(); // returns daily adviser fee
    string generateAdvice(); // generates advice on asset movements for the current day
};

#endif //GROUPPROJECT_ADVISOR_H
