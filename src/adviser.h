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
    string name; // a string value that represents the name of the adviser

    unsigned double fee; // a double value that represents the daily fee charged by the adviser

    unsigned int accuracy; // an int value (1 - 10) that represents the acurracy of the adviser's predictions
	
private:

	void generateAccuracy(); // generates a value (1 - 10) representing the accuracy of an adviser's predictions
	
	void generateFee(); // generates a value representing the daily fee charged by the adviser

public:

    Adviser(string name);

    double getFee(); // returns a value representing the daily fee charge by the adviser

    string generateAdvice(); // generates advice on asset movements for the current day
};

#endif //GROUPPROJECT_ADVISOR_H
