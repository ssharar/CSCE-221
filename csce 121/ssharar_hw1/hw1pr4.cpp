//Shaeeta Sharar
//CSCE 121 Section 508
//Due: September 14, 2014
//hw1pr4.cpp

#include "std_lib_facilities_4.h"

int main()
{
	//Initialization of x
	int x = 1;
	
	//List 
	//A for loop is used to go through the algorithim and print out a list
	//The variables x2 and y are used to evaluate square and squareroot respectively then are printed to the screen. X is then changed to continue the formula
		for (int counter = 0; counter <11 ; counter++) 
	{
		int x2 = x * x;
		double y = sqrt(x2);
		cout << "square root of " << x2 << " is " << y << endl; 
		x *= 10;
	}
	
	//Explanation for strange values
	cout << "After a certain value, the value of the integer x exceeds the memory for an int. Thus the computer begins filling in junk values to the int and this produces the weird numbers. \n";
	
	return 0;
}
	