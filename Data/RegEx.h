//Basic review of using regular expressions in C++
#include <iostream>
#include <regex>

using namespace std;

int main() {
	string input = "There are 7 apples in my basket. Or, are there only 5?"
	regex blahblah("\\d"); //captures a digit. the function can be named anything
	cin>>input;
 	if(!cin) break;
 	if(input=="q") break; //stops if the user enters "q"
	if(regex_match(input, blahblah)) cout << blahblah << endl;
	else cerr << "No blahblah's were found!" << endl;
}

/*
Great reference here: http://www.cplusplus.com/reference/regex/
	List of patterns: http://www.cplusplus.com/reference/regex/ECMAScript/
	It also apparently supports grep syntax but I wouldn't mess with that since ECMA is so widely used


*/

