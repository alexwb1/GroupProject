#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <limits>
#include "Bank.h"
#include "Investment.h"
#include "Advisor.h"

using namespace std;

//Method Declarations
void mainMenu(Bank);
float startUp();
float prizeWheel();
string prizeSetter(int prizeNumber);
int randNum(int min, int max);
Bank bankSelector(float initialCapital);
Investment createInvestment(Bank userBank, Investment userInvestmentInput);

//MAIN
int main() {
    //Initial Welcome To Program
    //Selection of Bank
    //and Entry to Main Menu
    mainMenu(bankSelector(startUp()));
    //
    return 0;
}

//MAIN MENU METHOD////////////////////////////////////////////////////////////////////
void mainMenu(Bank inputBank){

    Bank UsersBank = inputBank;        //Creates a bank account for the user
    Advisor* advisor = new Advisor();  //Creates an advisor object for the user
    bool programActive;                //Boolean will remain true until program is quit
    int day = 1;                       //Sets the day to 1, days will increment after the user finishes their daily routine

    do {

        bool menuActive = true;        //Boolean is true when user is in the main menu
        int userInput;                 //Takes in user input
        string name="";                //Name is an empty string until altered by the user

        cout << "Welcome to your new bank!" << endl;  //Welcome to the bank
        cout << " " << endl;                          //Space between text outputs
        cout << advisor->getFace() << endl;
        cout << "Hello, I will be your advisor, " << advisor->getName() << "." << endl; //Gets the name of the advisor 
        cout << "What is your name?" << endl;         //Asks the user for their name
        string userName;                              //String for the user name
        cin >> userName;                              //User name is set to user input
        UsersBank.setAccountHolderName(userName);     //In the bank class, the account holder name is set to the users name
        cout << "It's a pleasure to meet you, " << UsersBank.getAccountHolderName() << endl;   //Bank says hello to the user
        cout << " " << endl;                         //Space between text outputs
        cout << "Let's start your portfolio by making 5 investment decisions" << endl;  //Banker says lets make some investments
        cout << " " << endl;                         //Space between text outputs   
                              
        cout << "Investment 1: " << endl;            //Investment 1
        Investment userInvestment1;                  //Creates investment object
        UsersBank.setInvestment1(createInvestment(UsersBank, userInvestment1));        //Sets the first investment in the users bank to the created object
        float bal = UsersBank.getAccountBalance() - userInvestment1.getTotalInvestment();   //Sets the users bank balance to the previous - amount invested       
        UsersBank.setAccountBalance(bal);            //Sets the users bank balance to the previous - amount invested
        cout << " " << endl;                         //Space between text outputs

        cout << "Investment 2: " << endl;            //Investment 2
        Investment userInvestment2;                  //Creates investment object
        UsersBank.setInvestment2(createInvestment(UsersBank, userInvestment2));         //Sets the second investment in the users bank to the created object
        float bal = UsersBank.getAccountBalance() - userInvestment2.getTotalInvestment();   //Sets the users bank balance to the previous - amount invested       
        UsersBank.setAccountBalance(bal);            //Sets the users bank balance to the previous - amount invested
        cout << " " << endl;                         //Space between text outputs

        cout << "Investment 3: " << endl;             //Investment 3
        Investment userInvestment3;                   //Creates investment object
        UsersBank.setInvestment3(createInvestment(UsersBank, userInvestment3));        //Sets the third investment in the users bank to the created object
        float bal = UsersBank.getAccountBalance() - userInvestment3.getTotalInvestment();   //Sets the users bank balance to the previous - amount invested       
        UsersBank.setAccountBalance(bal);            //Sets the users bank balance to the previous - amount invested
        cout << " " << endl;                         //Space between text outputs

        cout << "Investment 4: " << endl;            //Investment 4
        Investment userInvestment4;                  //Creates investment object
        UsersBank.setInvestment4(createInvestment(UsersBank, userInvestment4));        //Sets the fourth investment in the users bank to the created object
        float bal = UsersBank.getAccountBalance() - userInvestment4.getTotalInvestment();   //Sets the users bank balance to the previous - amount invested       
        UsersBank.setAccountBalance(bal);            //Sets the users bank balance to the previous - amount invested
        cout << " " << endl;                         //Space between text outputs

        cout << "Investment 5: " << endl;            //Investment 5
        Investment userInvestment5;                  //Creates investment object
        UsersBank.setInvestment5(createInvestment(UsersBank, userInvestment5));        //Sets the fifth investment in the users bank to the created object
        float bal = UsersBank.getAccountBalance() - userInvestment5.getTotalInvestment();   //Sets the users bank balance to the previous - amount invested       
        UsersBank.setAccountBalance(bal);            //Sets the users bank balance to the previous - amount invested
        cout << " " << endl;                         //Space between text outputs

        cout << "Now that you have made your investment decision..." << endl;     //All 5 decisions have been made, 
        cout << "What can I help you with today?" << endl;                        //Banker now asks the user what they would like to do

        do {                                              //Main loop for each day, user can make 4 decisions and decides when the day is done
            cout << " " << endl;                          //Space between text outputs
            cout << "Day " << day << endl;                //Outputs which day the user is in
            cout << " " << endl;                          //Space between text outputs
            cout << "1. Check account info" << endl;      //The user can press 1 to check their account info
            cout << "2. Check investments" << endl;       //The user can press 2 to check on an individual investment
            cout << "3. Modify investments" << endl;      //The user can press 3 to modify an individual investment
            cout << "4. Leave bank and end day" << endl;  //The user can press 4 to end the day and increment to the next one

            cin >> userInput;                             //User input (1-4)
            switch(userInput){                            //Switch statement for user input (1-4)

                case 1:{                                                                    //Case 1
                cout << " " << endl;                                                        //Space between text outputs
                cout << "Bank: " << UsersBank.getBankName() << endl;                        //Outputs the name of the users bank
                cout << "Account Holder: " << UsersBank.getAccountHolderName() << endl;     //Outputs the name of the account holder (users name)
                cout << "Balance: $" << UsersBank.getAccountBalance() << endl;              //Outputs the current balance of the users account
                }                                                                           //Ends case 1

                case 2: {                                                                                //Case 2
                cout << " " << endl;                                                                     //Space between text outputs
                cout << "Investment 1: " << UsersBank.getInvestment1().getName() << endl;                //Outputs the name of Investment 1              
                    float balance1 = UsersBank.getInvestment1().getTotalInvestment();                    //This code applies modifications to the price
                    balance1 = (balance1*(rand()%10)/100) + balance1;                                    //FIXME: This code should change based on financial data
                    UsersBank.getInvestment1().setTotalInvestment(balance1);                             //Sets total investment for Investment 1 to new value
                cout << "Investment 1 Shares: " << UsersBank.getInvestment1().getNumberOwned() << endl;  //Outputs the number of shares of Investment 1
                cout << "Total Investment: " << balance1 << endl;                                        //Outputs the total investment of Investment 1
                cout << " " << endl;                                                                     //Space between text outputs

                cout << "Investment 2: " << UsersBank.getInvestment2().getName() << endl;                //Outputs the name of Investment 2
                    float balance2 = UsersBank.getInvestment2().getTotalInvestment();                    //This code applies modifications to the price
                    balance2 = (balance2*(rand()%10)/100) + balance2;                                    //FIXME: This code should change based on financial data
                    UsersBank.getInvestment2().setTotalInvestment(balance2);                             //Sets total investment for Investment 2 to new value
                cout << "Investment 2 Shares: " << UsersBank.getInvestment2().getNumberOwned() << endl;  //Outputs the number of shares of Investment 2
                cout << "Total Investment: " << balance2 << endl;                                        //Outputs the total investment of Investment 2
                cout << " " << endl;                                                                     //Space between text outputs

                cout << "Investment 3: " << UsersBank.getInvestment3().getName() << endl;                //Outputs the name of Investment 3
                    float balance3 = UsersBank.getInvestment3().getTotalInvestment();                    //This code applies modifications to the price
                    balance3 = (balance3*(rand()%10)/100) + balance3;                                    //FIXME: This code should change based on financial data
                    UsersBank.getInvestment3().setTotalInvestment(balance3);                             //Sets total investment for Investment 3 to new value
                cout << "Investment 3 Shares: " << UsersBank.getInvestment3().getNumberOwned() << endl;  //Outputs the number of shares of Investment 3
                cout << "Total Investment: " << balance3 << endl;                                        //Outputs the total investment of Investment 3
                cout << " " << endl;                                                                     //Space between text outputs

                cout << "Investment 4: " << UsersBank.getInvestment4().getName() << endl;                //Outputs the name of Investment 4
                    float balance4 = UsersBank.getInvestment4().getTotalInvestment();                    //This code applies modifications to the price
                    balance4 = (balance4*(rand()%10)/100) + balance4;                                    //FIXME: This code should change based on financial data
                    UsersBank.getInvestment4().setTotalInvestment(balance4);                             //Sets total investment for Investment 4 to new value
                cout << "Investment 4 Shares: " << UsersBank.getInvestment4().getNumberOwned() << endl;  //Outputs the number of shares of Investment 4
                cout << "Total Investment: " << balance4 << endl;                                        //Outputs the total investment of Investment 4
                cout << " " << endl;                                                                     //Space between text outputs

                cout << "Investment 5: " << UsersBank.getInvestment5().getName() << endl;                //Outputs the name of Investment 5
                    float balance5 = UsersBank.getInvestment5().getTotalInvestment();                    //This code applies modifications to the price
                    balance5 = (balance5*(rand()%10)/100) + balance5;                                    //FIXME: This code should change based on financial data
                    UsersBank.getInvestment5().setTotalInvestment(balance5);                             //Sets total investment for Investment 5 to new value
                cout << "Investment 5 Shares: " << UsersBank.getInvestment5().getNumberOwned() << endl;  //Outputs the number of shares of Investment 5
                cout << "Total Investment: " << balance5 << endl;                                        //Outputs the total investment of Investment 5
                cout << " " << endl;                                                                     //Space between text outputs
                    break;                                                                               //Breaks Case 2        
                }

                case 3: {            //Case 3
                                     //INSERT CODE HERE FOR MODIFYING INVESTMENTS!!!!
                break;               //Breaks Case 3
                }

                case 4: {                                                               //Case 4
                    if (day >= 10) {                                                    //If day is > 10, the simulation is now done
                    cout << "You have reached the end of the simulation!" << endl;      //Output, simulation has now ended
                    cout << " " << endl;                                                //Space between text outputs
                    cout << "Press ENTER to see how you did overall" << endl;           //Output, press ENTER to see final analysis
                    menuActive = false;                                                 //Set boolean to false, exit main menu
                    programActive = false;                                              //Set boolena to fales, exit main program loop
                    break;                                                              //Breaks case 4
                    }

                    else {                                                              //If day is NOT > 10, increment day and continue main program loop                                                                                            
                         day++;                                                         //Increment day
                    }
                    break;                                                              //Breaks case 4
                }

                default: {                                                    //Default Case
                    cout << "Please enter a valid option" << endl;            //Output, user must enter an option between 1 and 4
                    cin.clear();                                              //Clear error flags
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');      //Clear the input buffer
                }
        }

        } while (menuActive);                                                 //Loop continues to run while boolean "menuActive" is true
    } while (programActive);                                                  //Loop continues to run while boolean "programActive" is true

    cout << "OVERALL ANALYSIS:" << endl;                                      //Output, overall analysis of users simulaiton results
    /*     --- ADD CODE HERE!!!! ---*/                                        //FIXME: ADD OVERALL ANALYSIS METHOD
}

