//Shaeeta Sharar
//CSCE 121 Section 508
//Due: October 21st, 2014
//hw6pr1.cpp
// 	Chrono.h for ssharar


//
// This is example code from Chapter 9.8 "The Date class" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------

namespace Chrono {

//------------------------------------------------------------------------------

class Date {
public:
    enum Month {
        jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };
	
	enum Day {
    saturday=0, sunday, monday, tuesday, wednesday, thursday, friday
	};

    class Invalid { };                 // to throw as exception

    Date(int y, Month m, int d);       // check for valid date and initialize
    Date();                            // default constructor
    // the default copy operations are fine

	
    // non-modifying operations:
    int   day()   const { return d; }
    Month month() const { return m; }
    int   year()  const { return y; }

    // modifying operations:
    void add_day(int n);        
    void add_month(int n);
    void add_year(int n);
	
	void subtract_year(int n);
	
	Date& operator++();
	
	Day day_of_week();
	
	//USED ONLY FOR HW6PR4
	Date& operator++(int);
	
private:
    int   y;
    Month m;
    int   d;
};

//------------------------------------------------------------------------------

bool is_date(int y, Date::Month m, int d); // true for valid date

//------------------------------------------------------------------------------

bool leapyear(int y);                  // true if y is a leap year

//------------------------------------------------------------------------------

bool operator==(const Date& a, const Date& b);
bool operator!=(const Date& a, const Date& b);

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Date& d);
istream& operator>>(istream& is, Date& dd);

//------------------------------------------------------------------------------

} // Chrono
