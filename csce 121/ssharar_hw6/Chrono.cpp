//Shaeeta Sharar
//CSCE 121 Section 508
//Due: October 21st, 2014
//hw6pr1.cpp
// 	Chrono.cpp for ssharar

/*//////NOTE////////
THIS IS A WORKIG FILE 
COMPILES PROPERLY
BUT NO COMMENTS
COPY COMMENTS FROM SCHOOL VER
///////NOTE///////*/

//
// This is example code from Chapter 9.8 "The Date class" of 
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Chrono.h"

namespace Chrono {

// member function definitions:

//------------------------------------------------------------------------------

Date::Date(int yy, Month mm, int dd)
    : y(yy), m(mm), d(dd)
{
    if (!is_date(yy,mm,dd)) throw Invalid();
}

//------------------------------------------------------------------------------

const Date& default_date()
{
    static const Date dd(2001,Date::jan,1); // start of 21st century
    return dd;
}

//------------------------------------------------------------------------------

Date::Date()
    :y(default_date().year()),
     m(default_date().month()),
     d(default_date().day())
{
}

//------------------------------------------------------------------------------
//MY CODE, edited this function
void Date::add_day(int n)
{
	//if the day is the end of a month, increments month and sets day to 1
	//in the special case of feburary, must check if it's a leapyear to change date_order
	//otherwise increment day
	if (n == 30)
	{
		if (m == apr || m == jun || m == sep || m == nov)
		{
			d = 1;
			add_month(m);
		}
	
	}
	else if (n == 31)
	{
		if (m == jan || m == mar || m == may || m == jul || m == aug || m == oct || m == dec)
		{
			d = 1;
			add_month(m);
		}
	}
	else if (m == feb && n == 28 && !leapyear(y))
	{
		d = 1;
		add_month(m);
	}
	else if (m == feb && n == 29 && leapyear(y))
	{
		d = 1;
		add_month(m);
	}	
	else
	{
		d= n+1;
	}
	
	
	
}

//------------------------------------------------------------------------------
//MY CODE, edited this function
void Date::add_month(int n)
{
	//if the month is december, change the month to january and increment the year
	//otherwise increment the month
    if (m == dec)
	{
		m = jan;
		add_year(y);
	}
	else
	{
		m = Month(m+1);
	}

}

//------------------------------------------------------------------------------
//MY CODE, edited this function
void Date::add_year(int n)
{
	//adds one to year
    y= n+1;
}

//------------------------------------------------------------------------------
//MY CODE, edited this function
void Date::subtract_year(int n)
{
    //subtracts one from year
	y= n-1;
}

//------------------------------------------------------------------------------
//MY CODE, edited this function
Date& Date::operator++()
 {
		//If it's the 1st of the month, increment the month
		//	if it's the 1st of January, increment the year
		//otherwise increment the day and return that value
		if (d == 1)
		{
			add_month(m);
			if (m == jan)
			{
				add_year(y);
			}
		}
		else
		{
			add_day(d);
		}
		
		
		return *this;
	}

	
//------------------------------------------------------------------------------
//MY CODE, edited this function
//ONLY USED FOR HW6PR4
Date& Date::operator++(int)
 {
		//If it's the 1st of the month, increment the month
		//	if it's the 1st of January, increment the year
		//otherwise increment the day and return that value
		
		//Assigns the this pointer to a
		Date a = *this;
		
		//Increments d1
        if (d == 1)
		{
			add_month(m);
			if (m == jan)
			{
				add_year(y);
			}
		}
		else
		{
			add_day(d);
		}
		cout <<"This-> is valid"<<endl;
		
		//Returns old value of *this before increment to d3
		return a;
		
		
	}
	
//------------------------------------------------------------------------------


// helper functions:

bool is_date(int y, Date::Month  m, int d)
{
    // assume that y is valid

    if (d<=0) return false;            // d must be positive

    int days_in_month = 31;            // most months have 31 days

    switch (m) {
case Date::feb:                        // the length of February varies
    days_in_month = (leapyear(y))?29:28;
    break;
case Date::apr: case Date::jun: case Date::sep: case Date::nov:
    days_in_month = 30;                // the rest have 30 days
    break;
    }

    if (days_in_month<d) return false;

    return true;
} 

//------------------------------------------------------------------------------
//MY CODE, edited this function
bool leapyear(int y)
{
    if (y%4 == 0)
	{
		if (y%100 == 0)
		{
			if (y%400 == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return true;
		}
	}
    else
	{
		return false;
	}
}

//------------------------------------------------------------------------------


bool operator==(const Date& a, const Date& b)
{
    return a.year()==b.year()
        && a.month()==b.month()
        && a.day()==b.day();
}

//------------------------------------------------------------------------------

bool operator!=(const Date& a, const Date& b)
{
    return !(a==b);
}

//------------------------------------------------------------------------------

ostream& operator<<(ostream& os, const Date& d)
{
    return os << '(' << d.year()
              << ',' << d.month()
              << ',' << d.day() 
              << ')';
}

//------------------------------------------------------------------------------

istream& operator>>(istream& is, Date& dd)
{
    int y, m, d;
    char ch1, ch2, ch3, ch4;
    is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
    if (!is) return is;
    if (ch1!='(' || ch2!=',' || ch3!=',' || ch4!=')') { // oops: format error
        is.clear(ios_base::failbit);                    // set the fail bit
        return is;
    }
    dd = Date(y,Date::Month(m),d);     // update dd
    return is;
}

//------------------------------------------------------------------------------
//MY CODE, edited this function
Date::Day Date::day_of_week()
{
    // ...
	int x;
	x = m;
	
	int calc_day_of_week=0;
	int inside_parenth=0;
	int century = 0;
	int year_of_century = 0;
	
	if (m == jan)
	{
		x = 13;
		subtract_year(y);
	}
	else if (m == feb)
	{
		x = 14;
		subtract_year(y);
	}
	else
	{
		x = m;
	}
	
	century = y/100;
	year_of_century = y%100;
	inside_parenth= ((x+1)*13)/5;
	
	calc_day_of_week = (year_of_century/4)+(century/4);
	calc_day_of_week = calc_day_of_week+ 5*century + year_of_century;
	calc_day_of_week = calc_day_of_week + inside_parenth;
	calc_day_of_week = calc_day_of_week + d;
	calc_day_of_week = calc_day_of_week%7;
	
	switch(calc_day_of_week)
	{
		case 0:
			return saturday;
			break;
		case 1:
			return sunday;
			break;
		case 2:
			return monday;
			break;
		case 3:
			return tuesday;
			break;
		case 4:
			return wednesday;
			break;
		case 5:
			return thursday;
			break;
		case 6:
			return friday;
			break;
	}
	
}

//------------------------------------------------------------------------------

Date next_Sunday(const Date& d)
{
    // ...
    return d;
}

//------------------------------------------------------------------------------

Date next_weekday(const Date& d)
{
    // ...
    return d;
}


//------------------------------------------------------------------------------

} // Chrono

//------------------------------------------------------------------------------

