//Shaeeta Sharar
//CSCE 121 Section 508
//Due: October 14th, 2014
//hw5pr3.cpp

#include "std_lib_facilities_4.h"
#include "Chrono.h"


int main()
{
	//Error Check
	//Runs program until it's finished or error is found
	//Goes through catch to find source of error
	//If error is found tells user of error before quitting
	try {
		//Declaring variables
		Chrono::Date date_input;
		
		//Inputs
		//Asks user to enter date and stores date
		cout << "Please enter today's date (YYYY, MM, DD) or (YY, MM, DD): " << endl;
		cin >> date_input;
		
		//Calculations and Output
		//Calculates increment then outputs
		++date_input;
		cout << "Tomorrow's date is: " << date_input << "." << endl;
		
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