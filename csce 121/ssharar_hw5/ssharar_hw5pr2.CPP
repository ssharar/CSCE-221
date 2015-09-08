//Shaeeta Sharar
//CSCE 121 Section 508
//Due: October 14th, 2014
//hw5pr2.cpp

#include "std_lib_facilities_4.h"


int main()
{
	//Error Check
	//Runs program until it's finished or error is found
	//Goes through catch to find source of error
	//If error is found tells user of error before quitting
	try {
		//Declaring variables
		//Names of files variables
		string input_file_1;
		string input_file_2;
		//Contents of file variables
		string line;
		string line2;
		int line_number = 1;
		//Input and Output streams of files variables
		ifstream file_1;
		ifstream file_2;
		ofstream output_file;
		
		//Input first file
		//Prompts user for file name, inputs filename, checks to make sure file is running
		cout << "Please enter the file name of input 1: " << endl;
		getline(cin, input_file_1); 

		file_1.open(input_file_1);
		
		if (!file_1.is_open())
		{
			cout << "Couldn't open file.";
		}

		//Input second file
		//Prompts user for file name, inputs filename, checks to make sure file is running
		cout << "Please enter the file name of input 1: " << endl;
		getline(cin, input_file_2); 

		file_2.open(input_file_2);
		
		if (!file_2.is_open())
		{
			cout << "Couldn't open file.";
		}

		//Output File
		//Opens a new txt file
		output_file.open ("output.txt");
		
		//Comparing Values
		//While the program hasn't reached the end of either txt file input
		//		the program gets a line, checks if the lines are exactly equal or not, prints either ok or diff to screen and file, increments line number
		while(!file_1.eof() || !file_2.eof())
		{
			getline(file_1,line);
			getline(file_2,line2);
			
			if (line == line2)
			{
				output_file << line_number << ":OK" << endl;
				cout << line_number << ":OK" << endl;
			}
			else
			{
				output_file << line_number << ":DIFF" << endl;
				cout << line_number << ":DIFF" << endl;
			}
			line_number++;
		}

		//Closes file
		output_file.close();
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
