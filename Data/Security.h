#include <iostream>
#include <vector>



class Security{

     private:
	std::vector<std::vector<unsigned> > data; /*Dimensions for this 2d vector: ticker, date, open, high, low, close*/


     public:

	Security(std::vector<std::vector<unisgned> > data){
		this->data=data;
	}



};//end class declaration
