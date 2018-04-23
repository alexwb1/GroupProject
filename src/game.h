#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include "brokerage.h"
#include "adviser.h"
#include "asset.h"

class Game
{
    std::vector<Brokerage> brokerages; // vector that contains a list of the available brokerages
    std::vector<Adviser> advisers; // vector that contains a list of available assets
    std::vector<Asset> assets; // vector that contains a list of available assets

	std::vector<int> moneyHistory; // vector to contain history week by week of total money

    Brokerage *brokerage; // pointer to the brokerage that the user chose
    Adviser *adviser; // pointer to the adviser that the user chose

    std::string name; // name of the user
    int capital; // current amount of capital that a user does not have invested
    unsigned int week = 0; // unsigned integer value that represents the current week
    const int FINAL_WEEK = 26; // constant int value that represents the last week of available data

public:

    std::string getName(); // returns a string value representing the user's name
    Game(int capital, std::string name); // the Game constructor takes in an initial capital value and a player name

    int getCapital(); // returns an int value representing the capital that a user does not have invested
    void setCapital(int capital); // sets the capital member variable to a specified value

    bool nextWeek(); // increments the week by 1
    int getWeek(); // returns the current week
    int getFinalWeek(); // returns the final week of game play

    std::vector<Brokerage> getBrokerages(); // returns a vector of the available brokerages
    Brokerage* getBrokerage(); // returns a pointer to the user-chosen brokerage
    bool setBrokerage(const std::string &name); // sets the user-chosen brokerage
    void printBrokerages(); // prints all brokerages

    Adviser* getAdviser(); // returns a pointer to the user-chosen adviser
    std::vector<Adviser> getAdvisers(); // returns a list of the available advisers
    bool setAdviser(const std::string &name); // sets the user-chosen adviser
    void printAdvisers(); // prints all advisers

    std::vector<Asset> getAssets(); // returns a list of the available assets
    bool buyAsset(const std::string &name, unsigned int quantity); // adds an asset to the user's portfolio and substracts the price from the user's capital; returns true if this action can be taken, false if not
    bool sellAsset(const std::string &name, unsigned int quantity); // removes an asset from the user's portfolio and adds the price to the user's capital; returns true if this action can be taken, false if not
    std::vector<Asset> getPortfolio(); // returns a vector of assets each of which the user owns
    void printAssets(); // prints all of the current assets
    void printPortfolio(); // prints the current portfolio
    bool containsAsset(std::string assetName); // returns a boolean value indicating if a there is a certain asset
    int getBuyingPower(std::string assetName); // returns the number of shares that can be purchased given the current captial
    int getNumShares(std::string assetName); // returns of the number of shares of a specific investment

    std::string* printAd(std::string &asset); // returns a string representing advice from the adviser

	int getTotalMoney(); // returns sum of capital and monetary value of investments
    void printMoneyHistory(); // prints the history of account balances
    std::vector<int> getMoneyHistory(); // returns the money history vector

private:

    std::vector<Brokerage> loadBrokerages(const std::string &filename);
    std::vector<Adviser> loadAdvisers(const std::string &filename);
    std::vector<Asset> loadAssets(const std::string &filename);

};

// Definition of Game methods

Game::Game(int initialCapital, std::string name)
{
    // set the default variables
    this->capital = initialCapital;
    this->name = std::move(name);

    // load in brokerages, advisers, and assets from data folder
    this->brokerages = loadBrokerages("../data/brokerages.txt");
    this->advisers = loadAdvisers("../data/advisers.txt");
    this->assets = loadAssets("../data/assets.txt");

    // add the first value to moneyHistory
    moneyHistory.push_back(initialCapital);
}

int Game::getTotalMoney()
{
    // initializes equity as free capital
	int equity = capital;

	// gets the user portfolio
    std::vector<Asset> portfolio = getPortfolio();

    // iterates over the portfolio and adds up the total value
    for (auto &a : portfolio)
    {
        if(a.getQuantity() != 0)
        {
            // adds the current asset value to the overall equity value
            equity = equity + a.getQuantity()*a.getPriceAtWeek(week);
        }
    }

	return equity;
}

bool Game::nextWeek()
{
    // pushes the next weekly money value to money history
	moneyHistory.push_back(getTotalMoney());

	// if the week is is less than or equal to the final week
    if (week <= FINAL_WEEK)
    {
        // increments the week variable
        week++;

        // if the adviser fee is more than the user can afford
        if (adviser->getFee() >= capital)
        {
            // set capital to zero
            capital = 0;
        }
        else
        {
            // subtract the adviser fee from
            capital -= adviser->getFee();
        }
        // returns true if the next week is reached
        return true;
    }
    else {
        // returns false if the last week is reached
        return false;
    }
}

int Game::getWeek()
{
    return week;
}

int Game::getFinalWeek()
{
    return FINAL_WEEK;
}

std::string Game::getName()
{
    return name;
}

int Game::getCapital()
{
    return capital;
}

void Game::setCapital(int capital)
{
    this->capital = capital;
}

Brokerage* Game::getBrokerage()
{
    return brokerage;
}

