#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
#include "game.h"
using namespace std;

// Welcome methods
void welcomeMessage();
bool playGame();
string userName();
int promptInitialCapital(string name);
int wheel();
string prizeSetter(int prizeNumber);

// Set up methods
void promptBrokerage(Game *g);
void promptAdviser(Game *g);
void promptAssets(Game *g);
void sellAssets(Game *g);
void buyAssets(Game *g);

// Game play methods
int makeDecision();
void checkAccountInfo(Game *g);
void checkMarkets(Game *g);
void modifyInvestment(Game *g);
void printAdvice(Game *g);


int main()
{
    string name; // a string value representing the user's name
    bool game; // a boolean value representing if the user wants to play
    int startingAmount; // an int value representing the starting amount of money that a player has

    // prints out a welcome message to the user and asks if the user would like to play
    welcomeMessage();
    game = playGame();

    // if the user decides not to play the game, close the game
    if (!game)
    {
        cout << "You chose not to play Asset Management Simulator." <<endl;
        return 0;
    }
    // if the user decides to play, say thanks
    else
    {
      cout << "Thanks for choosing to play Asset Management Simulator" << endl;
      cout << "Let's get started." << endl;
      cout << endl;
    }

    // sets up game object with a random starting capital and the user's name
    name = userName();
    startingAmount = promptInitialCapital(name);
    Game *g = new Game(startingAmount, name);

    // prints user's starting capital
    cout << "Your starting capital is: $" << g->getCapital() << endl;

    // prompts the user to set up their portfolio and other game options
    promptBrokerage(g);
    promptAdviser(g);
    promptAssets(g);

    // prints the users capital
    cout << "You now have: $" << g->getCapital() << endl << endl;

    int decisionTime;
    int userDecision;

    //Loop through 6 months done weekly (24 weeks)
    while(g->getWeek() < g->getFinalWeek() && game == true) {//Ends game when user chooses to quit or when time is up
        decisionTime = 6; //Gives the user a maximum of 6 decisions per day
        while(decisionTime > 0) {
            decisionTime -= 1; //user has less decision time
            userDecision = makeDecision();
            switch (userDecision)
            { //new
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
                    printAdvice(g);// (Option 4) TODO: Fill in
                    break;
                case 5:
                    break;
                default:
                    cout << "See switch statement on main.cpp starting on line " << endl;
                    break;
            }

        }
        g->nextWeek(); //Increments the week in game class
        cout << "we are now on week " << g->getWeek() << "\n" << endl; //FIXME: delete later
        //TODO: explainHowWeekWent(); Gives a short story about the week based on financial outcomes
        //TODO: suggestionForNextWeek(); Gives an inner dialogue on what could be done for better financial outcome
    }
    //TODO: Create a means of summarizing the events of all 26 weeks.
	cout << "Finished main" << endl;
	return 0;
}

//prints message to explain the game
void welcomeMessage()
{
    cout << endl;
    cout << "Welcome to Asset Management Simulator" << endl << endl;
    cout << "Today, you have the opportunity to learn how to do the following:" << endl << endl;
    cout << "    1. Choose a financial adviser." << endl;
    cout << "    2. Choose assets to invest in." << endl;
    cout << "    3. Choose a brokerage to work with." << endl;
    cout << "    4. Manage funds over a long period of time." << endl << endl;
}

// prompts the user to decide if they would like to play
bool playGame()
{
    // prompts the user asking if they would like to play the game
    string decision;
    bool playGame = false;
    cout << "Would you like to learn these things? (Type 1 for 'Yes' or 0 for 'No')" << endl;
    cin >> decision;

    // evaluates the user's decision
    while (true)
    {
        if (decision == "1")
        {
            playGame = true;
            break;
        }
        else if (decision == "0")
        {
            playGame = false;
            break;
        }
        else
        {
            // if the input is neither 1 nor 0, prompt the user again
            cout << "Please type 1 for 'Yes' or 0 for 'No'" << endl;
            cin >> decision;
            continue;
        }
    }
    cout << endl;
    return playGame;
}
// gets user's name for use in Game creation
string userName()
{
    // prints out initial question asking for user's name
    cout << "What is your name? (Please enter first name only)" << endl;

    // reads and returns the user's input
    string name;
    cin >> name;
    cin.clear();
    cout << endl;
    return name;
}

