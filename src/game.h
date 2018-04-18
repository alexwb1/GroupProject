#pragma once

#include "game.h"
#include <fstream>
#include <sstream>
#include <iostream>
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
    unsigned int week = 1; // unsigned integer value that represents the current week
    const int FINAL_WEEK = 27; // constant int value that represents the last week of available data

public:

    Game(int initialCapital, std::string name); // the Game constructor takes in an initial capital value and a player name

    std::vector<Brokerage> loadBrokerages(const std::string &filename);

    std::vector<Adviser> loadAdvisers(const std::string &filename);

    std::vector<Asset> loadAssets(const std::string &filename);

    bool nextWeek(); // increments the week by 1

    std::string getName(); // returns a string value representing the user's name

    int getCapital(); // returns an int value representing the capital that a user does not have invested

    void setCapital(int capital); // sets the capital member variable to a specified value

    Brokerage* getBrokerage(); // returns a pointer to the user-chosen brokerage

    bool setBrokerage(const std::string &name); // sets the user-chosen brokerage

    Adviser* getAdviser(); // returns a pointer to the user-chosen adviser

    bool setAdviser(const std::string &name); // sets the user-chosen adviser

    bool buyAsset(const std::string &name, int quantity); // adds an asset to the user's portfolio and substracts the price from the user's capital; returns true if this action can be taken, false if not

    bool sellAsset(const std::string &name, int quantity); // removes an asset from the user's portfolio and adds the price to the user's capital; returns true if this action can be taken, false if not
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

std::vector<Brokerage> Game::loadBrokerages(const std::string &filename)
{
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

std::vector<Adviser> Game::loadAdvisers(const std::string &filename)
{
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

std::vector<Asset> Game::loadAssets(const std::string &filename)
{
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

bool Game::nextWeek()
{
    if (week < FINAL_WEEK) {
        week++;
        return true;
    }
    else {
        return false;
    }
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
    for (auto &b : brokerages)
    {
        if (b.getName() == name)
        {
            brokerage = &b;
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
    for (auto &a : advisers)
    {
        if (a.getName() == name)
        {
            adviser = &a;
            return true;
        }
    }
    return false;
}

bool Game::buyAsset(const std::string &name, int quantity)
{
    for (auto &a : assets)
    {
        if (a.getTicker() == name)
        {
            if (a.getPriceAtWeek(week) * quantity > capital)
            {
                return false;
            }
            else {
                a.setQuantity(a.getQuantity() + quantity);
                return true;
            }
        }
    }
}

bool Game::sellAsset(const std::string &name, int quantity)
{
    for (auto &asset : assets) {
        if (asset.getTicker() == name)
        {
            if (quantity > asset.getQuantity())
            {
                return false;
            }
            else {
                asset.setQuantity(asset.getQuantity() - quantity);
                return true;
            }
        }
    }
}