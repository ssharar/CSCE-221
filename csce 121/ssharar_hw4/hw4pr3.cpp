//Shaeeta Sharar
//CSCE 121 Section 508
//Due: October 7th, 2014
//hw4pr3.cpp

#include "std_lib_facilities_4.h"

//Functions
//Checks if the answer starts with y 
//Returns true if it does
//Returns false if it doesn't
bool check_if_yes(char letter)
{
	if (letter == 'Y')
	{
		return true;
	}
	else if (letter == 'y')
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main()
{
	//Error Check
	//Runs program until it's finished or error is found
	//Goes through catch to find source of error
	//If error is found tells user of error before quitting
	try {
		
		//Declaring variables
		vector<string> question;
		string answer;
		char letter;
		
		//Adding elements to the vector
		question.push_back("Are you thinking of a human?");
		question.push_back("Are they a famous celebrity?");
		question.push_back("Are they below five feet?");
		question.push_back("Are they the champion of the sun? Master of karate and friendship for everyone?");
		question.push_back("Are you thinking of something that is a part of a large franchise?");
		question.push_back("Did you waste your life away using this?");
		question.push_back("Can it be used to quiet a loud cat?");
		
		//Inputs
		//Displays welcome message to user
		//Asks the user the first question and then records the response
		cout << "Hello welcome to the guessing game." << endl;
		cout << "Please choose one of these 8 options: Danny Devito, Steve Buscemi, The Dayman, Final Fantasy VII, Kitten Mittens (TM), Gunter (Adventure Time), Charlie Kelly King of the Rats, or garbage." << endl;
		cout << "Picked one? Good. I'll now try to guess your choice by asking you a series of questions. Let's begin." << endl;
		
		cout << question[0] << endl;
		cin >> answer;
		letter = answer[0];
		
		//Begins Checking
		//Calls Function and asks if the answer was true or false
		
		//If true it asks a set of nestled questions based on the value the function returns
		//Otherwise asks a different set of nestled questions
		if (check_if_yes(letter)==true)
		{
			cout << question[1] << endl;
			cin >> answer;
			letter = answer[0];
			
			if (check_if_yes(letter)==true)
			{
				cout << question[2] << endl;
				cin >> answer;
				letter = answer[0];
				
				if (check_if_yes(letter)==true)
				{
					cout << "You must be thinking of Danny Devito." << endl;
				}
				else
				{
					cout << "You must be thinking of Steve Buscemi." << endl;
				}
			}
			else
			{
				cout << question[3] << endl;
				cin >> answer;
				letter = answer[0];
				
				if (check_if_yes(letter)==true)
				{
					cout << "You must be thinking of The Dayman ahh ahhh AHHHHHHHH." << endl;
				}
				else
				{
					cout << "You must be thinking of Charlie Kelly King of the Rats." << endl;
				}
			}
		}
		else 
		{
			cout << question[4] << endl;
			cin >> answer;
			letter = answer[0];
			
			if (check_if_yes(letter)==true)
			{
				cout << question[5] << endl;
				cin >> answer;
				letter = answer[0];
				
				if (check_if_yes(letter)==true)
				{
					cout << "You must be thinking of Final Fantasy VII." << endl;
				}
				else
				{
					cout << "You must be thinking of Gunter from Adventure Time." << endl;
				}
			}
			else
			{
				cout << question[6] << endl;
				cin >> answer;
				letter = answer[0];
				
				if (check_if_yes(letter)==true)
				{
					cout << "You must be thinking of kitten mittens." << endl;
				}
				else
				{
					cout << "You must be thinking of garbage." << endl;
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