int promptInitialCapital(string name)
{
    // prompt the user for how he would like to determine his money
    cout << "Hello " << name << "!" << endl;
    cout << "How would you like to determine your initial capital? (Please enter an integer 1 or 2)" << endl << endl;
    cout << "1. I'll choose myself. Why the hell wouldn't I?" << endl;
    cout << "2. Let me spin the Wheel of Small Loans." << endl;

    // read in the user's decision
    string decision;
    cin >> decision;

    // evaluate the user's decision
    while (true)
    {
        if (decision == "1")
        {
            // prompt the user for how much money they would like
            cout << "How much money would like to begin the game with? (Please enter an integer value)" << endl;

            // read in and return the user-chosen starting capital
            string initialCapital;
            cin >> initialCapital;
            while (!all_of(initialCapital.begin(), initialCapital.end(), ::isdigit))
            {
                cout << "Please enter an integer value greater than 0" << endl;
                cin.clear();
                cin >> initialCapital;
            }

            // convert the string value to an int
            int c = 0;
            stringstream ss;
            ss << initialCapital;
            ss >> c;
            return c;
        }
        else if (decision == "2")
        {
            // spin the Wheel of Small Loans
            return wheel();
        }
        else
        {
            // if the user does not enter a valid option, prompt again
            cout << "Please enter an integer value 1 or 2" << endl;
            cin >> decision;
        }
    }
}

// prints the name of brokerages and lets the user pick one.
void promptBrokerage(Game *g)
{
    // initializes necessary variables
    bool chooseB = false;
    string brokerageName;

    // prints out the options for the user
    g->printBrokerages();
    cout << "Which of these brokerages would you like to use? (Please type a name)" << endl;

    // begins loop to ensure that the user entered well formed input
    while (!chooseB)
    {
        // clears cin and attempts to read in the user's input
        cin.clear();
        cin >> brokerageName;

        // attempts to choose the brokerage; chooseB is true if successfully chose, false otherwise
        chooseB = g->setBrokerage(brokerageName);

        // if the user entered malformed input, the user is prompted again
        if (!chooseB)
        {
            cout << endl;
            cout << "Please type the name of the brokerage exactly as it is displayed." << endl;
            g->printBrokerages();
        }
    }
    cout << "Thanks for choosing " << brokerageName << " as your brokerage." << endl;
    cin.clear();
    cout << endl;
}

// prints the name of the Advisers and lets the user pick one.
void promptAdviser(Game *g)
{
    // initializes necessary variables
    bool chooseA = false;
    string adviserName;

    // prints out the prompt to the user and the list of advisers that can be chosen
    cout << "Which of these advisers would you like to work with? (Please type a name)" << endl;
    g->printAdvisers();

    // begins loop to ensure that a proper selection is made
    while (!chooseA)
    {
        // reads in the user's input and attempts to choose the advise
        cin >> adviserName;
        chooseA = g->setAdviser(adviserName);

        // if the adviser was not properly selected, then the user is prompted again
        if (!chooseA)
        {
            cout << endl;
            cout << "Please type the name of the adviser's name exactly as it is displayed." << endl;
            g->printAdvisers();
        }
    }
    cout << "Thanks for choosing " << adviserName << " as your adviser." << endl;
    cin.clear();
    cout << endl;
}
// prints the name of the Advisers and lets the user pick one.
void promptAssets(Game *g) {

    // initializes necessary variables
    bool finished = false;
    string assetName;
    string buy;
    string quantity;
    int q;

    // begins loop to buy multiple assets
    while (!finished) {
        // prompts the user if they would like to buy an asset
        cout << "Would you like to buy an asset? (Enter 1 for 'Yes' and 0 for 'No')" << endl;
        cin >> buy;
        if (buy == "1")
        {
            // prints out the prompt and a list of the available assets that a user can buy
            cout << "Your current capital is: " << g->getCapital() << endl;
            g->printAssets();
            cout << "Which of these assets would you like to buy?" << endl;

            // reads in the user's input and attempts to choose the advise
            cin >> assetName;
            cin.clear();

            // while loop ensures that a proper asset name is chosen
            while (!g->containsAsset(assetName)) {
                g->printAssets();
                cout << endl;
                cout << "Please enter the asset exactly as it appears above." << endl;
                cin >> assetName;
            }

            // prompts the user by asking how many shares they would like to buy and reads in the input
            cout << "How many shares of " << assetName << " would you like to buy? ";
            cout << "You can buy a maximum of " << g->getBuyingPower(assetName) << " shares." << endl;
            cin >> quantity;

            // convert to quantity to integer
            stringstream convert;
            convert << quantity;
            convert >> q;

            // while loop ensures that an integer was given and that the int is valid
            while (!all_of(quantity.begin(), quantity.end(), ::isdigit) && g->getBuyingPower(assetName) <= q)
            {
                cout << "Please enter a valid integer number " << endl;
                cout << "You can buy a maximum of " << g->getBuyingPower(assetName) << " shares." << endl;
                cin >> quantity;

                // convert to quantity to integer
                convert << quantity;
                convert >> q;
            }

            // buys the asset
            g->buyAsset(assetName, q);
        }
        else if (buy == "0")
        {
            finished = true;

        }
    }
}

