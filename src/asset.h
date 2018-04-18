#ifndef GROUPPROJECT_ASSET_H
#define GROUPPROJECT_ASSET_H


#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/*

This class will hold an object for each financial instrument. The data will be
stored in a vector. Each index of the vector represents one day of closing price.

The constructor of the class will take in the symbol or name of the instrument as
it is in the "stock_price_data.txt" data file and read that data into the "data" vector.

*/

class Asset
{
	vector<int> prices; // vector to hold each day's price

	string ticker; // string to hold the symbol of the stock

	int quantity = 0;

	public:

		Asset(string ticker, vector<int> data);

		string getTicker();

		int getPriceAtWeek(int week);
};




#endif