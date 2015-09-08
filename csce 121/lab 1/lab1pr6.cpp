//Shaeeta Sharar
//CSCE 121 Section 508
//Due: September 25, 2014
//lab1pr6.cpp

#include "std_lib_facilities_4.h"

int main()
{
	//Variables initialized
	double input = 0;
	
	double large = 0;
	double small = 0;
	
	//Inputs
	//Asks user to input a number
	//Uses this number to set the initial largest and smallest number (as the first value is both the largest and smallest so far
	cout << "Please enter a number. Press '|' to terminate." << endl;
	cin >> input;

	large = input;
	small = input;
	
	//Outputs value as largest (because it is)
	cout << "Largest so far " << input << endl;
	
	//Asks user for an input
	cout << "Please enter a number. Press '|' to terminate." << endl;

	//Comparison
	//Takes in inputs from the user
	//Terminates when "|" or a value other than a double is entred
	while (cin >> input)
	{
		//If the input is larger than the largest value prints out the input as new largest value and sets large value to this number
		if (input > large)
		{
			cout << "Largest so far " << input << endl;
			large = input;
		}

		//If input is less than largest value goes in through another comparison
		else if (input < large)
		{
			//If input is greater than the smallest and smaller than the largest it is a middle value
			//Outputs middle value while notifying user
			if (input > small)
			{
				cout << "Not largest or smallest so far. " << input << " is a middle value." << endl;
			}
			//If input is smaller than smallest prints out the input as new smallest value and sets small value to this number
			else if (input < small)
			{
				cout << "Smallest so far " << input << endl;
				small = input;
			}
			//If input is equal to smallest then prints out the input as smallest value and sets small value to this number
			else
			{
				cout << "Smallest so far " << input << endl;
				small = input;
			}
		}

		//If input is equal to largest then prints out the input as largest value and sets large value to this number
		else
		{
			cout << "Largest so far " << input << endl;
			large = input;
		}
	}	
	
	return 0;
}