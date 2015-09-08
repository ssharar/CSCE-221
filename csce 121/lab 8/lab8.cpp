
//
// This is example code from Chapter 16.5 "An example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <sstream>
#include "Graph.h"        // get access to our graphics library facilities
#include "GUI.h"
#include "Window.h"

using namespace Graph_lib;
using namespace std;

//------------------------------------------------------------------------------

struct Lines_window : Graph_lib::Window {
    Lines_window(Point xy, int w, int h, const string& title );

private:
    Button button_x1;
	Button button1;
	Button button_x2;
    Button button2;
    Button button_x3;
	Button button3;
	Button button_x4;
    Button button4;
    Button button_x5;
	Button button5;
	Button button_x6;
    Button button6;
	Button button_x7;
    Button button7;
    Button button_x8;
	Button button8;
	Button button_x9;
    Button button9;
	
    Button quit_button;

    static void cb_bx(Address, Address);
    void bx();
	static void cb_b1(Address, Address);
    void b1();
	static void cb_b2(Address, Address);
    void b2();
	static void cb_b3(Address, Address);
    void b3();
	static void cb_b4(Address, Address);
    void b4();
	static void cb_b5(Address, Address);
    void b5();
	static void cb_b6(Address, Address);
    void b6();
	static void cb_b7(Address, Address);
    void b7();
	static void cb_b8(Address, Address);
    void b8();
	static void cb_b9(Address, Address);
    void b9();
    static void cb_quit(Address, Address);
    void quit(); 
};

//------------------------------------------------------------------------------

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
    :Window(xy,w,h,title),
	button_x1(Point(0,0), 100, 100, "X", cb_bx),
    button1(Point(0,0), 100, 100, " ", cb_b1),
	button_x2(Point(100,0), 100, 100, "X", cb_bx),
	button2(Point(100,0), 100, 100, " ", cb_b2),
	button_x3(Point(200,0), 100, 100, "X", cb_bx),
	button3(Point(200,0), 100, 100, " ", cb_b3),
	button_x4(Point(0,100), 100, 100, "X", cb_bx),
    button4(Point(0,100), 100, 100, " ", cb_b4),
	button_x5(Point(100,100), 100, 100, "X", cb_bx),
	button5(Point(100,100), 100, 100, " ", cb_b5),
	button_x6(Point(200,100), 100, 100, "X", cb_bx),
	button6(Point(200,100), 100, 100, " ", cb_b6),
	button_x7(Point(0,200), 100, 100, "X", cb_bx),
    button7(Point(0,200), 100, 100, " ", cb_b7),
	button_x8(Point(100,200), 100, 100, "X", cb_bx),
	button8(Point(100,200), 100, 100, " ", cb_b8),
	button_x9(Point(200,200), 100, 100, "X", cb_bx),
	button9(Point(200,200), 100, 100, " ", cb_b9),
    quit_button(Point(x_max()-70,0), 70, 20, "Quit", cb_quit)
    
{
    attach(button1);
	attach(button2);
	attach(button3);
	attach(button4);
	attach(button5);
	attach(button6);
	attach(button7);
	attach(button8);
	attach(button9);
	
    attach(quit_button);
}

//------------------------------------------------------------------------------

void Lines_window::cb_quit(Address, Address pw)    // "the usual"
{  
       reference_to<Lines_window>(pw).quit();
} 

//------------------------------------------------------------------------------

void Lines_window::quit()
{
    hide();        // curious FLTK idiom for delete window
}

//------------------------------------------------------------------------------

void Lines_window::cb_bx(Address, Address pw)     // "the usual"
{  
    reference_to<Lines_window>(pw).bx();
} 

//------------------------------------------------------------------------------

void Lines_window::bx()
{
   
}

//------------------------------------------------------------------------------


void Lines_window::cb_b1(Address, Address pw)     // "the usual"
{  
    reference_to<Lines_window>(pw).b1();
} 

//------------------------------------------------------------------------------

void Lines_window::b1()
{
  detach(button1);
  attach(button_x1);
  cout <<"yo";
}

//------------------------------------------------------------------------------


void Lines_window::cb_b2(Address, Address pw)     // "the usual"
{  
    reference_to<Lines_window>(pw).b2();
} 

//------------------------------------------------------------------------------

void Lines_window::b2()
{
   detach(button2);
   attach(button_x2);
}

//------------------------------------------------------------------------------

void Lines_window::cb_b3(Address, Address pw)     // "the usual"
{  
    reference_to<Lines_window>(pw).b3();
} 

//------------------------------------------------------------------------------

void Lines_window::b3()
{
   detach(button3);
   attach(button_x3);
}

//------------------------------------------------------------------------------

void Lines_window::cb_b4(Address, Address pw)     // "the usual"
{  
    reference_to<Lines_window>(pw).b4();
} 

//------------------------------------------------------------------------------

void Lines_window::b4()
{
   detach(button4);
   attach(button_x4);
}

//------------------------------------------------------------------------------

void Lines_window::cb_b5(Address, Address pw)     // "the usual"
{  
    reference_to<Lines_window>(pw).b5();
} 

//------------------------------------------------------------------------------

void Lines_window::b5()
{
   detach(button5);
   attach(button_x5);
}

//------------------------------------------------------------------------------

void Lines_window::cb_b6(Address, Address pw)     // "the usual"
{  
    reference_to<Lines_window>(pw).b6();
} 

//------------------------------------------------------------------------------

void Lines_window::b6()
{
   detach(button6);
   attach(button_x6);
}
//------------------------------------------------------------------------------

void Lines_window::cb_b7(Address, Address pw)     // "the usual"
{  
    reference_to<Lines_window>(pw).b7();
} 

//------------------------------------------------------------------------------

void Lines_window::b7()
{
   detach(button7);
   attach(button_x7);
}

//------------------------------------------------------------------------------

void Lines_window::cb_b8(Address, Address pw)     // "the usual"
{  
    reference_to<Lines_window>(pw).b8();
} 

//------------------------------------------------------------------------------

void Lines_window::b8()
{
   detach(button8);
   attach(button_x8);
}

//------------------------------------------------------------------------------

void Lines_window::cb_b9(Address, Address pw)     // "the usual"
{  
    reference_to<Lines_window>(pw).b9();
} 

//------------------------------------------------------------------------------

void Lines_window::b9()
{
   detach(button9);
   attach(button_x9);
}

//------------------------------------------------------------------------------


int main()
try {
    Lines_window win(Point(100,100),370,300,"lines");
    return gui_main();
}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    cerr << "Some exception\n";
    return 2;
}

//------------------------------------------------------------------------------
