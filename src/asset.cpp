#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "asset.h"

Asset::Asset(string ticker, vector<int> prices) {
	this->ticker = ticker;
	this->prices = prices;
}

string Asset::getTicker() {
	return ticker;
}

int Asset::getPriceAtWeek(int week) {
	return prices[week - 1];
}
