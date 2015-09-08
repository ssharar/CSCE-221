//Shaeeta Sharar
//CSCE 121 Section 508
//Due: October 7th, 2014
//hw4pr1.cpp

#include "std_lib_facilities_4.h"



int main()
{
	//Error Check
	//Runs program until it's finished or error is found
	//Goes through catch to find source of error
	//If error is found tells user of error before quitting
	try {
		
		//Initializing Variables
		//a, b, and c are user inputs
		//x1 and x2 are the roots found
		double a = 0;
		double b = 0;
		double c = 0;
		double x1 = 0;
		double x2 = 0;
		double inside_sqrt = 0;
		double residual_x1 = 0;
		double residual_x2 = 9;
		 
		//Inputs
		//Ask user for values of a, b and c
		cout << "Welcome to the quadratic formula calculator. \n" << "Please enter the values for a, b, and c: " << endl;
		cin >> a >> b >> c;
		
		//Compute
		//Call the functions to perform the value and assign the value to a variable
		inside_sqrt = pow(b, 2) - (4 * a * c);
		
		x1 = (-b + sqrt(inside_sqrt) ) / (2*a);
		x2 = (-b - sqrt(inside_sqrt) ) / (2*a);
		
		residual_x1 = a*pow(x1,2) + b*x1 + c;
		residual_x2 = a*pow(x2,2) + b*x2 + c;
		
		//Output 
		//Print values to user
		cout << "Your two roots are: " << x1 << " and " << x2 << endl;
		cout << "The residual for the first root is: " << residual_x1 << endl;
		cout << "The residual for the second root is: " << residual_x2 << endl;
		
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