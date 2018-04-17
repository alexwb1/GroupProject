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

This  class will  hold an object for  each finiacal  instrument. The data will be
stored in a vector. Each index of the  vector represents one day of closing price.

The constructor of the  class will take in the symbol or name of the instrument as
it is in the "stock_data.txt" data file and read that data into the "data" vector.

*/

class Asset
{
	vector<string> data; // vector to hold each days' data. 
	string assetName;    // string to hold the symbol of the stock
	string fileName;  // string to hold the name of the file that the data is being access from
	ifstream inFile;  // file object
	string inter;     // string used to tokenize the file lines
	
	
	public:
		Asset(string);
		string getAssetName();
		double getDayData(int);
		
};




#endif