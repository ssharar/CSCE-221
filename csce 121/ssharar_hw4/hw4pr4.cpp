//Shaeeta Sharar
//CSCE 121 Section 508
//Due: October 7th, 2014
//hw4pr4.cpp

#include "std_lib_facilities_4.h"

//Functions
//Finds the maximum value of 3 given values
double find_max(double a, double b, double c)
{
	double x = 0;
	double y = 0;
	x = std::max(a,b);
	y = std::max(x,c);
	return y;
}


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
		double residual_x2 = 0;
		double d = 0;
		double new_a = 0;
		double new_b = 0;
		double new_c = 0;
		double abs_a = 0, abs_b = 0, abs_c = 0;
		 
		 
		//Inputs
		//Ask user for values of a, b and c
		cout << "Welcome to the quadratic formula calculator. \n" << "Please enter the values for a, b, and c: " << endl;
		cin >> a >> b >> c;
		
		//Cases
		//Tests for specific cases and acts accordingly
		if ( a ==0 && b ==0 && c ==0)
		{ 
			//Output 
			//Print values to user
			cout << "In this case say that x can be any number (real or complex)." << endl;
		}
		else if ( a ==0 && b ==0 && c !=0)
		{
			//Output 
			//Print values to user
			cout << "In this case the equation is inconsistent." << endl;
		}
		else if ( a==0 )
		{
			//Compute
			//Call the functions to perform the value and assign the value to a variable
			x1 = -c/b;
			residual_x1 = b*x1 + c;
			
			//Output 
			//Print values to user
			cout << "Your only root is: " << x1 << endl;
			cout << "The residual for the root is: " << residual_x1 << endl;
		}
		else if ( a !=0 && b ==0 && c ==0)
		{
			//Compute
			//Call the functions to perform the value and assign the value to a variable
			x1 = 0;
			residual_x1 = 0;
			
			//Output 
			//Print values to user
			cout << "Your only root is: " << x1 << endl;
			cout << "The residual for the root is: " << residual_x1 << endl;
			
		}
		else
		{
			//Calculations
			//Calculate d
			abs_a = abs(a);
			abs_b = abs(b);
			abs_c = abs(c);
			d = find_max(abs_a,abs_b,abs_c);
			
			//Compute
			//Adjust values of a, b, and c using the value of d calculated above
			new_a = a/d; 
			new_b = b/d; 
			new_c = c/d;
			
			//Cases
			//Tests for specific cases involving the new values of a, b, and c and acts accordingly
			if (new_a == 0)
			{	
				//Compute
				//Call the functions to perform the value and assign the value to a variable
				x1 = -new_c/new_b;
				residual_x1 = new_b*x1 + new_c;
			
				//Output 
				//Print values to user
				cout << "Your only root is: " << x1 << endl;
				cout << "The residual for the root is: " << residual_x1 << endl;
			}
			else
			{
				if (d == abs_b)
				{
					//Compute
					//Call the functions to perform the value and assign the value to a variable
					inside_sqrt = 1 - (4 * new_a * new_c);
		
					x1 = (-new_b + sqrt(inside_sqrt) ) / (2*new_a);
					x2 = (-new_b - sqrt(inside_sqrt) ) / (2*new_a);
		
					residual_x1 = new_a*pow(x1,2) + new_b*x1 + new_c;
					residual_x2 = new_a*pow(x2,2) + new_b*x2 + new_c;
		
					//Output 
					//Print values to user
					cout << "Your two roots are: " << x1 << " and " << x2 << endl;
					cout << "The residual for the first root is: " << residual_x1 << endl;
					cout << "The residual for the second root is: " << residual_x2 << endl;
				}
				else if (d == abs_a && a > 0)
				{
					//Compute
					//Call the functions to perform the value and assign the value to a variable
					inside_sqrt = new_b*b - (4 * new_c);
		
					x1 = (-new_b + sqrt(a) * sqrt(inside_sqrt) ) / (2*new_a);
					x2 = (-new_b - sqrt(a) * sqrt(inside_sqrt) ) / (2*new_a);
		
					residual_x1 = new_a*pow(x1,2) + new_b*x1 + new_c;
					residual_x2 = new_a*pow(x2,2) + new_b*x2 + new_c;
		
					//Output 
					//Print values to user
					cout << "Your two roots are: " << x1 << " and " << x2 << endl;
					cout << "The residual for the first root is: " << residual_x1 << endl;
					cout << "The residual for the second root is: " << residual_x2 << endl;
				}
				else if (d == abs_a && a < 0)
				{
					//Compute
					//Call the functions to perform the value and assign the value to a variable
					inside_sqrt = new_b*b + (4 * new_c);
		
					x1 = (-new_b + sqrt(-a) * sqrt(-inside_sqrt) ) / (2*new_a);
					x2 = (-new_b - sqrt(-a) * sqrt(-inside_sqrt) ) / (2*new_a);
		
					residual_x1 = new_a*pow(x1,2) + new_b*x1 + new_c;
					residual_x2 = new_a*pow(x2,2) + new_b*x2 + new_c;
		
					//Output 
					//Print values to user
					cout << "Your two roots are: " << x1 << " and " << x2 << endl;
					cout << "The residual for the first root is: " << residual_x1 << endl;
					cout << "The residual for the second root is: " << residual_x2 << endl;
				}
				else if (d == abs_c && c > 0)
				{
					//Compute
					//Call the functions to perform the value and assign the value to a variable
					inside_sqrt = new_b*b - (4 * new_a);
		
					x1 = (-new_b + sqrt(c) * sqrt(inside_sqrt) ) / (2*new_a);
					x2 = (-new_b - sqrt(c) * sqrt(inside_sqrt) ) / (2*new_a);
		
					residual_x1 = new_a*pow(x1,2) + new_b*x1 + new_c;
					residual_x2 = new_a*pow(x2,2) + new_b*x2 + new_c;
		
					//Output 
					//Print values to user
					cout << "Your two roots are: " << x1 << " and " << x2 << endl;
					cout << "The residual for the first root is: " << residual_x1 << endl;
					cout << "The residual for the second root is: " << residual_x2 << endl;
				}
				else if (d == abs_c && c < 0)
				{
					//Compute
					//Call the functions to perform the value and assign the value to a variable
					inside_sqrt = new_b*b + (4 * new_a);
		
					x1 = (-new_b + sqrt(-c) * sqrt(-inside_sqrt) ) / (2*new_a);
					x2 = (-new_b - sqrt(-c) * sqrt(-inside_sqrt) ) / (2*new_a);
		
					residual_x1 = new_a*pow(x1,2) + new_b*x1 + new_c;
					residual_x2 = new_a*pow(x2,2) + new_b*x2 + new_c;
		
					//Output 
					//Print values to user
					cout << "Your two roots are: " << x1 << " and " << x2 << endl;
					cout << "The residual for the first root is: " << residual_x1 << endl;
					cout << "The residual for the second root is: " << residual_x2 << endl;
				}
				else
				{
					cout << "Cannot compute." << endl;
				}
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