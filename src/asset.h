#pragma once
#include <string>
#include <vector>

/*
 The asset class is used to hold all data relating to the assets available in the game. All pricing that used for the
 assets is based on real pricing data. The asset class keeps track of when assets were purchased and sold as well as the
 ticker and prices of the asset over time. The asset class also has methods that allow for shares to be easily bought
 and sold.
*/

class Asset
{
	std::vector<int> prices; // vector to hold each day's price
    std::vector<int> purchases; // a vector containing the purchase history of this asset
	std::string ticker; // string to hold the symbol of the stock

	unsigned int quantity = 0; // int value representing how many shares are owned

	public:

		Asset(std::string ticker, std::vector<int> prices); // constructor for the Asset class

		int getPriceAtWeek(unsigned int week); // gets the price of the asset at a specific week

		std::string getTicker(); // gets the ticker of the current asset

		unsigned int getQuantity(); // gets the quantity of shares owned

		int buy(unsigned int quantity, unsigned int purchaseWeek); // buys a given amount of the asset at a given week

		int sell(unsigned int quantity, unsigned int purchaseWeek); // sells a given amount of the asset at the given week

		std::vector<int> getPurchases(); // returns the purchase history vector

};

// Definition of Asset methods

Asset::Asset(std::string ticker, std::vector<int> prices)
{
    // initializes variables
    this->ticker = ticker;
    this->prices = prices;

    // initializes the purchases and sells made per week
    for (int i = 0; i < prices.size(); i++) {
        purchases.push_back(0);
    }
}

int Asset::getPriceAtWeek(unsigned int week)
{
    return prices[week];
}

std::string Asset::getTicker()
{
    return ticker;
}

unsigned int Asset::getQuantity()
{
    return quantity;
}

int Asset::buy(unsigned int quantity, unsigned int purchaseWeek)
{
    // add the quantity bought to the current quantity
    this->quantity = this->quantity + quantity;

    // update the purchase history vector
    purchases[purchaseWeek] = purchases[purchaseWeek] + quantity;

    // return the amount spent on the asset
    return quantity * prices[purchaseWeek];
}

int Asset::sell(unsigned int quantity, unsigned int purchaseWeek)
{
    // subtract the quantity sold from the current quantity
    this->quantity = this->quantity - quantity;

    // update the purchase history vector
    purchases[purchaseWeek] = purchases[purchaseWeek] - quantity;

    // return the amount received for the sale
    return quantity * prices[purchaseWeek];
}

std::vector<int> Asset::getPurchases()
{
    return purchases;
}