//////////////////////////////////////StartUp//////////////////////////////////////
float startUp(){      

    string spinThatWheel;                                                     //Creates string spinThatWheel

    cout << "Welcome to the Market Trading Simulator" << endl;                //Output, welcome to the simulator
    cout << "This simulator will start you off with a small loan!" << endl;   //Output, user will get initial capital
    cout << "Spin the wheel to win your initial capital!" << endl;            //Output, user will spin a whell
    cout << " " << endl;                                                      //Space between text outputs
    cout << "Press ENTER to spin the wheel!" << endl;                         //Output, user must hit ENTER to continue
    std::cin.ignore();                                                        //Ignores inputs until ENTER is pressed

    float initialCapital = prizeWheel();                                      //Intial capital is set to the return of method prizewheel (float)
    return initialCapital;                                                    //Returns the users intial capital
}

//////////////////////////////////////Prize Wheel//////////////////////////////////////
float prizeWheel() {

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
    float moneyWonInt;                                                        //Creates a float, "moneyWonInt" that will be returned by this method

    if (moneyWon == "$100,000.00"){                                           //If string "moneyWon" equals "$100,000.00" then...
        moneyWonInt = 100000.00;                                              //Float "moneyWonInt" is set to 100,000.00
    }
    else if (moneyWon == " $50,000.00"){                                      //If string "moneyWon" equals "$50,000.00" then...
        moneyWonInt = 50000.00;                                               //Float "moneyWonInt" is set to 50,000.00
    }
    else if (moneyWon == " $75,000.00"){                                      //If string "moneyWon" equals "$75,000.00" then...
        moneyWonInt = 75000.00;                                               //Float "moneyWonInt" is set to 75,000.00
    }
    else if (moneyWon == " $87,500.00"){                                      //If string "moneyWon" equals "$87,500.00" then...
        moneyWonInt = 87500.00;                                               //Float "moneyWonInt" is set to 87,500.00
    }
    else if (moneyWon == " $67,500.00"){                                      //If string "moneyWon" equals "$67,500.00" then...
        moneyWonInt = 67500.00;                                               //Float "moneyWonInt" is set to 67,500.00
    }

    cout << "You have won " << moneyWon << " from the Wheel of Small Loans!" << endl;      //Output, user has won $ "moneyWon" in initial capital
    cout << " " << endl;                                                                   //Space between text outputs
    return moneyWonInt;                                                                    //Method returns float value for users initial capital
}

