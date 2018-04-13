#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#ifndef UNTITLED10_ADVISOR_H
#define UNTITLED10_ADVISOR_H
class Advisor{

private:/*------Instance Variables-------*/
    string name;
    string face;

    void setFields() {
        unsigned short choice=(rand()%3)+1;
        string face = "", name = "";
        switch(choice) {
            case 1: {
                name = "Zacharina";
                face = "/%%%%%%\\\n| o  o |\nl   >  l\n \\_==_/ \n";
                break;
            }
            case 2: {
                name = "Dilbert";
                face = " _____\n/7&&^y\\\n| 0 0 |\n|  J  |\n \\HHH/ \n";
                break;
            }
            case 3:{
                name = "Frankenstein";
                face= "~~~~~~~\n| U U |\n|  t  |\n| ~~~ |\n ^^^^^ \n";
                break;
            }

        }
        this->name = name;
        this->face = face;

    }

public:

    Advisor(){
        setFields();
    }

    const string &getName() const {
        return name;
    }

    const string &getFace() const {
        return face;
    }

};
#endif //UNTITLED10_ADVISOR_H
