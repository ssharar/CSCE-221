//Shaeeta Sharar
//CSCE 121 Section 508
//Due: September 25, 2014
//lab1pr5.cpp

#include "std_lib_facilities_4.h"

int main()
{
	//Variables initialized
	double input_1 =0;
	double input_2 =0;
	
	//Inputs
	//Asks user to input two ints
	cout << "Please enter two integers. Press '|' to terminate." << endl;
	
	//Reads inputs
	//Terminates the program when "|" or a type other than int is entered
	while (cin >> input_1 >> input_2)
	{
		//If the 1st value is larger it prints a statement saying so
		if (input_1 > input_2)
		{
			//Variable initialized
			//Subtracts inputs and uses difference  to initiate if statements below
			double comparison_1 = 0;
			comparison_1 = input_1 - input_2;
			
			//If values are almost equal, the user is notified otherwise it simply prints the smaller and larger values.
			if (comparison_1 <= .01)
			{
			cout << "The values are almost equal.\n The smaller value is: " << input_2 << " The larger value is: " << input_1 << endl;
			}
			else
			{
			cout << "The smaller value is: " << input_2 << " The larger value is: " << input_1 << endl;
			}
		}
		
		//If the 2nd value is larger it prints a statement saying so
		else if (input_2 > input_1)
		{
			//Variable initialized
			//Subtracts inputs and uses difference  to initiate if statements belowdouble comparison_2 = 0;
			double comparison_2 = input_2 - input_1;
			
			//If values are almost equal, the user is notified otherwise it simply prints the smaller and larger values.
			if (comparison_2 <= .01)
			{
			cout << "The values are almost equal.\n The smaller value is: " << input_1 << " The larger value is: " << input_2 << endl;
			}
			else
			{
			cout << "The smaller value is: " << input_1 << " The larger value is: " << input_2 << endl;
			}
		}
		
		//Else if the values are equal it lets the user know
		else
		{
		cout << "The values " << input_1 << " and " << input_2 << " are exactly equal." << endl;
		}
	}	
	return 0;
}