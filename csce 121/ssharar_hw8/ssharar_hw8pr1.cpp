//Shaeeta Sharar
//CSCE 121 Section 508
//Due: December 11th, 2014
//ssharar_hw8pr1.cpp

//#include "std_lib_facilities_4.h"
#include <regex>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	//Error Check
	//Runs program until it's finished or error is found
	//Goes through catch to find source of error
	//If error is found tells user of error before quitting
	try {
		//Inputs
		//Asks user for input
		cout << "Enter ISBN: ";
		
		//Pattern
		//This is the pattern inputs must fit
		regex pat{R"((978|979)(\s|-)?\d{1}(\s|-)?\d{1}(\s|-)?\d{1}(\s|-)?\d{1}(\s|-)?\d{1}(\s|-)?\d{1}(\s|-)?\d{1}(\s|-)?\d{1}(\s|-)?\d{1}(\s|-)?(\d{1}|\w{1})?)"};
		
		//Repeats
		//Inputs string 
		//Checks the regex pattern to see if it fits the pattern
		while (cin)
		{
			smatch match;
			
			string isbn_number;
			getline(cin,isbn_number);
			
			if (regex_search(isbn_number, match, pat))
			{
				cout << "This is a valid input format" << endl;
			}
			else
			{
				cout << "This is not a valid input format" << endl;
			}
			
			cout << "Enter ISBN: ";
		}
				
	}
	
	
	
	catch (exception& e)
	{
		cerr << "error: " << e.what() << endl;
		return 1;
	}
	catch(...)
	{
		cerr << "Oops: unknown exception!" << endl;
		return 2;
	}
	
	return 0;
}