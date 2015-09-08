/*
   Simple_window.cpp
   Minimally revised for C++11 features of GCC 4.6.3 or later
   Walter C. Daugherity		June 10, 2012
*/

//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

Simple_window::Simple_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
    next_button(Point(x_max()-70,00), 70, 20, "Next", cb_next),
	close_button(Point(x_max()-70,30), 70, 20, "Exit",cb_quit), //Just made this exit button for later use
    button_pushed(false)
{
    attach(next_button);
	attach(close_button);
}

//------------------------------------------------------------------------------

bool Simple_window::wait_for_button()
// modified event loop:
// handle all events (as per default), quit when button_pushed becomes true
// this allows graphics without control inversion
{
    show();
    button_pushed = false;
	#if 1
		// Simpler handler
		while (!button_pushed) 
			Fl::wait();
		Fl::redraw();
	#else
		exit(0);
																						// To handle the case where the user presses the X button in the window frame
																						// to kill the application, change the condition to 0 to enable this branch.
		Fl::run();
	#endif
		return button_pushed;
}

//------------------------------------------------------------------------------
void Simple_window::cb_quit(Address, Address pw)
	// Call Simple_window::quit() for the window located at address pw
{
 	reference_to<Simple_window>(pw).quit();	// now call our function
} 

//------------------------------------------------------------------------------

void Simple_window::cb_next(Address, Address pw)
// call Simple_window::next() for the window located at pw
{  
    reference_to<Simple_window>(pw).next();    
}

//------------------------------------------------------------------------------

void Simple_window::next()
{
    button_pushed = true;
    hide();
}

//------------------------------------------------------------------------------
void Simple_window::quit()
{
	button_pushed = true;
	hide();
	exit(0);
}

//------------------------------------------------------------------------------