//////////////////////////////////////Prize Setter for Prize Wheel//////////////////////////////////////
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

//////////////////////////////////////Random Number Generator//////////////////////////////////////
int randNum(int min, int max) {                       //Takes a minimum and maximum value
    srand (static_cast <unsigned> (time(0)));         //Based C was invented
    return rand() % max + min;                        //Returns a random value
}

//////////////////////////////////////Bank Selector Method//////////////////////////////////////
Bank bankSelector(float initialCapital){                     

    srand (static_cast <unsigned> (time(0)));        //Users random number generator based on time

    int bankSelection;                               //Creates integer bank seleciton
    bool bankSelectionBool = true;                   //Creates boolean for bank selection loop

    while (bankSelectionBool){                                                               //Loop repeats while boolean "bankSelectionBool" is true
        cout << "The first major decision you must make is selecting your bank!" << endl;    //Output, time to select a bank
        cout << " " << endl;                                                                 //Space between text outputs
        cout << "You will have 3 choices:" << endl;                                          //User will have 3 choices
        cout << " " << endl;                                                                 //Space between text outputs
        cout << "1. The First National Bank of Cryptocurrency" << endl;                      //Option 1 for user bank
        cout << "Press 1 to see more info on this bank" << endl;                             //User press 1 to select Option 1
        cout << " " << endl;                                                                 //Space between text outputs
        cout << "2. Shred It Credit Union" << endl;                                          //Option 2 for user bank
        cout << "Press 2 to see more info on this bank" << endl;                             //User press 2 to select Option 2
        cout << " " << endl;                                                                 //Space between text outputs
        cout << "3. Steal My Money Financial Services" << endl;                              //Option 3 for user bank
        cout << "Press 3 to see more info on this bank" << endl;                             //User press 3 to select Option 3

        bool bankBool2 = true;                      //Creates another boolean for bank information loop

        Bank UserBank;                              //Creates a bank object to be used as the users bank

        while (bankBool2){                          //Loops while "bankbool2" is true

            cin >> bankSelection;                   //User input for selection of bank

            if (bankSelection == 1) {
                //INTEREST RATE GENERATION
                UserBank.setMaxIR(0.03);     //LOW INTEREST RATE OFFERED BY NATIONAL BANK
                UserBank.setMinIR(0.01);     //LOW INTEREST RATE OFFERED BY NATIONAL BANK
                UserBank.setIR(UserBank.getMinIR() + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (UserBank.getMaxIR() - UserBank.getMinIR()))));
                //FEES GENERATION
                UserBank.setMaxFee(300);     //High INITIAL FEE OFFERED BY CREDIT UNION
                UserBank.setMinFee(175);     //High INITIAL FEE OFFERED BY CREDIT UNION
                UserBank.setFee(rand() %  + (UserBank.getMaxFee() - UserBank.getMinFee()) + UserBank.getMinFee());
                //Information Setters
                UserBank.setBankName("The First National Bank of Cryptocurrency");
                UserBank.setBankType("National Bank");
                //Bonuses Setter
                UserBank.setMaxBonus(300);   //MEDIUM BONUS OFFERED BY NATIONAL BANK
                UserBank.setMinBonus(200);   //MEDIUM BONUS OFFERED BY NATIONAL BANK
                UserBank.setBonus(rand() % (UserBank.getMaxBonus() - UserBank.getMinBonus()) + UserBank.getMinBonus());
                bankBool2 = false;
                //Initial Capital Setter
                UserBank.setAccountBalance(initialCapital -  (float) UserBank.getFee() +  (float) UserBank.getBonus());
            }

            else if (bankSelection == 2) {
                //INTEREST RATE GENERATION
                UserBank.setMaxIR(0.09);     //HIGH INTEREST RATE OFFERED BY CREDIT UNION
                UserBank.setMinIR(0.04);     //HIGH INTEREST RATE OFFERED BY CREDIT UNION
                UserBank.setIR(UserBank.getMinIR() + static_cast <float> (rand()) /
                                             (static_cast <float> (RAND_MAX / (UserBank.getMaxIR() - UserBank.getMinIR()))));
                //FEES GENERATION
                UserBank.setMaxFee(50);      //LOW INITIAL FEE OFFERED BY CREDIT UNION
                UserBank.setMinFee(10);      //LOW INITIAL FEE OFFERED BY CREDIT UNION
                UserBank.setFee(rand() %  + (UserBank.getMaxFee() - UserBank.getMinFee()) + UserBank.getMinFee());
                //Information Setters
                UserBank.setBankName("Shred It Credit Union");
                UserBank.setBankType("Credit Union");
                //Bonuses Setter
                UserBank.setMaxBonus(100);   //LOW BONUS OFFERED BY CREDIT UNION
                UserBank.setMinBonus(20);    //LOW BONUS OFFERED BY CREDIT UNION
                UserBank.setBonus(rand() % (UserBank.getMaxBonus() - UserBank.getMinBonus()) + UserBank.getMinBonus());
                bankBool2 = false;
                //Initial Capital Setter
                UserBank.setAccountBalance(initialCapital - ((float) UserBank.getFee()) + ((float) UserBank.getBonus()));
            }

            else if (bankSelection == 3) {
                //INTEREST RATE GENERATION
                UserBank.setMaxIR(0.07);     //MEDIUM INTEREST RATE OFFERED BY FINANCIAL SERVICES
                UserBank.setMinIR(0.05);     //MEDIUM INTEREST RATE OFFERED BY FINANCIAL SERVICES
                UserBank.setIR(UserBank.getMinIR() + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (UserBank.getMaxIR() - UserBank.getMinIR()))));
                //FEES GENERATION
                UserBank.setMaxFee(70);      //MEDIUM INITIAL FEE OFFERED BY FINANCIAL SERVICES
                UserBank.setMinFee(50);      //MEDIUM INITIAL FEE OFFERED BY FINANCIAL SERVICES
                UserBank.setFee(rand() % (UserBank.getMaxFee() - UserBank.getMinFee()) + UserBank.getMinFee());
                //Information Setters
                UserBank.setBankName("Steal My Money Financial Services");
                UserBank.setBankType("Financial Services");
                //Bonuses Setter
                UserBank.setMaxBonus(200);   //LOW BONUS OFFERED BY NATIONAL BANK
                UserBank.setMinBonus(100);   //LOW BONUS OFFERED BY NATIONAL BANK
                UserBank.setBonus(rand() % (UserBank.getMaxBonus() - UserBank.getMinBonus()) + UserBank.getMinBonus());
                bankBool2 = false;
                //Initial Capital Setter
                UserBank.setAccountBalance(initialCapital - ((float) UserBank.getFee()) + ((float) UserBank.getBonus()));
            }

            else {
                cout << "That is not a valid option.  Please choose a bank." << endl;    //If the user does not input an integer between 1 and 3 inclusive, the loop will repeat
                cout << " " << endl;                                                     //Space between text outputs
            }
        }

        //BANK INFORMATION OUTPUT AFTER INFORMATION IS REQUESTED
        cout << "You have elected to see more information on " << UserBank.getBankName() << endl;   //Bank info is requested about
        cout << " " << endl;                                                                        //Space between text outputs
        cout << "Bank Type: " << UserBank.getBankType() << endl;                                    //Output, type of selected bank
        std::cout << std::fixed;                                                                    //Sets floats to fixed point location
        std::cout << std::setprecision(2);                                                          //Sets float precision to 2 decimal places
        cout << "Interest Rate: " << UserBank.getIR() << "%" << endl;                               //Output, interest rate of selected bank
        cout << "Fees: $" << UserBank.getFee() << ".00" << endl;                                    //Output, fees of selected bank
        cout << "Bonuses: $" << UserBank.getBonus() << ".00 sign up bonus" << endl;                 //Output, bonuses of selected bank
        cout << " " << endl;                                                                        //Space between text outputs

        string bankChoice;                                                                          //Creates a string, "bankChoice"
        bool bankChoiceBool = true;                                                                 //Creates a boolean, "bankChoiceBool" and sets it to true

        while (bankChoiceBool){                                                                                     //Loops while "bankChoiceBool" is true

            cout << "Would you like to set up an account with this bank? y/n" << endl;                              //Output, does user want this bank
            cin >> bankChoice;                                                                                      //Input, does user want this bank

            if (bankChoice == "Yes" || bankChoice == "Y" || bankChoice == "yes" || bankChoice == "y"){              //If user input is yes...
                cout << "Thank you for choosing " << UserBank.getBankName() << "!" << endl;                         //Bank is selected
                cout << " " << endl;                                                                                //Space between text outputs
                return UserBank;                                                                                    //Return Bank object "UserBank"
            }
            else if (bankChoice == "No" || bankChoice == "N" || bankChoice == "no" || bankChoice == "n"){           //If user input is no...
                cout << "Okay, you may continue considering your options." << endl;                                 //Bank is not selected and loop will repteat
                cout << " " << endl;                                                                                //Space between text outputs
                bankChoiceBool = false;                                                                             //Boolean, "bankChoiceBool" is set to false, will return to outer loop to continue bank selection process
            }
            else {                                                                                                  //If user input is not yes OR no
                cout << "That was not a valid option.  Please type Yes or No." << endl;                             //Output, please try again, loop will repeat until user input is yes or no
                cout << " " << endl;                                                                                //Space between text outputs
            }
        }
    }
}

