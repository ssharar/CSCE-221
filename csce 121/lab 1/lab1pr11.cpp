//Shaeeta Sharar
//CSCE 121 Section 508
//Due: September 25, 2014
//lab1pr11.cpp

#include "std_lib_facilities_4.h"

int main()
{
	//Variables initialized
	double input = 0;
	string unit;
	Vector<double> inputs;
	
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
		inputs.push_back(conversion);
	}
	else if (unit == "cm")
	{
		conversion = input / 100;
		large = conversion;
		small = conversion;
		inputs.push_back(conversion);
	}
	else if (unit == "in")
	{
		conversion = input / (100*2.54);
		large = conversion;
		small = conversion;
		inputs.push_back(conversion);
	}
	else if (unit == "ft")
	{
		conversion = input / (100*2.54) / 12;
		large = conversion;
		small = conversion;
		inputs.push_back(conversion);
	}
	else
	{
		cout << "Incorrect unit please enter valid unit." << endl;
		exit(0);
	}

	//Asks user for an input
	cout << "Please enter a list of numbers with units (cm, m, in, or ft). Press '|' to terminate." << endl;

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
				large = conversion;
				inputs.push_back(conversion);
			}
			//If input is less than largest value goes in through another comparison
			else if (conversion < large)
			{
				//If input is greater than the smallest and smaller than the largest it is a middle value
				//Outputs middle value while notifying user
				if (conversion > small)
				{
					inputs.push_back(conversion);
				}
				//If input is smaller than smallest prints out the input as new smallest value and sets small value to this number
				else if (conversion < small)
				{
					small = conversion;
					inputs.push_back(conversion);
				}
				//If input is equal to smallest then prints out the input as smallest value and sets small value to this number
				else
				{
					small = conversion;
					inputs.push_back(conversion);
				}
				//If input is equal to largest then prints out the input as largest value and sets large value to this number
			}
			else
			{
				large = conversion;
				inputs.push_back(conversion);
			}
		}
		
		else if (unit == "cm")
		{
			
			conversion = input / 100;
			
			//If the input is larger than the largest value prints out the input as new largest value and sets large value to this number
			if (conversion > large)
			{
				large = conversion;
				inputs.push_back(conversion);
			}
			//If input is less than largest value goes in through another comparison
			else if (conversion < large)
			{
				//If input is greater than the smallest and smaller than the largest it is a middle value
				//Outputs middle value while notifying user
				if (conversion > small)
				{
					inputs.push_back(conversion);
				}
				//If input is smaller than smallest prints out the input as new smallest value and sets small value to this number
				else if (conversion < small)
				{
					small = conversion;
					inputs.push_back(conversion);
				}
				//If input is equal to smallest then prints out the input as smallest value and sets small value to this number
				else
				{
					small = conversion;
					inputs.push_back(conversion);
				}
				//If input is equal to largest then prints out the input as largest value and sets large value to this number
			}
			else
			{
				large = conversion;
				inputs.push_back(conversion);
			}
		}
		else if (unit == "in")
		{
			
			conversion = (input / 100) * 2.54;
			
			//If the input is larger than the largest value prints out the input as new largest value and sets large value to this number
			if (conversion > large)
			{
				large = conversion;
				inputs.push_back(conversion);
			}
			//If input is less than largest value goes in through another comparison
			else if (conversion < large)
			{
				//If input is greater than the smallest and smaller than the largest it is a middle value
				//Outputs middle value while notifying user
				if (conversion > small)
				{
					inputs.push_back(conversion);
				}
				//If input is smaller than smallest prints out the input as new smallest value and sets small value to this number
				else if (conversion < small)
				{
					small = conversion;
					inputs.push_back(conversion);
				}
				//If input is equal to smallest then prints out the input as smallest value and sets small value to this number
				else
				{
					small = conversion;
					inputs.push_back(conversion);
				}
			}
			//If input is equal to largest then prints out the input as largest value and sets large value to this number
			else
			{
				large = conversion;
				inputs.push_back(conversion);
			}
		}
		else if (unit == "ft")
		{
			
			conversion = ((input / 100) * 2.54) / 12;
			
				//If the input is larger than the largest value prints out the input as new largest value and sets large value to this number
			if (conversion > large)
			{
				large = conversion;
				inputs.push_back(conversion);
			}
			//If input is less than largest value goes in through another comparison
			else if (conversion < large)
			{
				//If input is greater than the smallest and smaller than the largest it is a middle value
				//Outputs middle value while notifying user
				if (conversion > small)
				{
					inputs.push_back(conversion);
				}
				//If input is smaller than smallest prints out the input as new smallest value and sets small value to this number
				else if (conversion < small)
				{
					small = conversion;
					inputs.push_back(conversion);
				}
				//If input is equal to smallest then prints out the input as smallest value and sets small value to this number
				else
				{
					small = conversion;
					inputs.push_back(conversion);
				}
			}
			//If input is equal to largest then prints out the input as largest value and sets large value to this number
			else
			{
				large = conversion;
				inputs.push_back(conversion);
			}
		}
		else 
		{
			cout << "Incorrect unit please enter valid unit." << endl;
			break;
		}
	}

	double sum;
	for (int count = 0; count < inputs.size(); count++)	
	{
		sum += inputs[count];
	}
	
	sort (inputs.begin(), inputs.end());
	
	for (int element = 0; element < inputs.size(); element++)	
	{
		cout << "The value of position " << element << " is " << inputs[element] << " meters. ";
	}	
	
	cout << "\n" << "The largest value was " << large << " in meters." << endl;
	cout << "The smallest value was " << small << " in meters." << endl;
	cout << "The number of values entered was " << inputs.size() << "." << endl;
	cout << "The sum of all the values was " << sum << " in meters." << endl;
	
	return 0;

}