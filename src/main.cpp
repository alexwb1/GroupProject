#include <iostream>
#include <vector>
#include "asset.h"

int main(){



return 0;
}







InstrumentData::InstrumentData(string name)
{
	inFile.open(name, ios::in);
	
	if(!inFile)
	{
		cerr << "\nThe file could not be opened.\n";
	}
	
	
	
	while(getline(inFile,line))
	{
		
		stringstream check1(line);
		data.clear();
		
		while(getline(check1, inter, ','))
		{
			tokens.push_back(inter);
			cout << inter << endl;
		}
	}
	
}