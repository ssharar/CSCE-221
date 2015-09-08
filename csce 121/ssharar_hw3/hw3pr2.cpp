//Shaeeta Sharar
//CSCE 121 Section 508
//Due: September 28, 2014
//hw3pr2.cpp

#include "std_lib_facilities_4.h"

//A function which reads in a double and outputs a square root 10 times
double my_sqrt_1(double n)
{
	//Initializing variables in the scope of the function
	double x = 1;
	
	//Repeat
	//Uses a counter to repeat the function 10 times
	for (int count = 1 ; count == 10 ; count++)
	{
		//Square root function
		//Computes square root
		x = (x + n/x)/2;
	}
	
	//Returns the value computed above
	return x;
} 

int main()
{
	//Error Check
	//Runs program until it's finished or error is found
	//Goes through catch to find source of error
	//If error is found tells user of error before quitting
	try {
		//Initializing variables
		double n = 0;
		double relative_error_per_cent = 0;
	
		//Repeat
		//For a list of values, the function is computed
		for(auto k : {-100, -10, -1, 0, 1, 10, 100})
		{
			//Computes function for finding 
			n = M_PI * pow(10.0, k);
			
			relative_error_per_cent = 100 * ( (my_sqrt_1(n) - sqrt(n)) / sqrt(n) );
		
			//Outputs
			//Prints values of n, square root of n and the function square root of n
			cout << "The value of n is " << n << endl
				 << "The value of the square root n is " << sqrt(n) << endl
				 << "The value of my square root is " << my_sqrt_1(n);
			
			cout << setw(40) << "The relative error is " << relative_error_per_cent << endl;
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