bool Game::setBrokerage(const std::string &name)
{
    // iterates over brokerage until the proper brokerage is found
    for (int i = 0; i < brokerages.size(); i++)
    {
        if (brokerages[i].getName() == name)
        {
            // when the proper brokerage is found, the brokerage pointer is set to that brokerage
            brokerage = &brokerages[i];

            // returns true when the brokerage is set
            return true;
        }
    }

    // returns false when no brokerage is found
    return false;
}

Adviser *Game::getAdviser()
{
    return adviser;
}

bool Game::setAdviser(const std::string &name)
{
    // iterates over advisers until the correct adviser is found
    for (int i = 0; i < advisers.size(); i++)
    {
        if (advisers[i].getName() == name)
        {
            // when the correct adviser is found, set the adviser pointer to that adviser
            adviser = &advisers[i];

            // return true when the adviser is found and set
            return true;
        }
    }

    // return false when the adviser is not found
    return false;
}

bool Game::buyAsset(const std::string &name, unsigned int quantity)
{
    // iterates over assets until the correct asset is found
    for (int i = 0; i < assets.size(); i++)
    {
        if (assets[i].getTicker() == name)
        {
            // when the correct asset is found, check if the user has enough capital
            if (assets[i].getPriceAtWeek(week) * quantity > capital)
            {
                // if the user does not have enough capital, warn the user
                std::cout << "You do not have enough money to buy those shares.\n" << std::endl;

                // return false when the user does not have sufficient funds
                return false;
            }
            else
            {
                // charge the brokerage fee and the price of the asset times the number of shares to the user's capital
                capital -= assets[i].buy(quantity, week) + brokerage->getFee();

                // print out how many shares have been purchased
                std::cout << "You successfully purchased " << quantity << " shares of " << name << std::endl;

                // return true when the user successfully purchases the shares
                return true;
            }
        }
    }
    return false;

}

bool Game::sellAsset(const std::string &name, unsigned int quantity)
{
    // iterate over the assets vector until the proper asset is found
    for (auto &a : assets) {
        if (a.getTicker() == name)
        {
            if (quantity > a.getQuantity())
            {
                // if the user does not have enough asset to sell the entered amount
                std::cout << "You only own " << a.getQuantity() << " shares of " << a.getTicker() << std::endl;

                // return false if the sale is not made
                return false;
            }
            else
            {
                // if the user has the shares, sell the shares and charge the brokerage fee
                capital += a.sell(quantity, week) - brokerage->getFee();

                // return true when the sale takes place
                return true;
            }
        }
    }
}

std::string* Game::printAd(std::string &asset)
{
    // initialize the asset pointer to nullptr
    Asset *a = nullptr;

    // iterate over the assets vector
    for (int i = 0; i < assets.size(); i++)
    {
        if (assets[i].getTicker() == asset)
        {
            // when the correct asset is found, point a to the asset
            a = &assets[i];

            // break out of the loop because the asset has been found
            break;
        }
    }

    // get advice from the adviser about the asset
    return adviser->getAdvice(a, 0);
}

std::vector<Asset> Game::getPortfolio()
{
    // initializes portfolio vector of Assets
    std::vector<Asset> portfolio;

    // iterates over the assets list
    for (auto &a : assets)
    {
        // when the user owns a specific asset
        if (a.getQuantity() != 0)
        {
            // add the asset to the user's portfolio list
            portfolio.push_back(a);
        }
    }
    // return the list of assets that the user owns
    return portfolio;
}

std::vector<Brokerage> Game::loadBrokerages(const std::string &filename)
{
    // initialize necessary variables
    std::vector<Brokerage> b;
    std::string line;
    std::ifstream file(filename);

    // if the file is open, then read from it
    if (file.is_open())
    {
        while (getline(file, line))
        {
            // create brokerage object with name from the brokerages.txt file
            Brokerage brokerage(line);

            // push the constructed brokerage object to the list of brokerages
            b.push_back(brokerage);
        }

        // close the file
        file.close();
    }

    // if the file cannot be opened, alert the user
    else std::cout << "Unable to open " << filename << std::endl;

    // return the brokerages that have been created
    return b;
}

std::vector<Adviser> Game::loadAdvisers(const std::string &filename)
{
    // initializes necessary variables
    std::vector<Adviser> a;
    std::string line;
    std::ifstream file(filename);

    // if the file is open, read from the file
    if (file.is_open())
    {
        while (getline(file, line))
        {
            // constructs the Adviser object with the name read from advisers.txt
            Adviser adviser(line);

            // pushes the constructed adviser to the list of advisers
            a.push_back(adviser);
        }

        // close the file
        file.close();
    }

    // if the file cannot be opened, alert the user
    else std::cout << "Unable to open " << filename << std::endl;

    // return the advisers that have been loaded
    return a;
}

