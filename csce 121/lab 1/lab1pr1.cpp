//Shaeeta Sharar
//CSCE 121 Section 508
//Due: September 25, 2014
//lab1pr1.cpp

#include "std_lib_facilities_4.h"

int main()
{
	//Variables initialized
	int input_1 =0;
	int input_2 =0;
	
	//Inputs
	//Asks user to input two ints
	cout << "Please enter two integers. Press '|' to terminate." << endl;
	
	//Reads Inputs
	//Breaks when character "|" is the input (or if value is not of int type)
	//Otherwise prints the two inputs
	while (cin >> input_1 >> input_2)
	{
		cout << "Here are your inputs: " << input_1 << " " << input_2 << endl;
	}	
	return 0;
}