// prompts the user to sell assets
void sellAssets(Game *g)
{
    bool chooseAs = false;
    string assetName;
    int numAssets;
    g->printPortfolio();
    cout << endl << "Which of these assets would you like to sell?" << endl;
    while (!chooseAs) {
        //getline(cin, assetName); FIXME: Not working in Sean's IDE
        cin >> assetName;
        cout << "How many shares of " << assetName << " do you want to sell?" << endl;
        cin >> numAssets; // FIXME: make sure there is no input error
        chooseAs = g->sellAsset(assetName, numAssets);
        if (!chooseAs) {
            cout << "Please type the name of the asset exactly as it is displayed." << endl;
            g->printPortfolio();
        }
    }
    cout << "You have sold " << numAssets << " shares of " << assetName << "." << endl;
}

// prompts the user to buy assets
void buyAssets(Game *g)
{
    bool chooseAs = false;
    string assetName;
    int numAssets;
    cout << "\nWhich of these assets would you like to buy?" << endl;
    g->printAssets();
    while (!chooseAs) {
        //getline(cin, assetName); FIXME: Not working in Sean's IDE
        cin >> assetName;

        chooseAs = g->buyAsset(assetName, 1);
        if (chooseAs == false) {
            cout << "Please type the name of the asset exactly as it is displayed." << endl;
            g->printAssets();
        }
    }
    cout << "You have bought shares of " << assetName << "." << endl;
}

// Definition of game play methods

// prompts the user to make their decision
int makeDecision()
{
    string decision;
    cout << "What action would you like to take? (Enter an integer 1 - 5)" << endl << endl;
    cout << "1. Check account info" << endl;
    cout << "2. Check the market" << endl;
    cout << "3. Modify an investment" << endl;
    cout << "4. Get advice" << endl;
    cout << "5. End week" << endl;
    while(cin >> decision) {
        cout << endl;
        if (decision == "1")
        {
            return 1;
        }
        if (decision == "2")
        {
            return 2;
        }
        if (decision == "3")
        {
            return 3;
        }
        if (decision == "4")
        {
            return 4;
        }
        if (decision == "5")
        {
            return 5;
        }
        else
        {
            cout << "Please enter an integer 1 - 5." << endl;
            continue;
        }
    }
}

// checks the account information of the user
void checkAccountInfo(Game *g)
{
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

// prints out the market price of all assets
void checkMarkets(Game *g)
{
    cout << endl << "Market Prices:" << endl;
    vector<Asset> ass = g->getAssets();
    cout << "Asset : Current Price" << endl;

    for (auto &a : ass)
    {
        cout << a.getTicker() << " - $" << a.getPriceAtWeek(g->getWeek()) << endl;;
    }
}

// prompts the user to modify one of their investments
void modifyInvestment(Game *g)
{
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

// prints advice about a specific asset
void printAdvice(Game *g)
{
    // asks the user which asset they would like to get advice about
    g->printAssets();
    cout << "Which asset would you like to get advice about?" << endl;
    string assetName;
    cin >> assetName;

// prints out the adviser's advice
  cout << *(g->printAd(assetName)) << endl;
}

// spins a wheel to determine how much initial capital the player is awarded
int wheel()
{
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

// helps the wheel method spin the wheel by determining the price amount from a random int
string prizeSetter(int prizeNumber)
{

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
