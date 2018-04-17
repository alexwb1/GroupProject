#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include "Security.h"

class fileReader{
   private:
	std::vector<string> tickers;
	std::vector<Security> securities;//creates a 3d vector. or a vector of 2d vectors, where each security object is the historical data for a different security

   public:

	void openFile(){
	ifstream input;
	input.open("/home/alexander/Dropbox/projects/groupProject/Data/SPX.csv");

if (!inFile) {                                  //It might be better to use a try/catch block
   std:: cerr << "Unable to open file datafile.txt";
    exit(1);
}

while (inFile >> str) {
  document = document + str;
	}

	ifstream.close(); // closes the input file stream

	}

	}//end openFile()

	void writeFile(){// I am not sure why you would ever need to write a file but okay
		  ofstream myfile;
		  myfile.open("output.biatch");
		  myfile << "Writing this to a biatch file.\n";
		  myfile.close();
	}// end writeFile()

void parser(string input){
	
	regex datetime("\\d"); //captures a digit. the function can be named anything
	regex price("\\d");
	std::cin>>userInput;
 	if(!std::cin)
 	{
 		break;
 	} 
 	if(userInput=="q")
 	{
 		break; //stops if the user enters "q"
 	}
	if(regex_match(input, datetime))
	{
		cout << datetime << endl;
	} 
	else
	{	
		 cerr << "There was an error reading the data. << endl;
	}
}



};//end class declaration

