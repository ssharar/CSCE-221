//Shaeeta Sharar
//CSCE 121 Section 508
//Due: October 26st, 2014
//ssharar_hw7pr1.cpp

#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"
#include "GUI.h"
#include "Point.h"
#include "Window.h"

using namespace Graph_lib;


int main()
{
	//Error Check
	//Runs program until it's finished or error is found
	//Goes through catch to find source of error
	//If error is found tells user of error before quitting
	try {
		
		//Declaring top left corner:
		Point top_left {100,100};
		
		Simple_window canvas {top_left, 400, 400, "Canvas"};
		
		//1st initial "S"
		//	Uses 3 lines to draw letter "S"
		Line S1(Point(80,100),Point(200,200));
		Line S2(Point(80,100),Point(200,50));
		Line S3(Point(80,260),Point(200,200));
		
		//2nd initial "S"
		//	Uses 3 lines to draw letter "S"
		Line S2_1(Point(180,150),Point(300,250));
		Line S2_2(Point(180,150),Point(300,100));
		Line S2_3(Point(180,310),Point(300,250));
		
		//Setting Line Widths and Colors
		//	sets each line to a thick width of 4px
		//	sets color to 1st initial lines
		S1.set_style(Line_style(Line_style::solid, 4));
		S2.set_style(Line_style(Line_style::solid, 4));
		S3.set_style(Line_style(Line_style::solid, 4));
		
		S2_1.set_style(Line_style(Line_style::solid, 4));
		S2_2.set_style(Line_style(Line_style::solid, 4));
		S2_3.set_style(Line_style(Line_style::solid, 4));
		
		S1.set_color(Color::magenta);
		S2.set_color(Color::magenta);
		S3.set_color(Color::magenta);
		
		//Output to screen:
		//Attaching shapes to window
		canvas.attach(S1);
		canvas.attach(S2);
		canvas.attach(S3);
		canvas.attach(S2_1);
		canvas.attach(S2_2);
		canvas.attach(S2_3);
		
		//Waiting for person to enter to close window
		canvas.wait_for_button();
		
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