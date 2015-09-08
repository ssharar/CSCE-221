//Shaeeta Sharar
//CSCE 121 Section 508
//Due: September 14, 2014
//hw1pr3.cpp

#include "std_lib_facilities_4.h"

int main()
{
	//Deceleration/Initialization of variables
	//The variables titled penny_# or pound_# are user inputs
	//Variables titled penny_#_converted or its variants are used during conversion below.
	int penny_1 = 0;
	int penny_2 = 0, penny_2_converted = 0;
	int penny_5 = 0, penny_5_converted = 0;
	int penny_10 = 0, penny_10_converted = 0;
	int penny_20 = 0, penny_20_converted = 0;
	int penny_25 = 0, penny_25_converted = 0;
	int penny_50 = 0, penny_50_converted = 0;
	int pound_1 = 0, pound_1_converted = 0;
	int pound_2 = 0, pound_2_converted = 0;
	int pound_5 = 0, pound_5_converted = 0;

	int sum = 0;
	int british_to_us;
	
	//User inputs 
	//The user is prompted to enter amounts of coins and those inputs are stored.
	cout << "How many 1-penny coins do you have?" << endl;
	cin >> penny_1;

	cout << "How many 2-penny or tuppence coins do you have?" << endl;
	cin >> penny_2;

	cout << "How many 5-penny coins do you have?" << endl;
	cin >> penny_5;

	cout << "How many 10-penny coins do you have?" << endl;
	cin >> penny_10;

	cout << "How many 20-penny coins do you have?" << endl;
	cin >> penny_20;

	cout << "How many 25-penny coins do you have?" << endl;
	cin >> penny_25;

	cout << "How many 50-penny coins do you have?" << endl;
	cin >> penny_50;

	cout << "How many 1-pound coins do you have?" << endl;
	cin >> pound_1;

	cout << "How many 2-pound coins do you have?" << endl;
	cin >> pound_2;

	cout << "How many 5-pound coins do you have?" << endl;
	cin >> pound_5;

	//Conversion and sum
	//The input values are converted to their 1-penny equivalent amount. 
	//Those values are used to calculate the total in pence as well as the converted value is US dollars
	penny_2_converted = penny_2 * 2;
	penny_5_converted = penny_5 * 5;
	penny_10_converted = penny_10 * 10;
	penny_20_converted = penny_20 * 20;
	penny_25_converted = penny_25 * 25;
	penny_50_converted = penny_50 * 50;

	pound_1_converted = pound_1 * 100;
	pound_2_converted = pound_2 * 200;
	pound_5_converted = pound_5 * 500;

	sum = penny_1 + penny_2_converted + penny_10_converted + penny_20_converted + penny_25_converted + penny_50_converted + pound_1_converted + pound_2_converted + pound_5_converted;
	british_to_us = sum * .0162;

	//Print to screen
	//Input values are printed out to the user in the correct format
	//The conversion values are then printed
	cout << "You have " << penny_1 << " 1-penny coins." << endl;
	cout << "You have " << penny_2 << " 2-penny coins." << endl;
	cout << "You have " << penny_5 << " 5-penny coins." << endl;
	cout << "You have " << penny_10 << " 10-penny coins." << endl;
	cout << "You have " << penny_20 << " 20-penny coins." << endl;
	cout << "You have " << penny_25 << " 25-penny coins." << endl;
	cout << "You have " << penny_50 << " 50-penny coins." << endl;
	cout << "You have " << pound_1 << " 1-pound coins." << endl;
	cout << "You have " << pound_2 << " 2-pound coins." << endl;
	cout << "You have " << pound_5 << " 5-pound coins." << "\n \n";
	cout << "The value of all of your coins is " << sum << " pence." << endl;
	cout << "This amount in US dollars is " << british_to_us << " dollars." <<endl;


	return 0;
}