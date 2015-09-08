//Shaeeta Sharar
//CSCE 121 Section 508
//Due: October 21st, 2014
//hw6pr2.cpp

#include "std_lib_facilities_4.h"

//Functions
//Prints the binary version of a number
void print_binary(int n)
{
	//PSUEDO CODE PROVIDED:
	/*
		void print_binary(int n){
		if n isn't zero, print_binary(all but last bit of n)
		//print last bit
		if n mod 2 is 0, print a 0
		otherwise print a 1		
		}
	*/
	
	//last bit finder:
	int x = (n& 0x1);
	
	if (n != 0)
	{
		//every bit except last:
		print_binary(n >> 1);
		
		cout << x ;
	}
	else if (n%2 == 0 && n ==0)
	{
		
	}
	else if (n%1 == 0 && n !=0)
	{
		cout << 0;
	}
	else
	{
		cout << 1 ;
	}
}

int main()
{
	//Error Check
	//Runs program until it's finished or error is found
	//Goes through catch to find source of error
	//If error is found tells user of error before quitting
	try {
		//Declare Variables
		int number=0;
		
		//Inputs
		//Ask for number and store
		cout << "Please enter a number, enter a non-integer to exit: " << endl;
		
		//Repeats
		//Inputs and runs until value of non integer type entered
		while (cin >> number)
		{
			//Check if negative
			//	if negative print error
			//	if 0 print 0
			//	otherwise run function
			if (number < 0)
			{
				cout << "Error: number is negative. Try again." << endl;
			}
			else if (number == 0)
			{
				cout << "The binary number of 0 is 0." << endl;
			}
			else
			{
				cout << "The binary number of " << number << " is ";
				print_binary(number);
				cout << "." << endl;
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