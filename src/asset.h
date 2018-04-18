#pragma once

#include <string>
#include <vector>

class Asset
{
	std::vector<int> prices; // vector to hold each day's price

    std::vector<int> purchases; // a vector containing the purchase history of this asset

	std::string ticker; // string to hold the symbol of the stock

	unsigned int quantity = 0; // int value representing how many shares are owned

	public:

		Asset(std::string ticker, std::vector<int> prices);

		int getPriceAtWeek(unsigned int week);

        std::string getTicker();

		unsigned int getQuantity();

		int buy(unsigned int quantity, unsigned int purchaseWeek);

		int sell(unsigned int quantity, unsigned int purchaseWeek);

		std::vector<int> getPurchases();

};

// Definition of Asset methods

Asset::Asset(std::string ticker, std::vector<int> prices) {
    this->ticker = ticker;
    this->prices = prices;
    for (int i = 0; i < prices.size(); i++) {
        purchases.push_back(0);
    }
}

int Asset::getPriceAtWeek(unsigned int week) {
    return prices[week];
}

std::string Asset::getTicker() {
    return ticker;
}

unsigned int Asset::getQuantity() {
    return quantity;
}

int Asset::buy(unsigned int quantity, unsigned int purchaseWeek) {
    this->quantity = this->quantity + quantity;
    purchases[purchaseWeek] = purchases[purchaseWeek] + quantity;
    return quantity * prices[purchaseWeek];
}

int Asset::sell(unsigned int quantity, unsigned int purchaseWeek) {
    this->quantity = this->quantity - quantity;
    purchases[purchaseWeek] = purchases[purchaseWeek] - quantity;
    return quantity * prices[purchaseWeek];
}

std::vector<int> Asset::getPurchases() {
    return purchases;
}
