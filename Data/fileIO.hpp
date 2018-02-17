#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>
#include <Security.h>

class fileReader{
   private:
	std::vector<string> tickers;
	//std::vector<Security> securities;//creates a 3d vector. or a vector of 2d vectors, where each security object is the historical data for a different security

   public:

	void openFile(){ //we want the 1st, 2nd, 3rd, 4th, and 5th colmns out of 7 {Date,Open,High,Low,Close}
	ifstream input;
	input.open("/home/alexander/Dropbox/projects/groupProject/Data/SPX.csv");
	struct marketData{
		string date;
		std::vector<double> prices; // {0,1,2,3,4} := {Date,Open,High,Low,Close}
	}

if (!inFile) {                                  //It might be better to use a try/catch block
   std:: cerr << "Unable to open file datafile.txt";
    exit(1);
}

while (inFile >> str) {


  // document = document + str;
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

	std::vector<marketData> stuff;

	string pricePattern="\\d{1,}+[.]\\d{1,10}";
	string datePattern="\\d{4}+[-]\\d{2}+[-]\\d{2}";
	
	regex datetime(datePattern);	//captures datetime format
	regex price(pricePattern);		//captures price data format
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
		 cerr << "There was an error reading the data." << endl;
	}
}

void plotdata(string ticker){ //this plots a green circle right now so change that!
	string windowLabel = ticker + " Historical Price Plot";
	sf::RenderWindow window(sf::VideoMode(1200, 1200), windowLabel);
    sf::CircleShape shape(600.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();		//These function calls make the window appear
        window.draw(shape);
        window.display();
    }
}


};//end class declaration

