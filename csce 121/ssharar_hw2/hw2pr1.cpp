//Shaeeta Sharar
//CSCE 121 Section 508
//Due: September 21, 2014
//hw2pr1.cpp

#include "std_lib_facilities_4.h"

int main()
{
	//Initialize Variables
	//It is an input value obtained from the user
	int amendment_number = 0;
	
	//Repeat
	//Breaks if the user does not input a value between 1-10
	//Otherwise runs the main code of printing the summary of requested amendment
	while(true)
	{
		//Inputs
		//The user is asked to input the number of an amendment and their answer is stored
		cout << "Please enter an amendment from the Bill of Rights: " << endl;
		cin >> amendment_number;
		if (amendment_number <= 10 && amendment_number >= 1)
		{
		//Checking number
		//If the amendment number entered is between 1 and 10 then the program prints the requested amendment by going down the if/else statements and finding the number that matches
		//Otherwise the program notifies the user of an error and quits
			if (amendment_number == 1)
			{
				cout << "The first amendment is: Freedom of religion, speech, and the press, right of petition and assembly." << endl;
			}
			else if (amendment_number == 2)
			{
				cout << "The second amendment is: Right to bear arms." << endl;
			}
			else if (amendment_number == 3)
			{
				cout << "The third amendment is: Government can not force people to quarter troops in their homes."<< endl;
			}
			else if (amendment_number == 4)
			{
				cout << "The fourth amendment is: Protects against unreasonable search and seizure."<< endl;
			}
			else if (amendment_number == 5)
			{
				cout << "The fifth amendment is: Rights of people accused of crimes."<< endl;
			}
			else if (amendment_number == 6)
			{
				cout << "The sixth amendment is: Right to trial by jury in criminal cases."<< endl;
			}
			else if (amendment_number == 7)
			{
				cout << "The seventh amendment is: Right to trial by jury in civil cases."<< endl;
			}
			else if (amendment_number == 8)
			{
				cout << "The eight amendment is: Forbids excessive bail and cruel or unusual punishment."<< endl;
			}
			else if (amendment_number == 9)
			{
				cout << "The ninth amendment is: People's rights are not limited to those listed in the Constitution."<< endl;
			}
			else if (amendment_number == 10)
			{
				cout << "The tenth amendment is: States or people have all powers not denied or given to federal government by the Constitution."<< endl;
			}
			else 
			{
				cout << "That is not an amendment in the Bill of Rights.  Please enter a number between 1 and 10."<< endl; 
			}
		}
		else
		{
			break;
		}	
	}
	return 0;
}