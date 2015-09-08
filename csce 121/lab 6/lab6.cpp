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
		
		Simple_window canvas {top_left, 800, 1000, "Canvas"};
		
		
		//Grid
		//8x8 grid on top 800x800 square
		//	get size of window and sizes of squares
		//	use for loop to create grid
		//	attaches grid to window
		int x_max = 800;
		int y_max = 800;
		int x_size = 100;
		int y_size = 100;
		
		Lines grid;
		for (int x= x_size; x<=x_max; x = x+x_size)
		{
			grid.add(Point{x,0},Point{x,y_max});
		}
		for (int y=y_size; y<=y_max; y = y+y_size)
		{
			grid.add(Point{0,y},Point{x_max,y});
		}
		canvas.attach(grid);
		
		//Red squares
		//	creates 8 squares, places them, and fills them with red
		//	attaches squares to window
		Rectangle s1 {Point{1,1}, 100, 100};
		s1.set_fill_color(Color::red);
		
		Rectangle s2 {Point{100,100}, 100, 100};
		s2.set_fill_color(Color::red);
		
		Rectangle s3 {Point{200,200}, 100, 100};
		s3.set_fill_color(Color::red);
		
		Rectangle s4 {Point{300,300}, 100, 100};
		s4.set_fill_color(Color::red);
		
		Rectangle s5 {Point{400,400}, 100, 100};
		s5.set_fill_color(Color::red);
		
		Rectangle s6 {Point{500,500}, 100, 100};
		s6.set_fill_color(Color::red);
		
		Rectangle s7 {Point{600,600}, 100, 100};
		s7.set_fill_color(Color::red);
		
		Rectangle s8 {Point{700,700}, 100, 100};
		s8.set_fill_color(Color::red);
		
		canvas.attach(s1);
		canvas.attach(s2);
		canvas.attach(s3);
		canvas.attach(s4);
		canvas.attach(s5);
		canvas.attach(s6);
		canvas.attach(s7);
		canvas.attach(s8);
				
		//Images
		//	adds 200x200 image and sets location
		//	attaches warios to window
		Image wario1 {Point{300,1}, "wario.jpeg"};
		Image wario2 {Point{400,600}, "wario.jpeg"};
		Image wario3 {Point{1,200}, "wario.jpeg"};
		
		canvas.attach(wario1);
		canvas.attach(wario2);
		canvas.attach(wario3);
		
		//Moving Image
		// 	opens image and attaches to canvas
		//	moves image for a certain number of squares, using the next button as a waiting option
		Image wa {Point{100,1}, "wawawa.jpeg"};
		canvas.attach(wa);
		
		for (int i = 100; i <= 600; i= i+ 100)
		{
			wa.move(100,100);
			canvas.wait_for_button();
			if (i == 600)
			{
					break;
			}
		}
		
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