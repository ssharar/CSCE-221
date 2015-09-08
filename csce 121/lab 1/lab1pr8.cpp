//Shaeeta Sharar
//CSCE 121 Section 508
//Due: September 25, 2014
//lab1pr8.cpp

#include "std_lib_facilities_4.h"

int main()
{
	//Variables initialized
	double input = 0;
	string unit;
	
	double conversion = 0;
	
	double large = 0;
	double small = 0;
	
	//Inputs
	//Asks user to input a number
	//Uses this number to set the initial largest and smallest number (as the first value is both the largest and smallest so far
	cout << "Please enter a number and unit (cm, m, in, or ft). Press '|' to terminate." << endl;
	cin >> input >> unit;

	if (unit == "m")
	{
		conversion = input;
		large = conversion;
		small = conversion;
	}
	else if (unit == "cm")
	{
		conversion = input / 100;
		large = conversion;
		small = conversion;
	}
	else if (unit == "in")
	{
		conversion = input / (100*2.54);
		large = conversion;
		small = conversion;
	}
	else if (unit == "ft")
	{
		conversion = input / (100*2.54) / 12;
		large = conversion;
		small = conversion;
	}
	else
	{
		cout << "Incorrect unit please enter valid unit." << endl;
		exit(0);
	}

	//Outputs value as largest (because it is)
	cout << "Largest so far " << input << " " << unit << endl;
	
	//Asks user for an input
	cout << "Please enter a number and unit (cm, m, in, or ft). Press '|' to terminate." << endl;

	//Comparison
	//Takes in inputs from the user
	//Terminates when "|" or a value other than a double is entred
	while (cin >> input >> unit)
	{
		if (unit == "m")
		{
			conversion = input;

			//If the input is larger than the largest value prints out the input as new largest value and sets large value to this number
			if (conversion > large)
			{
				cout << "Largest so far " << input << " " << unit << endl;
				large = conversion;
			}
			//If input is less than largest value goes in through another comparison
			else if (conversion < large)
			{
				//If input is greater than the smallest and smaller than the largest it is a middle value
				//Outputs middle value while notifying user
				if (conversion > small)
				{
					cout << "Not largest or smallest so far. " << input << " " << unit << " is a middle value." << endl;
				}
				//If input is smaller than smallest prints out the input as new smallest value and sets small value to this number
				else if (conversion < small)
				{
					cout << "Smallest so far " << input << " " << unit << endl;
					small = conversion;
				}
				//If input is equal to smallest then prints out the input as smallest value and sets small value to this number
				else
				{
					cout << "Smallest so far " << input << " " << unit << endl;
					small = conversion;
				}
				//If input is equal to largest then prints out the input as largest value and sets large value to this number
			}
			else
			{
				cout << "Largest so far " << input << " " << unit << endl;
				large = conversion;
			}
		}
		
		else if (unit == "cm")
		{
			
			conversion = input / 100;
			
			//If the input is larger than the largest value prints out the input as new largest value and sets large value to this number
			if (conversion > large)
			{
				cout << "Largest so far " << input << " " << unit << endl;
				large = conversion;
			}
			//If input is less than largest value goes in through another comparison
			else if (conversion < large)
			{
				//If input is greater than the smallest and smaller than the largest it is a middle value
				//Outputs middle value while notifying user
				if (conversion > small)
				{
					cout << "Not largest or smallest so far. " << input << " " << unit << " is a middle value." << endl;
				}
				//If input is smaller than smallest prints out the input as new smallest value and sets small value to this number
				else if (conversion < small)
				{
					cout << "Smallest so far " << input << " " << unit << endl;
					small = conversion;
				}
				//If input is equal to smallest then prints out the input as smallest value and sets small value to this number
				else
				{
					cout << "Smallest so far " << input << " " << unit << endl;
					small = conversion;
				}
				//If input is equal to largest then prints out the input as largest value and sets large value to this number
			}
			else
			{
				cout << "Largest so far " << input << " " << unit << endl;
				large = conversion;
			}
		}
		else if (unit == "in")
		{
			
			conversion = (input / 100) * 2.54;
			
			//If the input is larger than the largest value prints out the input as new largest value and sets large value to this number
			if (conversion > large)
			{
				cout << "Largest so far " << input << " " << unit << endl;
				large = conversion;
			}
			//If input is less than largest value goes in through another comparison
			else if (conversion < large)
			{
				//If input is greater than the smallest and smaller than the largest it is a middle value
				//Outputs middle value while notifying user
				if (conversion > small)
				{
					cout << "Not largest or smallest so far. " << input << " " << unit << " is a middle value." << endl;
				}
				//If input is smaller than smallest prints out the input as new smallest value and sets small value to this number
				else if (conversion < small)
				{
					cout << "Smallest so far " << input << " " << unit << endl;
					small = conversion;
				}
				//If input is equal to smallest then prints out the input as smallest value and sets small value to this number
				else
				{
					cout << "Smallest so far " << input << " " << unit << endl;
					small = conversion;
				}
				//If input is equal to largest then prints out the input as largest value and sets large value to this number
			}
			else
			{
				cout << "Largest so far " << input << " " << unit << endl;
				large = conversion;
			}
		}
		else if (unit == "ft")
		{
			
			conversion = ((input / 100) * 2.54) / 12;
			
			//If the input is larger than the largest value prints out the input as new largest value and sets large value to this number
			if (conversion > large)
			{
				cout << "Largest so far " << input << " " << unit << endl;
				large = conversion;
			}
			//If input is less than largest value goes in through another comparison
			else if (conversion < large)
			{
				//If input is greater than the smallest and smaller than the largest it is a middle value
				//Outputs middle value while notifying user
				if (conversion > small)
				{
					cout << "Not largest or smallest so far. " << input << " " << unit << " is a middle value." << endl;
				}
				//If input is smaller than smallest prints out the input as new smallest value and sets small value to this number
				else if (conversion < small)
				{
					cout << "Smallest so far " << input << " " << unit << endl;
					small = conversion;
				}
				//If input is equal to smallest then prints out the input as smallest value and sets small value to this number
				else
				{
					cout << "Smallest so far " << input << " " << unit << endl;
					small = conversion;
				}
				//If input is equal to largest then prints out the input as largest value and sets large value to this number
			}
			else
			{
				cout << "Largest so far " << input << " " << unit << endl;
				large = conversion;
			}
		}
		else 
		{
			cout << "Incorrect unit please enter valid unit." << endl;
			break;
		}
	}	
	
	return 0;

}