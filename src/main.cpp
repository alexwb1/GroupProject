#include <iostream>
#include <cstring>
#include "game.h"

using namespace std;
//Welcome Methods
void welcomeMessage();
bool playGame();
string userName();
int wheel();
string prizeSetter(int prizeNumber);
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
    int startingAmount;
    //welcomeMessage();
    //game = playGame();//FIXME: Works, just commented out for testing
    game = true;
    if (game == false){
        cout << "You chose not to play Asset Management Simulator." <<endl;
        return 0;
    }
    //name = userName();//FIXME: Works, just commented out for testing
    name = "sean";
    startingAmount = wheel();
    Game *g = new Game(startingAmount,name);
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
    while(i < g->getFinalWeek() && game == true) {//Ends game when user chooses to quit or when time is up
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
                    getAdvice(g, i);// (Option 4) TODO: Fill in
                    break;
                case 5:
                    endWeek = endOfWeek(); // (option 5) TODO: Fill in
                    break;
                default:
                    cout << "See switch statement on main.cpp starting on line " << endl;
                    break;
            }

        }
        ++i;
        g->nextWeek(); //Increments the week in game class
        cout << "we are now on week " << i << "\n" << endl; //FIXME: delete later
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
    //print Port
    cout << "Got Advice" << endl;
}
bool endOfWeek(){
    return true;
}

int wheel(){
    srand (static_cast <unsigned> (time(0)));                                 //Sets the random number seed

    int maxSpins = 12;                                                        //Sets the maximum number of spins to 12
    int spinTimes = (rand() % maxSpins + 8);                                  //Sets the number of spins to a range of 8-20

    for (int i = 1; i <= spinTimes; i++){                                     //Loops the wheel "spinTimes" number of times
        cout << "======================" << endl;                             //Fancy text for the wheel
        cout << "||   " << prizeSetter(i) << "    ||" << endl;                //First possible prize
        cout << "||   " << prizeSetter(i + 1) <<  "    ||" << endl;           //Second possible prize
        cout << "||-> " << prizeSetter(i + 2) << "  <-||" << endl;            //Third possible prize
        cout << "||   " << prizeSetter(i + 3) << "    ||" << endl;            //Fourth possible prize
        cout << "||   " << prizeSetter(i + 4) << "    ||" << endl;            //Fifth possible prize
        cout << "======================" << endl;                             //Fancy text for the wheel
    }

    string moneyWon = prizeSetter(spinTimes + 2);                             //String "moneyWon" is determined by method prizeSetter (below)
    int moneyWonInt;                                                      //Creates a float, "moneyWonInt" that will be returned by this method

    if (moneyWon == "$100,000.00"){                                           //If string "moneyWon" equals "$100,000.00" then...
        moneyWonInt = 100000;                                            //Float "moneyWonInt" is set to 100,000.00
    }
    else if (moneyWon == " $50,000.00"){                                      //If string "moneyWon" equals "$50,000.00" then...
        moneyWonInt = 50000;                                               //Float "moneyWonInt" is set to 50,000.00
    }
    else if (moneyWon == " $75,000.00"){                                      //If string "moneyWon" equals "$75,000.00" then...
        moneyWonInt = 75000;                                             //Float "moneyWonInt" is set to 75,000.00
    }
    else if (moneyWon == " $87,500.00"){                                      //If string "moneyWon" equals "$87,500.00" then...
        moneyWonInt = 87500;                                             //Float "moneyWonInt" is set to 87,500.00
    }
    else if (moneyWon == " $67,500.00"){                                      //If string "moneyWon" equals "$67,500.00" then...
        moneyWonInt = 67500;                                             //Float "moneyWonInt" is set to 67,500.00
    }

    cout << "You have won " << moneyWon << " from the Wheel of Small Loans!" << endl;      //Output, user has won $ "moneyWon" in initial capital
    cout << " " << endl;                                                                   //Space between text outputs
    return moneyWonInt;                                                                  //Method returns float value for users initial capital
}
string prizeSetter(int prizeNumber){

    if (prizeNumber == 1 || prizeNumber  == 6 || prizeNumber  == 11 || prizeNumber  == 16 || prizeNumber  == 21){          //If int "prizeNumber" equals 1, or any increment of 5 until 21...
        return "$100,000.00";                                                                                              //Returns string "$100,000.00"
    }
    else if (prizeNumber == 2 || prizeNumber  == 7 || prizeNumber  == 12 || prizeNumber  == 17 || prizeNumber  == 22){     //If int "prizeNumber" equals 2, or any increment of 5 until 22...
        return " $50,000.00";                                                                                              //Returns string " $50,000.00"
    }
    else if (prizeNumber == 3 || prizeNumber  == 8 || prizeNumber  == 13 || prizeNumber  == 18 || prizeNumber  == 23){     //If int "prizeNumber" equals 3, or any increment of 5 until 23...
        return " $75,000.00";                                                                                              //Returns string " $75,000.00"
    }
    else if (prizeNumber == 4 || prizeNumber  == 9 || prizeNumber  == 14 || prizeNumber  == 19 || prizeNumber  == 24){     //If int "prizeNumber" equals 4, or any increment of 5 until 24...
        return " $87,500.00";                                                                                              //Return " $87,500.00"
    }
    else if (prizeNumber == 5 || prizeNumber  == 10 || prizeNumber  == 15 || prizeNumber  == 20 || prizeNumber  == 25){    //If int "prizeNumber" equals 5, or any increment of 5 until 25...
        return " $67,500.00";                                                                                              //Return " $67,500.00"
    }
    return 0;                                                                                                              //Returns 0
}
