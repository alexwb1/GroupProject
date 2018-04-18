#pragma once

#include <string>
#include <vector>

class Asset
{
	std::vector<int> prices; // vector to hold each day's price

	std::string ticker; // string to hold the symbol of the stock

	int quantity = 0; // int value representing how many shares are owned

	public:

		Asset(std::string ticker, std::vector<int> prices);

		int getPriceAtWeek(int week);

        std::string getTicker();

		int getQuantity();

		void setQuantity(int quantity);
};

// Definition of Asset methods

Asset::Asset(std::string ticker, std::vector<int> prices) {
    this->ticker = ticker;
    this->prices = prices;
}

int Asset::getPriceAtWeek(int week) {
    return prices[week - 1];
}

std::string Asset::getTicker() {
    return ticker;
}

int Asset::getQuantity() {
    return quantity;
}

void Asset::setQuantity(int quantity) {
    this->quantity = quantity;
}
