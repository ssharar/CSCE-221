//Shaeeta Sharar
//CSCE 121 Section 508
//Due: October 21st, 2014
//hw6pr1.cpp

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
		int function_return= 0;
		
		//Inputs
		//Asks user to enter date and stores date
		cout << "Please enter today's date (YYYY, MM, DD): " << endl;
		cin >> date_input;
		
		//Calculations and Output
		
		//Calculates day of the week function
		function_return = date_input.day_of_week();
		
			//Depending on the return values of the functions a switch statement checks the value and prints the day
			switch(function_return)
			{
				case 0:
					cout << "The day of the week is Saturday." << endl;
					break;
				case 1:
					cout << "The day of the week is Sunday." << endl;
					break;
				case 2:
					cout << "The day of the week is Monday." << endl;
					break;
				case 3:
					cout << "The day of the week is Tuesday." << endl;
					break;
				case 4:
					cout << "The day of the week is Wednesday." << endl;
					break;
				case 5:
					cout << "The day of the week is Thursday." << endl;
					break;
				case 6:
					cout << "The day of the week is Friday." << endl;
					break;
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