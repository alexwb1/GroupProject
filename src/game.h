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
    void printBrokerages(std::vector <Brokerage> v);

    Adviser* getAdviser(); // returns a pointer to the user-chosen adviser
    std::vector<Adviser> getAdvisers(); // returns a list of the available advisers
    bool setAdviser(const std::string &name); // sets the user-chosen adviser
    void printAdvisers(std::vector <Adviser> v);

    std::vector<Asset> getAssets(); // returns a list of the available assets
    bool buyAsset(const std::string &name, unsigned int quantity); // adds an asset to the user's portfolio and substracts the price from the user's capital; returns true if this action can be taken, false if not
    bool sellAsset(const std::string &name, unsigned int quantity); // removes an asset from the user's portfolio and adds the price to the user's capital; returns true if this action can be taken, false if not
    std::vector<Asset> getPortfolio(); // returns a vector of assets each of which the user owns
    void printAssets(std::vector <Asset> v);

    std::string getAdvice(Asset, int); // returns a string representing advice from the adviser

private:

    std::vector<Brokerage> loadBrokerages(const std::string &filename);
    std::vector<Adviser> loadAdvisers(const std::string &filename);
    std::vector<Asset> loadAssets(const std::string &filename);

};

// Definition of Game methods

Game::Game(int initialCapital, std::string name)
{
    this->capital = initialCapital;
    this->name = std::move(name);
    this->brokerages = loadBrokerages("../data/brokerages.txt");
    this->advisers = loadAdvisers("../data/advisers.txt");
    this->assets = loadAssets("../data/assets.txt");
}

bool Game::nextWeek()
{
    if (week < FINAL_WEEK) {
        week++;
        capital -= adviser->getFee(); //Applies weekly adviser fee
        return true;
    }
    else {
        return false;
    }
}

int Game::getWeek() {
    return week;
}

int Game::getFinalWeek() {
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
    for (int i = 0; i < brokerages.size(); i++)
    {
        if (brokerages[i].getName() == name)
        {
            brokerage = &brokerages[i];
            return true;
        }
    }
    return false;
}

Adviser *Game::getAdviser()
{
    return adviser;
}

bool Game::setAdviser(const std::string &name)
{
    for (int i = 0; i < advisers.size(); i++)
    {
        if (advisers[i].getName() == name)
        {
            adviser = &advisers[i];
            return true;
        }
    }
    return false;
}

bool Game::buyAsset(const std::string &name, unsigned int quantity) {
    std::string userIn;
    std::cout << "How many shares of " << name << " would you like to purchase: ";
    //std::getline(std::cin, userIn);
    std::cin >> userIn;
    quantity = std::stoi(userIn);

    for (int i = 0; i < assets.size(); i++)
    {
        if (assets[i].getTicker() == name)
        {
            if (assets[i].getPriceAtWeek(week) * quantity > capital)
            {
                std::cout << "You do not have enough money to buy those shares.\n" << std::endl;
                return false;
            }
            else {
                capital -= assets[i].buy(quantity, week);
                return true;
            }
        }
    }
    return true;

}
bool Game::sellAsset(const std::string &name, unsigned int quantity) {
    for (auto &a : assets) {
        if (a.getTicker() == name)
        {
            if (quantity > a.getQuantity())
            {
                std::cout << a.getTicker()  << " has " << a.getQuantity() << " shares"<< std::endl;
                return false;
            }
            else {
                capital += a.sell(quantity, week);
                return true;
            }
        }
    }
}

std::string Game::getAdvice(Asset asset, int weekNum) {
    return adviser->getAdvice(asset, weekNum);
}
std::vector<Asset> Game::getPortfolio() {
    std::vector<Asset> portfolio;
    for (auto &a : assets)
    {
        if (a.getQuantity() != 0)
        {
            portfolio.push_back(a);
        }
    }
    return portfolio;
}

//Read Game Contents from txt files
std::vector<Brokerage> Game::loadBrokerages(const std::string &filename) {
    std::vector<Brokerage> b;
    std::string line;
    std::ifstream file(filename);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            line.pop_back();
            Brokerage brokerage(line);
            b.push_back(brokerage);
        }
        file.close();
    }

    else std::cout << "Unable to open " << filename << std::endl;

    return b;
}
std::vector<Adviser> Game::loadAdvisers(const std::string &filename) {
    std::vector<Adviser> a;
    std::string line;
    std::ifstream file(filename);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            line.pop_back();
            Adviser adviser(line);
            a.push_back(adviser);
        }
        file.close();
    }

    else std::cout << "Unable to open " << filename << std::endl;

    return a;
}
std::vector<Asset> Game::loadAssets(const std::string &filename) {
    std::vector<Asset> a;
    std::string line;
    std::ifstream file(filename);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            std::istringstream stream(line);
            std::string token;
            std::string name;
            std::vector<int> prices;

            while (getline(stream, token, ',')) {
                if (name.empty())
                {
                    name = token;
                }
                else {
                    std::stringstream convert(token);
                    int price = 0;
                    convert >> price;
                    prices.push_back(price);
                }
            }
            Asset asset(name, prices);
            a.push_back(asset);
        }
        file.close();
    }

    else std::cout << "Unable to open " << filename << std::endl;

    return a;
}


//Getters for game components
std::vector<Brokerage> Game::getBrokerages() {
    return brokerages;
}
std::vector<Adviser> Game::getAdvisers() {
    return advisers;
}
std::vector<Asset> Game::getAssets() {
    return assets;
}

//Print Functions
void Game::printBrokerages(std::vector <Brokerage> v){
    std::cout << std::endl;
    for (int i =0; i < v.size(); ++i){
        std::cout << "Brokerage " << i+1 << ": " << v[i].getName() << std::endl;
    }
    std::cout << std::endl;
}
void Game::printAdvisers(std::vector <Adviser> v){
    std::cout << std::endl;
    for (int i =0; i < v.size(); ++i){
        std::cout << "Adviser " << i+1 << ": " << v[i].getName() << std::endl;
    }
    std::cout << std::endl;
}
void Game::printAssets(std::vector <Asset> v){
    std::cout << std::endl;
    for(int i = 0; i < v.size(); ++i){
        std::cout << "Asset " << i+1 << ": " << v[i].getTicker() << std::endl;
    }
}
