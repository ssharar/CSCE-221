//Shaeeta Sharar
//CSCE 121 Section 508
//Due: October 21st, 2014
//hw6pr4.cpp

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
		Chrono::Date d1;
		Chrono::Date d2;
		Chrono::Date d3;
		
		//Inputs
		//Asks user to enter date and stores date
		//Runs in loop until user enters X
		cout << "Please enter today's date (YYYY, MM, DD) or (YY, MM, DD) to exit please enter X: " << endl;
		while(cin >> d1)
		{
			//Calculations and Output
			//Calculates increment then outputs
			d2 = d1;			//d2==old value of d1
			d3 = d1++;			//d3 == old value of d1, d1 == new value of d1
			
			//cout << "d1: " << d1 << "d2: " << d2 << "d3: " << d3 << endl;
			//Checking for errors
			if (d2 != d3)
			{
				cerr << "error in postfix ++, d2 does not equal d3";
			}
			if (d2 == d1)
			{
				cerr << "error in postfix ++, d1 does not equal d3";
			}
			else if (d1 != ++d2)
			{
				cerr << "error in postfix ++, d1 does not equal d3";
			}
			else
			{			
				cout << "Tomorrow's date is: " << d1 << "." << endl;
			}
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