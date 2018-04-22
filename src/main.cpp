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
void sellAssets(Game *g);
void buyAssets(Game *g);

//Week 1-24 methods
int bankDecisions();
void checkAccountInfo(Game *g);
void checkMarkets(Game *g);
void modifyInvestment(Game *g);
void getAdvice(Game *g, int weekNum);
bool endOfWeek();

int main()
{
    string name; //name of user
    bool game; //does the user decide to play?
    //welcomeMessage();
    //game = playGame();//FIXME: Works, just commented out for testing
    game = true;
    if (game == false){
        cout << "You chose not to play Asset Management Simulator." <<endl;
        return 0;
    }
    //name = userName();//FIXME: Works, just commented out for testing
    name = "sean";
    Game *g = new Game(100000,name);
    cout << "Your starting capital is: "<<g->getCapital() << endl;
    //promptBrokerage(g);//FIXME: Works, just commented out for testing
    g->setBrokerage("Ally Investments"); //DELETE
    //promptAdviser(g);//FIXME: Works, just commented out for testing
    g->setAdviser("Theodore Warner");//DELETE
    //promptAssets(g);//FIXME: Works, just commented out for testing
    g->buyAsset("OIL", 1); //FIXME: Mitchell is on the case
    cout << "You now have: " << g->getCapital() << " Money\n" << endl;

    int i = 1;
    bool endWeek;
    int decisionTime;
    int userDecision;

    //Loop through 6 months done weekly (24 weeks)
    while(g->getWeek() < g->getFinalWeek() && game == true) {//Ends game when user chooses to quit or when time is up
        endWeek = false;
        decisionTime = 6; //Gives the user a maximum of 6 decisions per day
        while(!endWeek && decisionTime > 0) {
            decisionTime -= 1; //user has less decision time
            userDecision = bankDecisions();
            switch (userDecision) { //new
                case 1:
                    checkAccountInfo(g);// (Option 1) TODO: Fill in method
                    break;
                case 2:
                    checkMarkets(g);//(Option 2) TODO: Fill in
                    // prints all potential investments
                    break;
                case 3:
                    modifyInvestment(g); //(Option 3) TODO: Fill in
                    break;
                case 4:
                    getAdvice(g, g->getWeek()+1);// (Option 4) TODO: Fill in
                    break;
                case 5:
                    endWeek = endOfWeek(); // (option 5) TODO: Fill in
                    break;
                default:
                    cout << "See switch statement on main.cpp starting on line " << endl;
                    break;
            }

        }
		
		g->nextWeek();
        
		
		
        //TODO: nextWeek(); Increments the week in game class
        cout << "we are now on week " << g->getWeek() << "\n" << endl; //FIXME: delete later
        //TODO: explainHowWeekWent(); Gives a short story about the week based on financial outcomes
        //TODO: suggestionForNextWeek(); Gives an inner dialogue on what could be done for better financial outcome
    }
    //TODO: Create a means of summarizing the events of all 26 weeks.
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
    int numAssets;
    cout << "\nWhich of these assets are you interested in?" << endl;
    g->printAssets(g->getAssets());
    while (!chooseAs) {
        //getline(cin, assetName); FIXME: Wasnt working on Sean's IDE
        cin >> assetName;
        chooseAs = g->buyAsset(assetName, 1);
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
void sellAssets(Game *g) {
    bool chooseAs = false;
    string assetName;
    int numAssets;
    cout << "\nWhich of these assets would you like to sell?" << endl;
    g->printAssets(g->getPortfolio());
    while (!chooseAs) {
        //getline(cin, assetName); FIXME: Not working in Sean's IDE
        cin >> assetName;
        cout << "How many shares of " << assetName << " do you want to sell?" << endl;
        cin >> numAssets; // FIXME: make sure there is no input error
        chooseAs = g->sellAsset(assetName, numAssets);
        if (chooseAs == false) {
            cout << "Please type the name of the asset exactly as it is displayed." << endl;
            g->printAssets(g->getPortfolio());
        }
    }
    cout << "You have sold " << numAssets << " shares of " << assetName << "." << endl;
}
void buyAssets(Game *g){
    bool chooseAs = false;
    string assetName;
    int numAssets;
    cout << "\nWhich of these assets would you like to buy?" << endl;
    g->printAssets(g->getAssets());
    while (!chooseAs) {
        //getline(cin, assetName); FIXME: Not working in Sean's IDE
        cin >> assetName;

        chooseAs = g->buyAsset(assetName, 1);
        if (chooseAs == false) {
            cout << "Please type the name of the asset exactly as it is displayed." << endl;
            g->printAssets(g->getAssets());
        }
    }
    cout << "You have bought shares of " << assetName << "." << endl;
}
//////////////////Week 1-24 methods////
int bankDecisions(){ // Returns an int for the decision the player makes
    string decision;
    cout << "What action would you like to take? (please select an integer that is shown)\n" << endl;
     //Nested method to make looping simpler
    //while (true){
        cout << "1. Check Account Info." << endl;
        cout << "2. Check the Market." << endl;
        cout << "3. Modify an Investment." << endl;
        cout << "4. Get Advice." << endl;
        cout << "5. End Week." << endl;
        while(cin >> decision) {
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
    cout << "\nAccount info:\n" << endl;
    double equity = 0;
    vector<Asset> portfolio = g->getPortfolio();

    cout << "Asset : Quantity\n" << endl;
    for (auto &a : portfolio)
    {
        if(a.getQuantity() != 0)
        {
            cout << a.getTicker() << " : " << a.getQuantity() << endl;
            equity = equity + a.getQuantity()*a.getPriceAtWeek(g->getWeek());
        }
    }

    cout << "\nCash on hand: " << g->getCapital() << endl;
    cout << "Current equity: " << equity << endl;

}
void checkMarkets(Game *g){
    cout << "\nMarket Prices:" << endl;
    vector<Asset> ass = g->getAssets();
    cout << "Asset : Current Price" << endl;

    for (auto &a : ass)
    {
        cout << a.getTicker() << " : " << a.getPriceAtWeek(g->getWeek()) << endl;;
    }

}
void modifyInvestment(Game *g){
    string userDecisionAlt;
    cout << "1. Buy" << endl;
    cout << "2. Sell" << endl;
    cout << "3. No action" << endl;
    while (cin >> userDecisionAlt) {
        if (userDecisionAlt == "1") {
            //TODO: Create new function for add asset.  DO NOT PROMPT ASSET
            buyAssets(g);
            break;
        } else if (userDecisionAlt == "2") {
            sellAssets(g);
            break;
        } else if (userDecisionAlt == "3")
            break;
        else
            cout << "Please enter an integer 1-5 make a decision." << endl;
        cout << "1. Buy" << endl;
        cout << "2. Sell" << endl;
        cout << "3. No action" << endl;
    }
}
void getAdvice(Game *g, int weekNum){
  // prompt the user about which asset they would like to get advice about
  cout << "Which asset would you like to get advice on?" << endl;
  std::string asset;
  cin >> asset;

  // output the users advice
  cout << g->getAdvice(asset, weekNum) << endl;
}
bool endOfWeek(){
    return true;
}
