//Shaeeta Sharar
//CSCE 121 Section 508
//Due: September 21, 2014
//hw2pr3.cpp

#include "std_lib_facilities_4.h"
#include <iomanip>

int main()
{
	//Variables initialized
	//These are used to input the user values and do computations on the input value
	double income = 0;
	double ten_percent = 0;
	double eighty_percent = 0;
	
	//Repeats Code
	//Breaks when a value less than 0 is entered
	//Otherwise runs the main code of printing set values based on a number input
	while (true)
	{
		//Prompts user for value of income and stores input value
		cout << "What is your income in dollars? Please omit the dollar sign when typing. Type 000 when finished." << endl;
		cin >> income;

		//If the input value is not 0 or negative the program computes 10% and 80% of the income value and prints said values in a specified format
		if (income > 0)
		{
			ten_percent = income * .1;
			eighty_percent = income * .8;
			cout << "You should give away $" << setprecision(2) << fixed << ten_percent;
			cout << ", save $" << setprecision(2) << fixed << ten_percent; 
			cout << ", and live on $" << setprecision(2) << fixed << eighty_percent << "." << endl << endl;
		}
		else
		{
			break;
		}
	}

	return 0;
}