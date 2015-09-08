//Shaeeta Sharar
//CSCE 121 Section 508
//Due: September 28, 2014
//hw3pr3.cpp

#include "std_lib_facilities_4.h"

int main()
{
	//Error Check
	//Runs program until it's finished or error is found
	//Goes through catch to find source of error
	//If error is found tells user of error before quitting
	try {
		//Decleration of Variables
		vector<string> input_words;
		vector<int> aggie_counter;
		
		//Inputs
		//Prompts user for a sentence/phrase
		//Inputs the words into a vector and stores them
		//Stops taking in entries when either ctrl+z or ctrl+d are used
		cout << "Welcome. \n" << "This program will count how many times the word aggies or a variant appears in a sentence \n" << "Please type a sentence. Press CTRL+D (Unix) or CTRL+Z (windows) to exit." << endl;
		for (string words; cin >> words;)
		{
			input_words.push_back(words);
		}
		
		//Counter
		//Checks every element inside the input vector to see if it matches the words "Aggie," "Aggies," "aggie," or "aggies" is entered
		//Stores a "1" in a counter vector for each form of aggies
		for (int element = 0; element<input_words.size(); ++element)
		{
			if (input_words[element] == "Aggie")
			{
				aggie_counter.push_back(1);
			}
			else if (input_words[element] == "Aggies")
			{
				aggie_counter.push_back(1);
			}
			else if (input_words[element] == "aggie")
			{
				aggie_counter.push_back(1);
			}
			else if (input_words[element] == "aggies")
			{
				aggie_counter.push_back(1);
			}
			else
			{
			}
		}
		
		//Outputs
		//Outputs the number of times the word aggie or its variants are entered (the size of the counter vector)
		cout << "The number of times the words Aggie or Aggies or aggie or aggies occur in the keyboard input is: " << aggie_counter.size() << endl;
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
	
	keep_window_open();
	return 0;
}