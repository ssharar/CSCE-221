//Shaeeta Sharar
//CSCE 121 Section 508
//Due: September 14, 2014
//hw1pr2.cpp

#include "std_lib_facilities_4.h"

int main()
{
	//Deceleration/Initialization of variables
	//The variables number_1, number_2, and operand are user inputs. The double answer is used to store the computation of the user inputs.
	double number_1 = 0;
	double number_2 = 0;
	string operand;

	double answer = 0;

	//Inputs from user
	//The user is prompted to enter two numbers followed by an operand.
	//These inputs are then stored into their respective variables (created above).
	cout << "Please enter two numbers followed by an operand. \nNumbers should be sperated by only a space. \nAcceptable operands are +, -, *, /, plus, minus, mul or div.\n";
	cin >> number_1 >> number_2 >> operand;
	
	//Operand Comparison
	//A large if statement is used to compare the operand provided by the user to other possible operands. It is then used to perform a computation between the two provided numbers. Answers are then printed to the page. 
	//If an invalid operand or number is entered, the user is notified and the program ends.
	if (operand == "+") 
	{
		answer = number_1 + number_2;
		cout << "The answer is: " << answer;
	}
	else if (operand == "-") 
	{
		answer = number_1 - number_2;
		cout << "The answer is: " << answer;
	}
	else if (operand == "*") 
	{
		answer = number_1 * number_2;
		cout << "The answer is: " << answer;
	}
	else if (operand == "/") 
	{
		answer = number_1 / number_2;
		cout << "The answer is: " << answer;
	}
		else if (operand == "minus") 
		{
		answer = number_1 - number_2;
		cout << "The answer is: " << answer;
	}
	else if (operand == "mul") 
	{
		answer = number_1 * number_2;
		cout << "The answer is: " << answer;
	}
	else if (operand == "div") 
	{
		answer = number_1 / number_2;
		cout << "The answer is: " << answer;
	}
	else if (operand == "plus") 
	{
		answer = number_1 + number_2;
		cout << "The answer is: " << answer;
	}
	else 
	{
		cout << "The operand/number you entered was invalid. Please try again."; 
	}

	return 0;
}