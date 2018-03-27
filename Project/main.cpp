#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#include "Bank.h"
#include "Investment.h"

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

//MAIN MENU METHOD
void mainMenu(Bank inputBank){

    Bank UsersBank = inputBank;
    bool programActive;
    int day = 1;

    do {
        bool menuActive = true;
        int userInput;

        cout << "Welcome to your new bank!" << endl;
        cout << " " << endl;
        cout << "Hello, I am your teller, " << "Max" << "." << endl; //ADD TELLER NAME HERE
        cout << "What is your name?" << endl;
        string userName;
        cin >> userName;
        UsersBank.setAccountHolderName(userName);
        cout << "It's a pleasure to meet you, " << UsersBank.getAccountHolderName() << endl;
        cout << " " << endl;
        cout << "Let's start your portfolio by making 5 investment decisions" << endl;
        cout << " " << endl;
        cout << "Investment 1: " << endl;
        Investment userInvestment1;
        UsersBank.setInvestment1(createInvestment(UsersBank, userInvestment1));
        float bal = UsersBank.getAccountBalance() - userInvestment1.getTotalInvestment();
        cout << "bal: " << bal;
        UsersBank.setAccountBalance(bal);

        cout << "test " << UsersBank.getAccountBalance() << endl;
        cout << "test " << UsersBank.getInvestment1().getTotalInvestment() << endl;

        cout << " " << endl;
        cout << "Investment 2: " << endl;
        Investment userInvestment2;
        UsersBank.setInvestment2(createInvestment(UsersBank, userInvestment2));
        cout << " " << endl;
        cout << "Investment 3: " << endl;
        Investment userInvestment3;
        UsersBank.setInvestment3(createInvestment(UsersBank, userInvestment3));
        cout << " " << endl;
        cout << "Investment 4: " << endl;
        Investment userInvestment4;
        UsersBank.setInvestment4(createInvestment(UsersBank, userInvestment4));
        cout << " " << endl;
        cout << "Investment 5: " << endl;
        Investment userInvestment5;
        UsersBank.setInvestment5(createInvestment(UsersBank, userInvestment5));

        cout << " " << endl;
        cout << "Now that you have made your investment decision..." << endl;
        cout << "What can I help you with today?" << endl;

        do {
            cout << " " << endl;
            cout << "Day " << day << endl;
            cout << " " << endl;
            cout << "1. Check account info" << endl;
            cout << "2. Check investments" << endl;
            cout << "3. Modify investments" << endl;
            cout << "4. Leave bank and end day" << endl;
            cin >> userInput;
            if (userInput == 1) {
                cout << " " << endl;
                cout << "Bank: " << UsersBank.getBankName() << endl;
                cout << "Account Holder: " << UsersBank.getAccountHolderName() << endl;
                cout << "Balance: $" << UsersBank.getAccountBalance() << endl;
            }
            else if (userInput == 2) {
                cout << " " << endl;
                cout << "Investment 1: " << UsersBank.getInvestment1().getName() << endl;
                cout << "Investment 1 Shares: " << UsersBank.getInvestment1().getNumberOwned() << endl;
                cout << "Total Investment: " << UsersBank.getInvestment1().getTotalInvestment() << endl;
                cout << " " << endl;
                cout << "Investment 2: " << UsersBank.getInvestment2().getName() << endl;
                cout << "Investment 2 Shares: " << UsersBank.getInvestment2().getNumberOwned() << endl;
                cout << "Total Investment: " << UsersBank.getInvestment2().getTotalInvestment() << endl;
                cout << " " << endl;
                cout << "Investment 3: " << UsersBank.getInvestment3().getName() << endl;
                cout << "Investment 3 Shares: " << UsersBank.getInvestment3().getNumberOwned() << endl;
                cout << "Total Investment: " << UsersBank.getInvestment3().getTotalInvestment() << endl;
                cout << " " << endl;
                cout << "Investment 4: " << UsersBank.getInvestment4().getName() << endl;
                cout << "Investment 4 Shares: " << UsersBank.getInvestment4().getNumberOwned() << endl;
                cout << "Total Investment: " << UsersBank.getInvestment4().getTotalInvestment() << endl;
                cout << " " << endl;
                cout << "Investment 5: " << UsersBank.getInvestment5().getName() << endl;
                cout << "Investment 5 Shares: " << UsersBank.getInvestment5().getNumberOwned() << endl;
                cout << "Total Investment: " << UsersBank.getInvestment5().getTotalInvestment() << endl;
                cout << " " << endl;
            }
            else if (userInput == 3){
            }
            else if (userInput == 4){
                if (day >= 10){
                    cout << "You have reached the end of the simulation!" << endl;
                    cout << " " << endl;
                    cout << "Press ENTER to see how you did overall" << endl;
                    menuActive = false;
                    programActive = false;
                }
                else {
                    day++;
                }
            }
            else if (userInput == 5){
            }
            else {
                cout << "Please enter a valid option" << endl;
                cin.clear(); //Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clear the input buffer
            }
        } while (menuActive);
    } while (programActive);

    cout << "OVERALL ANALYSIS:" << endl;
}

