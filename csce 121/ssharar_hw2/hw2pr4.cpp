//Shaeeta Sharar
//CSCE 121 Section 508
//Due: September 21, 2014
//hw2pr4.cpp

#include "std_lib_facilities_4.h"

int main()
{
	vector<int> quantities;
	vector<int> denomination;

	denomination.push_back(1);
	denomination.push_back(2);
	denomination.push_back(5);
	denomination.push_back(10);
	denomination.push_back(20);
	denomination.push_back(25);
	denomination.push_back(50);
	denomination.push_back(100);
	denomination.push_back(200);
	denomination.push_back(500);

	int input_amount;

	int number_of_coins = 1;
	
	int sum = 0;
	int british_to_us;
	
	for (int count = 0 ; count < 7 ; count++)
	{
		number_of_coins = denomination[count];
		cout << "How many : " << number_of_coins <<"-penny coins do you have?" << endl;
		cin >> input_amount;
		quantities.push_back(input_amount);
		
	}
	
	for (int count = 7 ; count <= 9 ; count++)
	{
		number_of_coins = (denomination[count])/100;
		cout << "How many : " << number_of_coins  <<"-pound coins do you have?" << endl;
		cin >> input_amount;
		quantities.push_back(input_amount);
		
	}
	
	sum = quantities[0]*denomination[0] + quantities[1]*denomination[1] + quantities[2]*denomination[2] + quantities[3]*denomination[3] + quantities[4]*denomination[4] + quantities[5]*denomination[5] + quantities[6]*denomination[6] + quantities[7]*denomination[7] + quantities[8]*denomination[8] + quantities[9]*denomination[9];
	british_to_us = sum * .0162;

	cout << "\nYou have " << quantities[0] << " 1-penny coins." << endl;
	cout << "You have " << quantities[1] << " 2-penny coins." << endl;
	cout << "You have " << quantities[2] << " 5-penny coins." << endl;
	cout << "You have " << quantities[3] << " 10-penny coins." << endl;
	cout << "You have " << quantities[4] << " 20-penny coins." << endl;
	cout << "You have " << quantities[5] << " 25-penny coins." << endl;
	cout << "You have " << quantities[6] << " 50-penny coins." << endl;
	cout << "You have " << quantities[7] << " 1-pound coins." << endl;
	cout << "You have " << quantities[8] << " 2-pound coins." << endl;
	cout << "You have " << quantities[9] << " 5-pound coins." << "\n \n";
	cout << "The value of all of your coins is " << sum << " pence." << endl;
	cout << "This amount in US dollars is " << british_to_us << " dollars." <<endl <<endl;

	return 0;
}