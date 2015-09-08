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
		
		Simple_window canvas {top_left, 800, 800, "Canvas"};
		
		
		Smiley x (Point{200,200}, 100);
		
		canvas.attach(x.smile1);
		canvas.attach(x.eye1);
		canvas.attach(x.eye2);
		canvas.attach(x);

		Frowny y (Point{600,200}, 100);
		
		canvas.attach(y.smile1);
		canvas.attach(y.eye1);
		canvas.attach(y.eye2);
		canvas.attach(y);
		
		S_Hat a (Point{200,500}, 100);
		
		canvas.attach(a.party_hat);
		canvas.attach(a.smile1);
		canvas.attach(a.eye1);
		canvas.attach(a.eye2);
		canvas.attach(a);
		
		F_Hat b (Point{600,500}, 100);
		
		canvas.attach(b.feather);
		canvas.attach(b.party_hat);
		canvas.attach(b.smile1);
		canvas.attach(b.eye1);
		canvas.attach(b.eye2);
		canvas.attach(b);
		
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