//////////////////////////////////////StartUp//////////////////////////////////////
float startUp(){

    string spinThatWheel;

    cout << "Welcome to the Market Trading Simulator" << endl;
    cout << "This simulator will start you off with a small loan!" << endl;
    cout << "Spin the wheel to win your initial capital!" << endl;
    cout << " " << endl;
    cout << "Press ENTER to spin the wheel!" << endl;
    std::cin.ignore();

    float initialCapital = prizeWheel();
    return initialCapital;
}

//////////////////////////////////////Prize Wheel//////////////////////////////////////
float prizeWheel() {

    srand (static_cast <unsigned> (time(0)));

    int maxSpins = 12;
    int spinTimes = (rand() % maxSpins + 8);

    for (int i = 1; i <= spinTimes; i++){
        cout << "======================" << endl;
        cout << "||   " << prizeSetter(i) << "    ||" << endl;
        cout << "||   " << prizeSetter(i + 1) <<  "    ||" << endl;
        cout << "||-> " << prizeSetter(i + 2) << "  <-||" << endl;
        cout << "||   " << prizeSetter(i + 3) << "    ||" << endl;
        cout << "||   " << prizeSetter(i + 4) << "    ||" << endl;
        cout << "======================" << endl;
    }

    string moneyWon = prizeSetter(spinTimes + 2);
    float moneyWonInt;

    if (moneyWon == "$100,000.00"){
        moneyWonInt = 100000.00;
    }
    else if (moneyWon == " $50,000.00"){
        moneyWonInt = 50000.00;
    }
    else if (moneyWon == " $75,000.00"){
        moneyWonInt = 75000.00;
    }
    else if (moneyWon == " $87,500.00"){
        moneyWonInt = 87500.00;
    }
    else if (moneyWon == " $67,500.00"){
        moneyWonInt = 67500.00;
    }

    cout << "You have won " << moneyWon << " from the Wheel of Small Loans!" << endl;
    cout << " " << endl;
    return moneyWonInt;
}

//////////////////////////////////////Prize Setter for Prize Wheel//////////////////////////////////////
string prizeSetter(int prizeNumber){

    if (prizeNumber == 1 || prizeNumber  == 6 || prizeNumber  == 11 || prizeNumber  == 16 || prizeNumber  == 21){
        return "$100,000.00";
    }
    else if (prizeNumber == 2 || prizeNumber  == 7 || prizeNumber  == 12 || prizeNumber  == 17 || prizeNumber  == 22){
        return " $50,000.00";
    }
    else if (prizeNumber == 3 || prizeNumber  == 8 || prizeNumber  == 13 || prizeNumber  == 18 || prizeNumber  == 23){
        return " $75,000.00";
    }
    else if (prizeNumber == 4 || prizeNumber  == 9 || prizeNumber  == 14 || prizeNumber  == 19 || prizeNumber  == 24){
        return " $87,500.00";
    }
    else if (prizeNumber == 5 || prizeNumber  == 10 || prizeNumber  == 15 || prizeNumber  == 20 || prizeNumber  == 25){
        return " $67,500.00";
    }
    return 0;
}

//////////////////////////////////////Random Number Generator//////////////////////////////////////
int randNum(int min, int max) {
    srand (static_cast <unsigned> (time(0)));
    return rand() % max + min;
}

Bank bankSelector(float initialCapital){

    srand (static_cast <unsigned> (time(0)));

    int bankSelection;
    bool bankSelectionBool = true;

    while (bankSelectionBool){
        cout << "The first major decision you must make is selecting your bank!" << endl;
        cout << " " << endl;
        cout << "You will have 3 choices:" << endl;
        cout << " " << endl;
        cout << "1. The First National Bank of Cryptocurrency" << endl;
        cout << "Press 1 to see more info on this bank" << endl;
        cout << " " << endl;
        cout << "2. Shred It Credit Union" << endl;
        cout << "Press 2 to see more info on this bank" << endl;
        cout << " " << endl;
        cout << "3. Steal My Money Financial Services" << endl;
        cout << "Press 3 to see more info on this bank" << endl;

        bool bankBool2 = true;

        Bank UserBank;

        while (bankBool2){
            cin >> bankSelection;
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
                UserBank.setFee(rand() %  + (UserBank.getMaxFee() - UserBank.getMinFee()) + UserBank.getMinFee());
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
                cout << "That is not a valid option.  Please choose a bank." << endl;
                cout << " " << endl;
            }
        }

        //BANK INFORMATION
        cout << "You have elected to see more information on " << UserBank.getBankName() << endl;
        cout << " " << endl;
        cout << "Bank Type: " << UserBank.getBankType() << endl;
        std::cout << std::fixed;
        std::cout << std::setprecision(2);
        cout << "Interest Rate: " << UserBank.getIR() << "%" << endl;
        cout << "Fees: $" << UserBank.getFee() << ".00" << endl;
        cout << "Bonuses: $" << UserBank.getBonus() << ".00 sign up bonus" << endl;
        cout << " " << endl;

        string bankChoice;
        bool bankChoiceBool = true;

        while (bankChoiceBool){

            cout << "Would you like to set up an account with this bank?" << endl;
            cin >> bankChoice;

            if (bankChoice == "Yes" || bankChoice == "Y" || bankChoice == "yes" || bankChoice == "y"){
                cout << "Thank you for choosing " << UserBank.getBankName() << "!" << endl;
                cout << " " << endl;
                return UserBank;
            }
            else if (bankChoice == "No" || bankChoice == "N" || bankChoice == "no" || bankChoice == "n"){
                cout << "Okay, you may continue considering your options." << endl;
                cout << " " << endl;
                bankChoiceBool = false;
            }
            else {
                cout << "That was not a valid option.  Please type Yes or No." << endl;
                cout << " " << endl;
            }
        }
    }
}

