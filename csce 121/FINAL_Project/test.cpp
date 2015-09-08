#include "std_lib_facilities_4.h"
#include "picture_window.h"
#include "Graph.h"
//#include "Picture.h"


using namespace Graph_lib;
//using namespace Pictures;


int main()
try {
  if(H112 != 201401L)error("Error: incorrect std_lib_facilities_4.h version ",
		  	   H112);
	picture_window win1(Point(100,200),600,500,"AggieSnap");
 
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