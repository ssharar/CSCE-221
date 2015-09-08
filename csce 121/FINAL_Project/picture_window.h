
#ifndef SIMPLE_WINDOW_GUARD
#define SIMPLE_WINDOW_GUARD 1

#include "GUI.h"    
#include "Graph.h"
#include "Picture.h"
using namespace Graph_lib;
using namespace Pictures;
//------------------------------------------------------------------------------

struct picture_window : Graph_lib::Window {
    picture_window(Point xy, int w, int h, const string& title );

	//Declaring all components of picture_window including variables and callbacks for buttons	
	Button upload_file_button;
	Button upload_web_button;
	In_box filename_box;
	Out_box tags_out;
	Out_box error_disp;
	In_box tags_in_1;
	In_box tags_in_2;
	In_box tags_in_3;
	In_box tags_in_4;
	In_box tags_in_5;
	In_box url_box;
	Button next_all_button;
	Button previous_all_button;
	Button next_tag_button;
	Button previous_tag_button;
	Button browse_all_button;
	Button browse_tags_button;
	
    bool wait_for_button(); // simple event loop
	
	Image start {Point{x_max()/2,y_max()/2}, "start.jpg"};
	
	vector<Picture> Picture_List;
	vector<String> filename_list;
	vector<String> Tags_Display;
	vector<Picture> Tags_Picture_List;
	Vector_ref<Image> image;

private:
    Button menu_button;
	Button quit_button;	
	
	int next_all_x=-1;
	
    bool button_pushed;     // implementation detail

    static void cb_all_br(Address, Address window);
    void browse_all();           
	static void cb_quit(Address, Address window); 
	void quit();
	static void cb_upload_file(Address, Address window);
	void upload_file();
	static void cb_upload_web(Address, Address window);
	void upload_web();
	static void cb_tags_br(Address, Address window);
	void browse_tags();
	static void cb_next_all(Address, Address window);
	void next_all();
	static void cb_previous_all(Address, Address window);
	void previous_all();
	static void cb_next_tag(Address, Address window);
	void next_tag();
	static void cb_previous_tag(Address, Address window);
	void previous_tag();
	static void cb_menu(Address, Address window);
	void menu();
	
	void next_image(vector<Picture> pic);
	void previous_image(vector<Picture> pic);
	/*static void cb_start(Address, Address window);
	void start();*/
	
	
	string family(string a, string b, string c, string d, string e);
	string friends(string a, string b, string c, string d, string e);
	string aggie(string a, string b, string c, string d, string e);
	string pets(string a, string b, string c, string d, string e);
	string vacation(string a, string b, string c, string d, string e);

	void add_Tags_List(string a, string b, string c, string d, string e)	;
	void check_tags_tags(string name, string a, string b, string c, string d, string e);
	
	
};

//------------------------------------------------------------------------------

#endif // SIMPLE_WINDOW_GUARD