std::vector<Asset> Game::loadAssets(const std::string &filename)
{
    // initializes necessary variables
    std::vector<Asset> a;
    std::string line;
    std::ifstream file(filename);

    // if the file is open, read the data from it
    if (file.is_open())
    {
        while (getline(file, line))
        {
            // read the entire line into a stringstrem for tokenizing
            std::istringstream stream(line);

            // initialize necessary variables
            std::string token;
            std::string name;
            std::vector<int> prices;

            // spilt the stream by the ',' character
            while (getline(stream, token, ',')) {
                if (name.empty())
                {
                    // if the name has not been defined, set the first token to be the name
                    name = token;
                }
                else {
                    // convert the string token representing a price into an integer
                    std::stringstream convert(token);
                    int price = 0;
                    convert >> price;

                    // add the price integer to the prices vector
                    prices.push_back(price);
                }
            }
            // construct a new asset based on the loaded price data and name
            Asset asset(name, prices);

            // push that asset to the assets vector
            a.push_back(asset);
        }

        // close the file
        file.close();
    }

    // if the file cannot be loaded, alert the user
    else std::cout << "Unable to open " << filename << std::endl;

    // return the list of loaded assets
    return a;
}

std::vector<Brokerage> Game::getBrokerages()
{
    return brokerages;
}

std::vector<Adviser> Game::getAdvisers()
{
    return advisers;
}

std::vector<Asset> Game::getAssets()
{
    return assets;
}

void Game::printBrokerages()
{
    // print the header for the following data
    std::cout << "Brokerage - Cost Per Trade" << std::endl << std::endl;

    // iterate over the brokerages vector and print out each brokerage name and fee
    for (int i = 0; i < brokerages.size(); ++i)
    {
        // print out each brokerage name and fee
        std::cout << brokerages[i].getName() << " - $" << brokerages[i].getFee() << std::endl;
    }
    std::cout << std::endl;
}

void Game::printAdvisers()
{
    // print out the header for the following data
    std::cout << "Adviser - Cost Per Meeting" << std::endl;
    std::cout << std::endl;

    // iterate over the advisers and print out their names and corresponding fees
    for (int i = 0; i < advisers.size(); ++i)
    {
        // print out the adviser's name with their corresponding fee
        std::cout << advisers[i].getName() << " - $" << advisers[i].getFee() << std::endl;
    }
    std::cout << std::endl;
}

void Game::printAssets()
{
    // print out header to explain data to user
    std::cout << "Asset Ticker - Current Value" << std::endl;
    std::cout << std::endl;

    // iterate over the assets and print each one out
    for(int i = 0; i < assets.size(); ++i)
    {
        // print out the asset with it's corresponding price at the current week
        std::cout << assets[i].getTicker() << " - $ " << assets[i].getPriceAtWeek(week) << std::endl;
    }
    std::cout << std::endl;
}

void Game::printPortfolio()
{
    // initialize variables
    int count = 0;
    std::vector<Asset> portfolio = getAssets();

    // print out the header for the table
    std::cout << "Asset - Quantity" << std::endl;
    std::cout << std::endl;

    // iterate over the assets that the user owns
    for(int i = 0; i < portfolio.size(); ++i)
    {
        // print out the asset with its corresponding quantity
        std::cout << "Asset " << i+1 << ": " << portfolio[i].getTicker() << " - " << portfolio[i].getQuantity() << std::endl;

        // increase the count of owned assets
        count++;
    }
    // if the user owns no assets
    if (!count)
    {
        // alert the user that they own no assets
        std::cout << "You have no owned assets." << std::endl;
    }
    std::cout << std::endl;
}

bool Game::containsAsset(std::string assetName)
{
    // iterates over the assets object
    for (int i = 0; i < assets.size(); i++)
    {
        // if the assetName matches one of the assets, return true
        if (assets[i].getTicker() == assetName)
        {
            return true;
        }
    }
    // if none of the assets match, return false
    return false;
}

int Game::getBuyingPower(std::string assetName)
{
    // iterates over the assets object
    for (int i = 0; i < assets.size(); i++)
    {
        // if the assetName matches one of the assets, return the number of shares that can be purchased
        if (assets[i].getTicker() == assetName)
        {
            int buyingPower = capital / assets[i].getPriceAtWeek(week);
            return buyingPower;
        }
    }
    // if none of the assets match, return -1
    return -1;
}

int Game::getNumShares(std::string assetName)
{
    // iterates over the assets object
    for (int i = 0; i < assets.size(); i++)
    {
        // if the assetName matches one of the assets, return the number of shares that can be purchased
        if (assets[i].getTicker() == assetName)
        {
            // return the number of shares that the user owns
            int numShares = assets[i].getQuantity();
            return numShares;
        }
    }
    // if none of the assets match, return 0
    return 0;
}

void Game::printMoneyHistory()
{
    // prints out the head for the table
    std::cout << "Week Number - Account Value" << std::endl;
    std::cout << std::endl;

    // iterates over moneyHistroy and prints each element
    for (int i = 0; i < moneyHistory.size(); i++)
    {
        // prints out each week and the corresponding portfolio value at that time
        std::cout << "Week " << i << " - $" << moneyHistory[i] << std::endl;
    }
    std::cout << std::endl;
}

std::vector<int> Game::getMoneyHistory()
{
    return moneyHistory;
}