Investment createInvestment(Bank userBank, Investment userInvestmentInput) {

    Bank UsersBank = userBank;
    Investment UserInvestment = userInvestmentInput;
    string type;
    string name;
    int stability;
    int value;
    int previousValue;
    int predictedValue;
    int numberOwned;
    int valueOwned;
    int numberSold;

    int investment = 0;
    string investmentChoice;
    bool investmentResearcher = true;

    while (investmentResearcher) {

        cout << " " << endl;
        cout << "Investable Profit: " << UsersBank.getAccountBalance() << endl; //FIXME: Account balance is not updating
        cout << "Which investment would you like to research?" << endl;
        cout << " " << endl;
        cout << "1. BitCoin" << endl;
        cout << "2. FJSCX" << endl;
        cout << "3. Banana Inc." << endl;
        cout << " " << endl;
        cin >> investment;

        switch (investment) {
            case 1:
                name = "BitCoin";
                type = "Cyber Currency";
                stability = 3;
                value = 14000;
                cout << "Name: " << name << endl;
                cout << "Type: " << type << endl;
                cout << "Stability: " << stability << endl;
                cout << "Value $" << value << ".00" << endl;
                break;

            case 2:
                name = "FJSCX";
                type = "Mutual Fund";
                stability = 8;
                value = 260;
                cout << "Name: " << name << endl;
                cout << "Type: " << type << endl;
                cout << "Stability: " << stability << endl;
                cout << "Value $" << value << ".00" << endl;
                break;

            case 3:
                name = "Banana Inc.";
                type = "Stock";
                stability = 7;
                value = 53;
                cout << "Name: " << name << endl;
                cout << "Type: " << type << endl;
                cout << "Stability: " << stability << endl;
                cout << "Value $" << value << ".00" << endl;
                break;

            default:
                name = "Default Inc.";
                type = "Stock";
                stability = 4;
                value = 1100;
                cout << "Name: " << name << endl;
                cout << "Type: " << type << endl;
                cout << "Stability: " << stability << endl;
                cout << "Value $" << value << ".00" << endl;
        }

        cout << " " << endl;
        cout << "Would you like to invest in " << name << "?" << endl;
        cout << "Yes or No" << endl;
        cin >> investmentChoice;

        if (investmentChoice == "Yes" || investmentChoice == "yes" || investmentChoice == "Y" ||
            investmentChoice == "y") {
            cout << " " << endl;

            float maxSharesBuyable = UsersBank.getAccountBalance() / value;
            float numberOfSharesToPurchase;

            cout << "You may buy up to " << maxSharesBuyable << " shares of " << name << endl;
            cout << "How many shares would you like to purchase?" << endl;
            cin >> numberOfSharesToPurchase;

            if (numberOfSharesToPurchase <= maxSharesBuyable) {
                UserInvestment.setNumberOwned(numberOfSharesToPurchase);
                float a = value * numberOfSharesToPurchase;
                UserInvestment.setTotalInvestment(a);
                cout << numberOfSharesToPurchase << " shares of " << name << " have been added to your portfolio."
                     << endl;
                cout << "Type: " << type << endl;
                cout << "Value: $" << value << ".00" << endl;
                cout << "Total Investment: $" << UserInvestment.getTotalInvestment() << endl;
                UserInvestment.setName(name);
                UserInvestment.setType(type);
                UserInvestment.setStability(stability);
                UserInvestment.setValue(value);
                UserInvestment.setNumberOwned(numberOfSharesToPurchase);
                float newBalance= UsersBank.getAccountBalance() - UserInvestment.getTotalInvestment();
                UsersBank.setAccountBalance(newBalance);
                cout << "Account Balance: $" << UsersBank.getAccountBalance() << endl;
                investmentResearcher = false;
                return UserInvestment;
            }

            else {
                if (numberOfSharesToPurchase > maxSharesBuyable) {
                    cout << "You cannot afford that many shares" << endl;
                    cout << "Please enter a valid number" << endl;
                } else {
                    cout << "Please enter a valid number" << endl;
                }
            }
        }
    }
}