//////////////////////////////////////Create Investment Method//////////////////////////////////////
Investment createInvestment(Bank userBank, Investment userInvestmentInput) {        

    Bank UsersBank = userBank;                            //Creates Bank object, "UsersBank"
    Investment UserInvestment = userInvestmentInput;      //Creates Investment object, "UserInvestment"
    string type;                                          //Creates string, "type"
    string name;                                          //Creates string, "name"
    int stability;                                        //Creates int, "stability"
    int value;                                            //Creates int, "value"
    int previousValue;                                    //Creates int, "previousValue"
    int predictedValue;                                   //Creates int, "predictedVale"
    int numberOwned;                                      //Creates int, "numberOwned"
    int valueOwned;                                       //Creates int, "valueOwned"
    int numberSold;                                       //Creates int, "numberSold"

    int investment = 0;                                   //Creates int, "investment" and set it to 0
    string investmentChoice;                              //Creats string, "investmentChoice"
    bool investmentResearcher = true;                     //Creates boolean, "investmentResearcher" and sets it to true

    while (investmentResearcher) {                                                       //Loops while "investmentResearcher" is true

        cout << " " << endl;                                                             //Space between text outputs
        cout << "Investable Profit: " << UsersBank.getAccountBalance() << endl;          //Output, investable profit, gets users account balance from the users bank
        cout << "Which investment would you like to research?" << endl;                  //Output, which investment would you like to research
        cout << " " << endl;                                                             //Space between text outputs
        cout << "1. BitCoin" << endl;                                                    //Output, BitCoin
        cout << "2. FJSCX" << endl;                                                      //Output, FJSCX
        cout << "3. Banana Inc." << endl;                                                //Output, Banana Inc.
        cout << " " << endl;                                                             //Space between text outputs
        cin >> investment;                                                               //Input, user chooses in investment (1-3, 4+ is default)

        switch (investment) {                                            //Switch statement for user input

            case 1:                                                      //Case 1
                name = "BitCoin";                                        //Name is set to BitCoin
                type = "Cyber Currency";                                 //Type is set to Cyber Currency
                stability = 3;                                           //Stbaility is set to 3
                value = 14000;                                           //Value is set to 14000
                cout << "Name: " << name << endl;                        //Output, name
                cout << "Type: " << type << endl;                        //Output, type
                cout << "Stability: " << stability << endl;              //Output, stability
                cout << "Value $" << value << ".00" << endl;             //Output, value
                break;

            case 2:                                                      //Case 2
                name = "FJSCX";                                          //Name is set to FJSCX
                type = "Mutual Fund";                                    //Type is set to Mutual Fund      
                stability = 8;                                           //Stability is set to 8
                value = 260;                                             //Value is set to 260
                cout << "Name: " << name << endl;                        //Output, name
                cout << "Type: " << type << endl;                        //Output, type
                cout << "Stability: " << stability << endl;              //Output, stability
                cout << "Value $" << value << ".00" << endl;             //Output, value
                break;

            case 3:                                                      //Case 3
                name = "Banana Inc.";                                    //Name is set to Banana Inc.
                type = "Stock";                                          //Type is set to Stock 
                stability = 7;                                           //Stability is set to 7
                value = 53;                                              //Value is set to 53
                cout << "Name: " << name << endl;                        //Output, name  
                cout << "Type: " << type << endl;                        //Output, type
                cout << "Stability: " << stability << endl;              //Output, stability
                cout << "Value $" << value << ".00" << endl;             //Output, value
                break;

            default:                                                     //Case Default
                name = "Default Inc.";                                   //Name is set to Default Inc.
                type = "Stock";                                          //Type is set to Stock 
                stability = 4;                                           //Stability is set to 4
                value = 1100;                                            //Value is set to 1000
                cout << "Name: " << name << endl;                        //Output, name  
                cout << "Type: " << type << endl;                        //Output, type
                cout << "Stability: " << stability << endl;              //Output, stability
                cout << "Value $" << value << ".00" << endl;             //Output, value
        }

        cout << " " << endl;                                                                                                   //Space between text outputs
        cout << "Would you like to invest in " << name << "?" << endl;                                                         //Output, make this investment?
        cout << "Yes or No" << endl;                                                                                           //Output, yes or no
        cin >> investmentChoice;                                                                                               //Input, user chooses yes or no

        if (investmentChoice == "Yes" || investmentChoice == "yes" || investmentChoice == "Y" ||
            investmentChoice == "y") {                                                                                         //If user input is yes...
            cout << " " << endl;                                                                                               //Space between text outputs

            float maxSharesBuyable = UsersBank.getAccountBalance() / value;                                                    //Float, "maxSharesBuyable" equals bank account balance / value of investment 
            float numberOfSharesToPurchase;                                                                                    //Float, "numberOfSharesToPurchase"

            cout << "You may buy up to " << maxSharesBuyable << " shares of " << name << endl;                                 //Output, maxSharesBuyable
            cout << "How many shares would you like to purchase?" << endl;                                                     //Output, how many would user like to purchase?
            cin >> numberOfSharesToPurchase;                                                                                   //Input, user chooses how many shares to purchase

            if (numberOfSharesToPurchase <= maxSharesBuyable) {                                                                //If the user chooses a feasible number to purchase...
                UserInvestment.setNumberOwned(numberOfSharesToPurchase);                                                       //Number of shares owned is set to the users choice
                float a = value * numberOfSharesToPurchase;                                                                    //Float, "a" is set to the total value of shares owned by the user (value * number of shares)
                UserInvestment.setTotalInvestment(a);                                                                          //Total investment is set to float a
                cout << numberOfSharesToPurchase << " shares of " << name << " have been added to your portfolio."<< endl;     //Output, number of shares of X have been added to the users portfolio
                cout << "Type: " << type << endl;                                                                              //Output, type of investment
                cout << "Value: $" << value << ".00" << endl;                                                                  //Output, value
                cout << "Total Investment: $" << UserInvestment.getTotalInvestment() << endl;                                  //Output, total investment (value * number of shares)
                UserInvestment.setName(name);                                                                                  //Set name in Investment object to string "name"
                UserInvestment.setType(type);                                                                                  //Set type in Investment object to string "type"
                UserInvestment.setStability(stability);                                                                        //Set stability in Investment object to string "investment" 
                UserInvestment.setValue(value);                                                                                //Set value in Investment object to float "value"
                UserInvestment.setNumberOwned(numberOfSharesToPurchase);                                                       //Set numberOwned in Investment object to float "numberOfSharesToPurchase" 
                float newBalance = UsersBank.getAccountBalance() - UserInvestment.getTotalInvestment();                        //Float, "newBalance" is equal to old balance in users bank account - total Investment (value * number of shares)
                UsersBank.setAccountBalance(newBalance);                                                                       //Set account balance in users bank to float "newBalance"
                cout << "Account Balance: $" << UsersBank.getAccountBalance() << endl;                                         //Output, users new account balance from the users bank
                investmentResearcher = false;                                                                                  //Set boolean "investmentResearcher" to false to end the loop
                return UserInvestment;                                                                                         //Return Investment "UserInvestment"
            }

            else {
                if (numberOfSharesToPurchase > maxSharesBuyable) {                                                             //If number of shares is > how many can be purchased...
                    cout << "You cannot afford that many shares" << endl;                                                      //Output, user cannot afford this many shares
                    cout << "Please enter a valid number" << endl;                                                             //Output, please enter a valid number
                } else {
                    cout << "Please enter a valid number" << endl;                                                             //If user input is not an integer value, Output, please enter a valid number
                }
            }
        }
    }
}

