#include <iostream>
#include <cstring>
#include "game.h"

using namespace std;

void welcomeMessage();
int playGame();
string userName();

void promptBrokerage(Game *g);
void promptAdviser(Game *g);
void promptAssets();

int main()
{
    string name; //name of user
    int game; //does the user decide to play?

    welcomeMessage();
    game = playGame();
    //game = 1;
    if (game == 0){
        cout << "You chose not to play Asset Management Simulator." <<endl;
        return 0;
    }
    name = userName();
    name = "sean";
    Game *g = new Game(10000,name);

    //promptBrokerage(g);

    //promptAdviser(g);

    //promptAssets();


    //Loop through 6 months done weekly (24 weeks)
    //bankDecisions()
    //is a switch statement with calls to other methods
    //checkAccountInfo()
    //
    //checkInvestment()
    //prints all investments
    //modifyInvestment()
    //add()
    //sell()
    //getAdvice()
    //nextWeek()

    //explainHowDayWent();
    //suggestionForNextDay();

	cout << "Finished main" << endl;
	return 0;
}

//prints message to explain game
void welcomeMessage(){
    cout << "Welcome to Asset Management Simulator\n" << endl;
    cout << "Today, you will learn how to do the following:" << endl;
    cout << "    1. Choose a financial adviser." << endl;
    cout << "    2. Choose assets to invest in." << endl;
    cout << "    3. Choose a brokerage to work with." << endl;
    cout << "    4. Manage funds over a long period of time." << endl;
}
//User decides to play the game (or not)
int playGame(){
    string decision;
    int playGame;
    cout << "Would you like to learn these things? (YES/NO)" << endl;
    while(true) {
        cin >> decision;
        if (decision == "YES") {
            playGame = 1;
            break;
        } else if (decision == "NO") {
            playGame = 0;
            break;
        }
        else{
            cout << "Please insert NO to quit, or insert YES to play" << endl;
            continue;
        }
    }
    return playGame;
}
//Gets user's name for use in Game creation

string userName(){
    cout << "Thanks for choosing to play Asset Management Simulator.\nLets get started.\n" << endl;
    cout << "What is your name?" << endl;
    string name;
    cin >> name;
    cout << endl << endl;
    cout << "Hello " << name << ". Lets go ahead and pick your brokerage, adviser, and assets.";
    return name;
}


//FIXME: must change to a getLine() for user input.
//Prints the name of Brokerages and lets the user pick one.
void promptBrokerage(Game *g){
    bool chooseB = false;
    string brokerageName;
    cout << "\nWhich of these brokerages would you like to use?" << endl;
    g->printBrokerages(g->getBrokerages());
    while (!chooseB){
        getline(cin, brokerageName);
        chooseB = g->setBrokerage(brokerageName);
        if (chooseB == false){
            cout << "\nPlease type the name of the brokerage exactly as it is displayed." << endl;
            g->printBrokerages(g->getBrokerages());
        }
    }
    cout << "Thanks for choosing " << brokerageName << " as your brokerage.\n" << endl;
}
//Prints the name of the Advisers and lets the user pick one
void promptAdviser(Game *g){
    bool chooseA = false;
    string adviserName;
    cout << "\nWhich of these Advisers would you like to work with?" << endl;
    g->printAdvisers(g->getAdvisers());
    while (!chooseA){
        getline(cin, adviserName);
        chooseA = g->setAdviser(adviserName); //FIXME: Ally Invest doesn't work
        if (chooseA == false){
            cout << "\nPlease type the name of the brokerage exactly as it is displayed." << endl;
            g->printAdvisers(g->getAdvisers());
        }
    }
    cout << "Thanks for choosing " << adviserName << " as your adviser.";
}

