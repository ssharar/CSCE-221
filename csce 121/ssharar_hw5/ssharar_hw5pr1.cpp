//Shaeeta Sharar
//CSCE 121 Section 508
//Due: October 14th, 2014
//hw5pr1.cpp

#include "std_lib_facilities_4.h"
#include "randint.h"


int main()
{
	//Error Check
	//Runs program until it's finished or error is found
	//Goes through catch to find source of error
	//If error is found tells user of error before quitting
	try {
		//Declaring Variables
		vector<int> number_0s;
		vector<int> number_1s;
		vector<int> number_2s;
		vector<int> number_3s;
		vector<int> number_4s;
		vector<int> number_5s;
		vector<int> number_6s;
		vector<int> number_7s;
		vector<int> number_8s;
		vector<int> number_9s;
		int randint_caller = 0;

		for (int count = 0; count <= 1000000; count++)
		{
			//Calling Function
			//Calls function and finds remainder aka the last digit
			randint_caller = randint();
			randint_caller = randint_caller%10;
			
			//Checking
			//Checks if last digit is equal to 1, 2, 3, 4, 5, 6, 7, 8, 9, or 0 and stores a number in a vector
			if (randint_caller == 0)
			{
				number_0s.push_back(1);
			}
			else if (randint_caller == 1)
			{
				number_1s.push_back(1);
			}
			else if (randint_caller == 2)
			{
				number_2s.push_back(1);
			}
			else if (randint_caller == 3)
			{
				number_3s.push_back(1);
			}
			else if (randint_caller == 4)
			{
				number_4s.push_back(1);
			}
			else if (randint_caller == 5)
			{
				number_5s.push_back(1);
			}
			else if (randint_caller == 6)
			{
				number_6s.push_back(1);
			}
			else if (randint_caller == 7)
			{
				number_7s.push_back(1);
			}
			else if (randint_caller == 8)
			{
				number_8s.push_back(1);
			}
			else
			{
				number_9s.push_back(1);
			}
		}
		
		//Outputs
		//Prints the number of entries ending in 0s, 1s, ect.
		cout << "There were " << number_0s.size() << " 0's." << endl;
		cout << "There were " << number_1s.size() << " 1's." << endl;
		cout << "There were " << number_2s.size() << " 2's." << endl;
		cout << "There were " << number_3s.size() << " 3's." << endl;
		cout << "There were " << number_4s.size() << " 4's." << endl;
		cout << "There were " << number_5s.size() << " 5's." << endl;
		cout << "There were " << number_6s.size() << " 6's." << endl;
		cout << "There were " << number_7s.size() << " 7's." << endl;
		cout << "There were " << number_8s.size() << " 8's." << endl;
		cout << "There were " << number_9s.size() << " 9's." << endl;
				
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