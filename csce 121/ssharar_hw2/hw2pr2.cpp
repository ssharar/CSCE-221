//Shaeeta Sharar
//CSCE 121 Section 508
//Due: September 21, 2014
//hw2pr2.cpp

#include "std_lib_facilities_4.h"

int main()
{
	//Initializing variables
	//One is an input value obtained from the user
	//The other is a vector containing the Bill of Rights
	int amendment_number = 0;
	vector<string> bill_of_rights;
	
	//Amendments
	//The 1st 10 amendments are put inside the vector in numerical order
	bill_of_rights.push_back("The first amendment is: Freedom of religion, speech, and the press, right of petition and assembly.");
	bill_of_rights.push_back("The second amendment is: Right to bear arms.");
	bill_of_rights.push_back("The third amendment is: Government can not force people to quarter troops in their homes.");
	bill_of_rights.push_back("The fourth amendment is: Protects against unreasonable search and seizure.");
	bill_of_rights.push_back("The fifth amendment is: Rights of people accused of crimes.");
	bill_of_rights.push_back("The sixth amendment is: Right to trial by jury in criminal cases.");
	bill_of_rights.push_back("The seventh amendment is: Right to trial by jury in civil cases.");
	bill_of_rights.push_back("The eight amendment is: Forbids excessive bail and cruel or unusual punishment.");
	bill_of_rights.push_back("The ninth amendment is: People's rights are not limited to those listed in the Constitution.");
	bill_of_rights.push_back("The tenth amendment is: States or people have all powers not denied or given to federal government by the Constitution.");
	
	
	//Inputs
	//The user is asked to input the number of an amendment and their answer is stored
	cout << "Please enter an amendment from the Bill of Rights: " << endl;
	cin >> amendment_number;
	
	//Checking number
	//If the amendment number entered is between 1 and 10 then the program prints the requested amendment by calling that spot on the vector
	//Otherwise the program notifies the user of an error and quits
	if (amendment_number >= 1 && amendment_number <= 10 )
	{
		cout << bill_of_rights[amendment_number-1] << endl;
	}
	else 
	{
		cout << "That is not an amendment in the Bill of Rights.  Please enter a number between 1 and 10 and try again."<< endl; 
	}
	return 0;
}