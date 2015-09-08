//Shaeeta Sharar
//CSCE 121 Section 508
//Lab 5 Test_output.cpp

#include "std_lib_facilities_4.h"


int main()
{
	//Error Check
	//Runs program until it's finished or error is found
	//Goes through catch to find source of error
	//If error is found tells user of error before quitting
	try {
		//Declaring variables
		int birth_year = 1995;
		int a =0, b =0, c =0, d =0;
		double number = 1234567.89;
		
		//Outputs with birth year
		//	changes birth year to various different notations
		//	shows the base for each notations
		//	shows age in decimal
		cout << "\nDecimal: " << showbase << birth_year << "\t" << 
			"Hexadecimal: " << showbase << hex << birth_year << "\t" << 
			"Octal: " << showbase << oct << birth_year << endl;
		cout << "My age is: " << dec << 2014-birth_year << "\n\n";
		
		//Reading in as octal and hexidecimal
		//Outputs numbers entered
		cout << "Please enter four numbers: " << endl;
		cin >> a >> oct >> b >> hex >> c >> d;
		cout << a << "\t" << b << "\t" << c << "\t" << d << "\n\n";
			//Explain:
			//	when a, b, c, and d are inputted they are set as the dec, oct, hex, hex, respectively.
		
		//Printing number several times
		cout << "Printing out the number 1234567.89 \n Default-float: " << number << "\t"
			<< "Fixed: " << fixed << number << "\t"
			<< "Scientific: " << scientific << number << "\n\n";
			//Explain which is most accurate
			//	fixed is most accurate in this case because it presents all of the number to the screen
		
		
		//Address book 
		//	uses setw to set width
		cout << "First name: " << setw(12) << "Last name: " << setw(12) << "Number: " << setw(20) << "Email: " <<endl <<endl;
		cout << "Charlie" << setw(11) << "Kelly" << setw(22) << "445-789-0987" << setw(32) << "milksteak@paddyspub.com" <<endl;
		cout << "Ronald" << setw(15) << "McDonald" << setw(20) << "1-800-CALLMAC" << setw(39) << "mackaratemaster88@paddyspub.com" <<endl;
		cout << "Dennis" << setw(15) << "Reynolds" << setw(19) << "345-765-3321" << setw(38) << "glitterglamrock@paddyspub.com" <<endl;
		cout << "Dee" << setw(18) << "Reynolds" << setw(19) << "167-885-7877" << setw(31) << "sweetdee@paddyspub.com" <<endl;
		cout << "Frank" << setw(16) << "Reynolds" << setw(19) << "456-836-8859" << setw(33) << "thewombat@reynoldsco.com" <<endl;
		
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