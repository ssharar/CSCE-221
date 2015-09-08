//Shaeeta Sharar
//CSCE 121 Section 508
//Due: October 26st, 2014
//ssharar_hw7pr2.cpp

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
		
		//Declaring top left corner & creating a window:
		Point top_left {100,100};
		
		Simple_window canvas {top_left, 600, 500, "Canvas"};
		
		//Creating the house:
		//House Base
		//	sets size, location, and color
		Closed_polyline base;
		base.add(Point{200,180});
		base.add(Point{200,400});
		base.add(Point{400,400});
		base.add(Point{400,180});
		Rectangle side {Point{100,301}, 100, 100};
		Rectangle garage {Point{400,301}, 100, 100};
		base.set_fill_color(Color::white);
		garage.set_fill_color(Color::white);	
		side.set_fill_color(Color::white);	
		
		//Door, door knob, garage door
		//	sets size, location, and color
		Rectangle door {Point{230,300}, 50, 100};
		Circle door_knob {Point{270,360},3};
		
		Rectangle garage_door {Point{410,320}, 80, 80};
		
		door.set_fill_color(Color::red);
		door_knob.set_fill_color(Color::white);
		door_knob.set_color(Color::white);
		
		//Windows
		//	sets size, location, and color
		Rectangle win1 {Point{110,320}, 80, 60};
		Rectangle win2 {Point{310,300}, 65, 80};
		Circle buttercup {Point{245,240},22};
		Circle blossom {Point{300,240},22};
		Circle bubbles {Point{355,240},22};
		
		win1.set_fill_color(Color::cyan);
		win2.set_fill_color(Color::cyan);
		blossom.set_fill_color(Color::magenta);
		bubbles.set_fill_color(Color::blue);	
		buttercup.set_fill_color(Color::green);
		
		//Trees, bluebird!
		//	sets size, location, and color
		Circle tree1 {Point{345,387},15};
		Circle tree2 {Point{310,387},15};
		Circle tree3 {Point{380,387},15};
		
		tree1.set_color(Color::green);
		tree2.set_color(Color::green);
		tree3.set_color(Color::green);
		
		tree1.set_fill_color(Color::green);
		tree2.set_fill_color(Color::green);
		tree3.set_fill_color(Color::green);	
		
		Circle bird_body {Point{380,380},5};
		Circle bird_head {Point{377,377},3};
		Polygon beak;
		beak.add(Point{377,377});
		beak.add(Point{377,379});
		beak.add(Point{375,378});
		
		bird_body.set_fill_color(Color::blue);
		bird_head.set_fill_color(Color::blue);
		beak.set_fill_color(Color::yellow);
		
		//Output to screen:
		//Attaching shapes to window	
		canvas.attach(base);
		canvas.attach(side);
		canvas.attach(garage);
		canvas.attach(door);
		canvas.attach(door_knob);
		canvas.attach(garage_door);
		canvas.attach(win1);
		canvas.attach(win2);
		canvas.attach(blossom);
		canvas.attach(bubbles);
		canvas.attach(buttercup);
		canvas.attach(tree1);
		canvas.attach(tree2);
		canvas.attach(tree3);
		canvas.attach(bird_body);
		canvas.attach(bird_head);
		canvas.attach(beak);
		
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