#include <iostream>
#include <cstring>
#include "game.h"

using namespace std;

void welcomeMessage();
int playGame();
string userName();

void promptBrokerage(Game *g);
void promptAdviser();
void promptAssets();

int main()
{
    string name; //name of user
    int game; //does the user decide to play?

    welcomeMessage();
    //game = playGame();  FIXME: works, just commented out for ease of testing
    game = 1;
    if (game == 0){
        cout << "You chose not to play Asset Management Simulator." <<endl;
        return 0;
    }
    //name = userName(); FIXME: works, just commented out for ease of testing
    name = "sean";
    Game *g = new Game(10000,name);

    promptBrokerage(g);

    //promptAdviser()

    //promptAssets()


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
    cout << "Welcome to Asset Management Simulator" << endl;
    cout << "Today, you will learn how to do the following:" << endl;
    cout << "    1. Choose a financial adviser." << endl;
    cout << "    2. Choose assets to invest in." << endl;
    cout << "    3. Choose a brokerage to work with." << endl;
    cout << "    4. Manage funds over a long period of time." << endl;
}
//User decides to play the game (or not)
int playGame(){
    char decision;
    int playGame;
    cout << "Would you like to learn these things? (Type 0 for NO and 1 for YES)" << endl;
    cin >> decision;
    while(true) {
        if (decision == '1') {
            playGame = 1;
            break;
        } else if (decision == '0') {
            playGame = 0;
            break;
        }
        else{
            cout << "Please insert 0 to quit, or insert 1 to play" << endl;
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
    return name;
}

//Prints the name of Brokerages and lets the user pick one.
void promptBrokerage(Game *g){
    bool chooseB = false;
    string brokerageName;
    cout << "\nWhich of these brokerages would you like to use?" << endl;
    g->printBrokerages(g->getBrokerages());
    while (!chooseB){
        cin >> brokerageName;
        chooseB = g->setBrokerage(brokerageName);
        if (chooseB == false){
            cout << "\nPlease type the name of the brokerage exactly as it is displayed." << endl;
            g->printBrokerages(g->getBrokerages());
        }
    }
    cout << "Thanks for choosing " << brokerageName << " as your brokerage.";
}