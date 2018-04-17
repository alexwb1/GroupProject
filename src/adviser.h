#ifndef GROUPPROJECT_ADVISOR_H
#define GROUPPROJECT_ADVISOR_H

#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

/*

 

*/

class Adviser
{
    string name;
    int fee;
    

public:
    Adviser(string name);

    int getFee();

    int setFee();

    void loadAdvice();

    string getAdvice();



};

#endif //GROUPPROJECT_ADVISOR_H
