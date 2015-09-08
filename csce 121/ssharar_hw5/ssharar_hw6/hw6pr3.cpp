//Shaeeta Sharar
//CSCE 121 Section 508
//Due: October 21st, 2014
//hw6pr3.cpp

#include "std_lib_facilities_4.h"

//Functions
//Prints the binary version of a number
void print_binary(int n)
{
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

//Checks to see if binary number is pallendronic
int check(int num)
{
	//Variables
	int size;
	vector<int> store;
	vector<int> reverse_store;
	vector<int> pallen_confirmer;
	
	//Loops to find the binary version of a number
	//Store values into vector
	//	note: this fines the backwards version of the binary number, but this doesn't matter as it's only used to check if the value is a palindrome
	while (num > 0)
	{
		if(num%2 == 0)
		{
			store.push_back(0);
		}
		else
		{
			store.push_back(1);
		}
		num = num/2;
	}
	
	//Finding reverse vector	
	//Puts elements of binary number vector inside another vector in reverse
	for (int counter = store.size()-1; counter >= 0; --counter)
	{
		reverse_store.push_back(store[counter]);
	}
	
	//Reverse Comparision
	//Tests palindronic nature by checking each element of both forward and reverse vector to see if they are equal
	//Returns 1 if true, 2 if false
	size = store.size();
	if (store[1] != reverse_store[1])
	{
		return 2;
	}
	else
	{
		for (int y = 0; y < size; ++y)
		{
			if (store[y] == reverse_store[y])
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
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
		int number_input=0;
		
				
		//Inputs
		//Ask for number and store
		cout << "Please enter a number, enter a non-integer to exit: " << endl;
		
		
		
		//Repeats
		//Inputs and runs until value of non integer type entered
		while (cin >> number_input)
		{
			
			
			//Check if negative
			//	if negative print error
			//	if 0 print 0
			//	otherwise run function
			if (number_input < 0)
			{
				cout << "Error: number is negative. Try again." << endl;
			}
			
			else if (number_input == 0)
			{
				cout << "The binary number of 0 is 0." << endl;
			}
			
			else
			{
				
				//Outputs binary version of number.
				cout << "The binary number of " << number_input << " is ";
				print_binary(number_input);
				cout << " which is " ;
				//Reads return from palindromic check fucntion and prints if it's palindromic or not			
				if (check(number_input) == 1)
				{
					cout << "palindromic. \n";
				}
				else
				{
					cout << "not palindromic. \n";
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