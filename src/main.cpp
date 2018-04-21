#include <iostream>
#include <cstring>
#include "game.h"

using namespace std;
//Welcome Methods
void welcomeMessage();
bool playGame();
string userName();

//Week 0 methods
void promptBrokerage(Game *g);
void promptAdviser(Game *g);
void promptAssets(Game *g);

//Week 1-24 methods
int bankDecisions();
void checkAccountInfo(Game *g);
void checkMarkets(Game *g);
void modifyInvestment(Game *g);
void getAdvice(Game *g);
void endOfWeek();

int main()
{
    string name; //name of user
    bool game; //does the user decide to play?
    //welcomeMessage();FIXME: Works, just commented out for testing
    //game = playGame();FIXME: Works, just commented out for testing
    game = true;
    if (game == false){
        cout << "You chose not to play Asset Management Simulator." <<endl;
        return 0;
    }
    //name = userName();FIXME: Works, just commented out for testing
    name = "sean";
    Game *g = new Game(100000,name);
    cout << "Your starting capital is: "<<g->getCapital() << endl;
    //promptBrokerage(g);FIXME: Works, just commented out for testing
    g->setBrokerage("Ally Investments"); //DELETE
    //promptAdviser(g);FIXME: Works, just commented out for testing
    g->setAdviser("Theodore Warner");//DELETE
    //promptAssets(g);FIXME: Works, just commented out for testing
    g->buyAsset("BTC", 1); //FIXME: buyAsset() is not taking capital from the user
    cout << "You now have: " << g->getCapital() << " Money\n" << endl;

    int i = 1;
    bool endWeek;
    int decisionTime;
    int userDecision;
    //Loop through 6 months done weekly (24 weeks)
    //while(i < g->getFinalWeek() && game == true) {//Ends game when user chooses to quit or when time is up
        endWeek = false;
        decisionTime = 6; //Gives the user a maximum of 6 decisions per day
        //while(!endWeek && decisionTime > 0) {
            userDecision = bankDecisions();
            //is a switch statement with calls to other methods
            checkAccountInfo(g);// (Option 1) TODO: Fill in method
            checkMarkets(g); //(Option 2) TODO: Fill in
                // prints all potential investments
            modifyInvestment(g);//(Option 3) TODO: Fill in
                //add()     (Option 3a)
                //sell()    (Option 3b)
            getAdvice(g);// (Option 5) TODO: Fill in
            endOfWeek(); // (option 6) TODO: Fill in
            decisionTime -= 1;
        //}
        //nextWeek()

        //explainHowWeekWent();
        //suggestionForNextWeek();
    //}
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
bool playGame(){
    string decision;
    int playGame;
    cout << "Would you like to learn these things? (Type 0 for NO and 1 for YES)" << endl;
    getline(cin, decision);
    while(true) {
        if (decision == "YES") {
            playGame = true;
            break;
        } else if (decision == "NO") {
            playGame = false;
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
    cout << endl << endl;
    cout << "Hello " << name << ". Lets go ahead and pick your brokerage, adviser, and assets." << endl;
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
//Prints the name of the Advisers and lets the user pick one.
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
//Prints the name of the Advisers and lets the user pick one.
void promptAssets(Game *g) {
    bool chooseAs = false;
    string assetName;
    int numAssets; //FIXME: return value of addToPortfolio(); tells the user how many assets they added
    cout << "\nWhich of these assets are you interested in?" << endl;
    g->printAssets(g->getAssets());
    while (!chooseAs) {
        getline(cin, assetName);
        chooseAs = g->buyAsset(assetName, 1); //FIXME: add two functions to buyAsset. 1) bool checkPortfolio(); 2) int addToPortfolio();
        if (chooseAs == false) {
            cout << "Please type the name of the asset exactly as it is displayed." << endl;
            g->printAssets(g->getAssets());
        }
    }
    cout << "Thank you for choosing " << assetName << ", it has been added to your portfolio." << endl;
//FIXME: Make into its own method so the user can add an asset at any time during the week
//    bool chooseAssRepeatLoop = false;
//
//    while (!chooseAssRepeatLoop) {
//
//        cout << "Are you interested in another asset? Yes or No?" << endl;
//        string userInput;
//        cin << userInput;
//
//        if ((userInput == "Yes") || (userInput == "yes")){
//            cout << "\nWhich of these assets are you interested in?" << endl;
//            g->printAssets(g->getAssets());
//            while (!chooseAssRepeatLoop) {
//                cin >> assetName;
//                chooseAssRepeatLoop = g->setAsset(assetName);
//                if (chooseAssRepeatLoop == false) {
//                    cout << "Please type the name of the asset exactly as it is displayed." << endl;
//                    g->printAsset(g->getAssets());
//                }
//            }
//        }
//        else if (((userInput == "No") || (userInput == "no"))){
//            chooseAssRepeatLoop = true;
//        }
//        else {
//            cout << "Incorrect user input."  << endl;
//        }
//    }
}

//////////////////Week 1-24 methods////
int bankDecisions(){ // Returns an int for the decision the player makes
    string decision;
    cout << "What action would you like to take? (please select an integer that is shown)\n" << endl;
     //Nested method to make looping simpler
    while (true){
        cout << "1. Check Account Info." << endl;
        cout << "2. Check the Market." << endl;
        cout << "3. Modify an Investment." << endl;
        cout << "4. Get Advice." << endl;
        cout << "5. End Week." << endl;
        cin >> decision;
        cout << endl;
        if(decision == "1"){
            return 1;
        }
        if(decision == "2"){
            return 2;
        }
        if(decision == "3"){
            return 3;
        }
        if(decision == "4"){
            return 4;
        }
        if(decision == "5"){
            return 5;
        }
        else{
            cout << "Please enter an integer 1-5 make a decision." << endl;
            continue;
        }
    }
}
//Decisions
void checkAccountInfo(Game *g){
    cout << "Account info checked" << endl;
}
void checkMarkets(Game *g){
    cout << "Checked the markets." << endl;
}
void modifyInvestment(Game *g){
    //addAsset
    //sellAsset
    cout << "Modified investment" << endl;
}
void getAdvice(Game *g){
    cout << "Got Advice" << endl;
}
void endOfWeek(){
    cout << "ended Week" << endl;
}
