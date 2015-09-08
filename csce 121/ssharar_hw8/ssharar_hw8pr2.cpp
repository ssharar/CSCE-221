//Shaeeta Sharar
//CSCE 121 Section 508
//Due: December 11th, 2014
//ssharar_hw8pr2.cpp

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
		cout << "Enter SSN: ";
		
		//Pattern
		//this is the valid format for ssns
		regex valid_pat{R"(\d{1}-?\d{2}-?\d{4})"};
		//these are all the exceptions the format should not follow
		regex pat_1{R"(000-?\d{2}-?\d{4})"};
		regex pat_2{R"(\d{3}-?00-?\d{4})"};
		regex pat_3{R"(\d{3}-?\d{2}-?0000)"};
		regex pat_4{R"(9\d{2}-?\d{2}-?\d{4})"};
		regex pat_5{R"(666-?\d{2}-?\d{4})"};
		
		//Repeats
		//Inputs string 
		//Checks the regex pattern to see if it fits the invalid patterns and lets the user know
		//Also checks the regex pattern to see if it fits the valid patterns and lets the user know
		while (cin)
		{
			smatch match;
			
			string ssn;
			getline(cin,ssn);
			
			if (regex_search(ssn, match, pat_1) || regex_search(ssn, match, pat_2) || regex_search(ssn, match, pat_3) || regex_search(ssn, match, pat_4) || regex_search(ssn, match, pat_5))
			{
				cout << "This is not a valid input format" << endl;
			}
			else if (ssn == "078-05-1120" || ssn == "123-45-6789" || ssn == "111-11-1111" || ssn == "222-22-2222" || ssn == "333-33-3333" || ssn == "444-44-4444" || ssn == "555-55-5555" || ssn == "777-77-7777" || ssn == "888-88-8888")
			{
				cout << "This is not a valid input format" << endl;
			}
			else if (ssn == "078051120" || ssn == "123456789" || ssn == "111111111" || ssn == "222222222" || ssn == "333333333" || ssn == "444444444" || ssn == "555555555" || ssn == "777777777" || ssn == "888888888")
			{
				cout << "This is not a valid input format" << endl;
			}
			else if (ssn == "07805-1120" || ssn == "12345-6789" || ssn == "11111-1111" || ssn == "22222-2222" || ssn == "33333-3333" || ssn == "44444-4444" || ssn == "55555-5555" || ssn == "77777-7777" || ssn == "88888-8888")
			{
				cout << "This is not a valid input format" << endl;
			}
			else if (ssn == "078-051120" || ssn == "123-456789" || ssn == "111-111111" || ssn == "222-222222" || ssn == "333-333333" || ssn == "444-444444" || ssn == "555-555555" || ssn == "777-777777" || ssn == "888-888888")
			{
				cout << "This is not a valid input format" << endl;
			}
			else if (regex_search(ssn, match, valid_pat))
			{
				cout << "This is valid." << endl;
			}
			
			cout << "Enter SSN: ";
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