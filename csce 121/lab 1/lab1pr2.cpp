//Shaeeta Sharar
//CSCE 121 Section 508
//Due: September 25, 2014
//lab1pr2.cpp

#include "std_lib_facilities_4.h"

int main()
{
	//Variables initialized
	int input_1 =0;
	int input_2 =0;
	
	//Inputs
	//Asks user to input two ints
	cout << "Please enter two integers. Press '|' to terminate." << endl;
	
	//Reads inputs
	//If the 1st value is larger it prints a statement saying so
	//Else, if the 2nd value is larger or the two values are equal it prints a statement saying so
	//Terminates the program when "|" or a type other than int is entered
	while (cin >> input_1 >> input_2)
	{
		if (input_1 > input_2)
		{
		 cout << "The smaller value is: " << input_2 << " The larger value is: " << input_1 << endl;
		}
		else
		{
		cout << "The smaller value is: " << input_1 << " The larger value is: " << input_2 << endl;
		}
	}	
	return 0;
}