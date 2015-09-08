#include "Tags.h"
#include <FL/Fl_Shared_Image.H>
using namespace Graph_lib;

//------------------------------------------------------------------------------

Tags::Tags tags;

//Initializing an empty Picture type to use
Picture pict_grab(" ", " ", " ", " ", " ", " ");

//Construct for picture window class
//This sets the placement of all widgets, attaches widgets to screen, hides unwanted widgets
//It also reads in images previously stored, checks tags, and adds tags to a vector to be displayed later
picture_window::picture_window(Point xy, int w, int h, const string& title) :
    Window(xy,w,h,title),
   //Button placement
		upload_file_button(Point(x_max()/2-160,y_max()/2+0), 150, 40, "Upload from file", cb_upload_file),
		upload_web_button(Point(x_max()/2,y_max()/2+0), 150, 40, "Upload from web", cb_upload_web),
		next_all_button(Point(x_max()-50, y_max()/2-20), 40, 40, "Next", cb_next_all),
		previous_all_button(Point(10, y_max()/2-20), 40, 40, "Prev.", cb_previous_all), 
		next_tag_button(Point(x_max()-50, y_max()/2-20), 40, 40, "Next", cb_next_tag),
		previous_tag_button(Point(10, y_max()/2-20), 40, 40, "Prev.", cb_previous_tag),
		browse_all_button(Point(x_max()/2-110, y_max()/2+50), 100, 40, "Browse All", cb_all_br),
		browse_tags_button(Point(x_max()/2, y_max()/2+50), 100, 40, "Browse Tags", cb_tags_br),
		//start_button(Point(x_max()/2-50, y_max()/2-20), 100, 40, "Start", cb_start),
		menu_button(Point(x_max()-160, 0), 70, 20, "Menu", cb_menu),
		quit_button(Point(x_max()-80, 0), 70, 20, "Quit", cb_quit),
	//Input/Output Box placements		
		tags_out(Point(x_max()/2-125, y_max()-40), 250, 30, "Tags: "),
		error_disp(Point(x_max()/2-125, y_max()-40), 300, 30, "Status Display: "),
		
		tags_in_1(Point(x_max()/6-50, y_max()-300), 100, 30, "Tags: "),
		tags_in_2(Point(x_max()/3-50, y_max()-300), 100, 30, " "),
		tags_in_3(Point(x_max()/2-50, y_max()-300), 100, 30, " "),
		tags_in_4(Point(x_max()*2/3-50, y_max()-300), 100, 30, " "),
		tags_in_5(Point(x_max()*5/6-50, y_max()-300), 100, 30, " "),
		
		filename_box(Point(x_max()/2-200, y_max()/2-130), 200, 30, "File name: "),
		
		url_box(Point(x_max()/2+60, y_max()/2-130), 200, 30, "URL: "),
		
	//initial window attachments
    button_pushed(false)
{	
	//attach(start_button);
	attach(quit_button);
	attach(menu_button);
	attach(browse_all_button);
	browse_all_button.hide();
	attach(browse_tags_button);
	browse_tags_button.hide();
	attach(upload_file_button);
	upload_file_button.hide();
	attach(upload_web_button);
	upload_web_button.hide();
	attach(next_all_button);
	next_all_button.hide();
	attach(previous_all_button);
	previous_all_button.hide();
	attach(next_tag_button);
	next_tag_button.hide();
	attach(previous_tag_button);
	previous_tag_button.hide();
	
	
	attach(tags_in_1);
	tags_in_1.hide();
	attach(tags_in_2);
	tags_in_2.hide();
	attach(tags_in_3);
	tags_in_3.hide();
	attach(tags_in_4);
	tags_in_4.hide();
	attach(tags_in_5);
	tags_in_5.hide();
	
	attach(filename_box);
	filename_box.hide();
	attach(url_box);
	url_box.hide();
	
	attach(tags_out);
	tags_out.hide();
	attach(error_disp);
	error_disp.hide();
	
	attach(start);

	Picture_List=pict_grab.read();
	for(int x=0;x<Picture_List.size();x++)
		check_tags_tags(Picture_List[x].get_filename(), 
						Picture_List[x].get_Family(), 
						Picture_List[x].get_Friends(), 
						Picture_List[x].get_Aggieland(), 
						Picture_List[x].get_Pets(), 
						Picture_List[x].get_Vacation());
	pict_grab.store_for_display(Picture_List, Tags_Display);
}

//------------------------------------------------------------------------------

bool picture_window::wait_for_button()
// modified event loop:
// handle all events (as per default), quit when button_pushed becomes true
// this allows graphics without control inversion
{
    show();
    button_pushed = false;	
	
#if 1
    // Simpler handler
    while (!button_pushed) Fl::wait();
    Fl::redraw();
	
#else
    // To handle the case where the user presses the X button in the window frame
    // to kill the application, change the condition to 0 to enable this branch.
    Fl::run();
#endif
    return button_pushed;
}


//------------------------------------------------------------------------------

//Callback for quit button, exits window
void picture_window::cb_quit(Address, Address pw)
	{
		reference_to<picture_window>(pw).quit();
	}

void picture_window::quit()
{
	button_pushed = true;
	hide();
}

//Callback for menu button, displays the initial main menu arrangement when clicked
//Allows for user to return to central screen when they're finished browsing through images
void picture_window::cb_menu(Address, Address pw)
	{
		reference_to<picture_window>(pw).menu();
	}
	
void picture_window::menu()
{
	button_pushed = true;
	//attach and hide stuff not associated with the main menu
	detach(start);
	redraw();
	next_all_button.hide();
	previous_all_button.hide();
	next_tag_button.hide();
	previous_tag_button.hide();
	upload_file_button.show();
	upload_web_button.show();
	browse_all_button.show();
	browse_tags_button.show();
	filename_box.show();
	url_box.show();
	tags_in_1.show();
	tags_in_2.show();
	tags_in_3.show();
	tags_in_4.show();
	tags_in_5.show();
	error_disp.show();
	tags_out.hide();
	for(int x=0;x<image.size();x++)
		detach(image[x]);
}

//------------------------------------------------------------------------------
//Upload from file
//A portion of the main menu
//This callback takes in the strings typed by the user, checks to make sure the proper file extension is used, then saves the picture to the Picture_List vector, saves the filename to the filename_list vector, stores the picture and separates its tags, then checks tags
//If the user inputs the wrong extension, an error message is displayed to the screen and allows the user to try typing again
void picture_window::cb_upload_file(Address, Address pw)
	{
		reference_to<picture_window>(pw).upload_file();
	}
void picture_window::upload_file()
{	
	button_pushed = true;
	
	//Get strings
	string file_name = filename_box.get_string();
	string tag_1 = tags_in_1.get_string();
	string tag_2 = tags_in_2.get_string();
	string tag_3 = tags_in_3.get_string();
	string tag_4 = tags_in_4.get_string();
	string tag_5 = tags_in_5.get_string();
	
	//Put in vector
	if (file_name.substr(file_name.size()-4) == ".jpg" || file_name.substr(file_name.size()-4) == ".JPG" || 
		file_name.substr(file_name.size()-4) == ".gif" || file_name.substr(file_name.size()-4) == ".GIF" || 
		file_name.substr(file_name.size()-5) == ".jpeg" || file_name.substr(file_name.size()-5) == ".JPEG"|| 
		file_name.substr(file_name.size()-4) == ".png" || file_name.substr(file_name.size()-4) == ".PNG"|| 
		file_name.substr(file_name.size()-4) == ".bmp" || file_name.substr(file_name.size()-4) == ".BMP") 
		{
		Picture_List.push_back(Picture(file_name, tag_1, tag_2, tag_3, tag_4, tag_5));		
		filename_list.push_back(file_name);
		pict_grab.store(Picture_List);
		pict_grab.store_for_display(Picture_List, Tags_Display);
		check_tags_tags(file_name, tag_1, tag_2, tag_3, tag_4, tag_5);
		error_disp.put("File uploaded to directory.");
	}
	else {
		error_disp.put("File type is not supported please try again.");
	}	
}
//------------------------------------------------------------------------------
//Upload from web
//A portion of the main menu
//This callback takes a URL, file name and tags for a picture, checks to make sure the proper file extension is used, then saves the picture to the Picture_List vector, saves the filename to the filename_list vector, stores the picture and separates its tags, then checks tags
//If the user inputs the wrong extension, an error message is displayed to the screen and allows the user to try typing again
void picture_window::cb_upload_web(Address, Address pw)
	{
		reference_to<picture_window>(pw).upload_web();
	}
void picture_window::upload_web()
{	
	button_pushed = true;
	//Get strings
	string file_name = filename_box.get_string();
	string url_name = url_box.get_string();
	string tag_1 = tags_in_1.get_string();
	string tag_2 = tags_in_2.get_string();
	string tag_3 = tags_in_3.get_string();
	string tag_4 = tags_in_4.get_string();
	string tag_5 = tags_in_5.get_string();
	
	system((string("wget ") + url_name + " -O " + file_name).c_str());
	
	//Put in vector
	if (file_name.substr(file_name.size()-4) == ".jpg" || file_name.substr(file_name.size()-4) == ".JPG" || 
		file_name.substr(file_name.size()-4) == ".gif" || file_name.substr(file_name.size()-4) == ".GIF" || 
		file_name.substr(file_name.size()-5) == ".jpeg" || file_name.substr(file_name.size()-5) == ".JPEG"|| 
		file_name.substr(file_name.size()-4) == ".png" || file_name.substr(file_name.size()-4) == ".PNG"|| 
		file_name.substr(file_name.size()-4) == ".bmp" || file_name.substr(file_name.size()-4) == ".BMP") 
		{
		Picture_List.push_back(Picture(file_name, tag_1, tag_2, tag_3, tag_4, tag_5));		
		filename_list.push_back(file_name);
		pict_grab.store(Picture_List);
		pict_grab.store_for_display(Picture_List, Tags_Display);
		check_tags_tags(file_name, tag_1, tag_2, tag_3, tag_4, tag_5);
		error_disp.put("File uploaded to directory.");
	}
	else {
		error_disp.put("File type is not supported please try again.");
	}	
}

//------------------------------------------------------------------------------
//Browsing all
//Callback for the browse all button
//This opens a new arrangement of buttons for browsing pictures
void picture_window::cb_all_br(Address, Address pw)
	{
		reference_to<picture_window>(pw).browse_all();
	}
void picture_window::browse_all()
{
	tags_out.put(" ");
	button_pushed = true;
	detach(start);
	redraw();
	//show the next and previous buttons
	next_all_button.show();
	previous_all_button.show();
	//hide the other buttons and boxes that aren't needed
	browse_all_button.hide();
	browse_tags_button.hide();
	upload_file_button.hide();
	upload_web_button.hide();
	filename_box.hide();
	url_box.hide();
	
	tags_in_1.hide();
	tags_in_2.hide();
	tags_in_3.hide();
	tags_in_4.hide();
	tags_in_5.hide();
	
	tags_out.show();
	error_disp.hide();
	
	//Setting variable used in for loop to browse 
	next_all_x=-1;
	
}

//------------------------------------------------------------------------------
//Browsing tags
//Callback for the browse by tags button
//This opens a new arrangement of buttons for browsing pictures
void picture_window::cb_tags_br(Address, Address pw)
	{
		reference_to<picture_window>(pw).browse_tags();
	}
void picture_window::browse_tags()
{	
	tags_out.put(" ");
	detach(start);
	redraw();
	button_pushed = true;
	//get the tag strings to search with
	string tag_1 = tags_in_1.get_string();
	string tag_2 = tags_in_2.get_string();
	string tag_3 = tags_in_3.get_string();
	string tag_4 = tags_in_4.get_string();
	string tag_5 = tags_in_5.get_string();
	//show the next and previous buttons
	next_tag_button.show();
	previous_tag_button.show();
	//hide the other buttons and boxes that aren't needed
	browse_all_button.hide();
	browse_tags_button.hide();
	upload_file_button.hide();
	upload_web_button.hide();
	filename_box.hide();
	url_box.hide();
	
	//tag output stream
	ostringstream out_tags;
	out_tags<<tag_1<<" , "<<tag_2<<" , "<<tag_3<<" , "<<tag_4<<" , "<<tag_5;
	
	tags_in_1.hide();
	tags_in_2.hide();
	tags_in_3.hide();
	tags_in_4.hide();
	tags_in_5.hide();
	
	error_disp.hide();
	tags_out.show();
	
	add_Tags_List(tag_1,tag_2,tag_3,tag_4,tag_5);	
	redraw();
	
	//Setting variable used in for loop to browse 
	next_all_x=-1;
}	

//------------------------------------------------------------------------------
//This block is the callback block to navigate through display
//It has all the callbacks for the "next" and "previous" buttons on our browse screens
void picture_window::cb_next_all(Address, Address pw)
	{
		reference_to<picture_window>(pw).next_all();
	}

void picture_window::next_all()
{
	next_image(Picture_List);	
}

void picture_window::cb_previous_all(Address, Address pw)
	{
		reference_to<picture_window>(pw).previous_all();
	}

void picture_window::previous_all()
{
	previous_image(Picture_List);	
}

void picture_window::cb_next_tag(Address, Address pw)
	{
		reference_to<picture_window>(pw).next_tag();
	}

void picture_window::next_tag()
{	
	next_image(Tags_Picture_List);
}

void picture_window::cb_previous_tag(Address, Address pw)
	{
		reference_to<picture_window>(pw).previous_tag();
	}

void picture_window::previous_tag()
{
	previous_image(Tags_Picture_List);
}

//------------------------------------------------------------------------------
//This block is to navigate through the display using the next and previous buttons

//Removes previous images from the screen and increments the counter
//If it's at the end of the vector of images, it restarts
//Clears vector_ref and pushes back new images to be displayed
//Outputs tags and displays images
//Redraws page
void picture_window::next_image(vector<Picture> pic)
{	
	for(int x=0;x<image.size();x++)		//remove the last image
		detach(image[x]);
	next_all_x++;
	
	if(next_all_x==pic.size()) 		//image vector tracker
		next_all_x=0;		
	image.clear();
	image.push_back(new Image(Point{x_max()/2,y_max()/2},pic[next_all_x].get_filename()));		 
	tags_out.put(pic[next_all_x].tags());
	
	attach(image[0]);

	redraw();
	button_pushed = true;		
}

//Removes previous images from the screen and increments the counter
//If it's at the end of the vector of images, it restarts
//Clears vector_ref and pushes back new images to be displayed
//Outputs tags and displays images
//Redraws page
void picture_window::previous_image(vector<Picture> pic)
{	
	for(int x=0;x<image.size();x++)		//remove the last image
		detach(image[x]);
	next_all_x--;
	
	if(next_all_x<0) 
		next_all_x=pic.size()-1;		
	if(next_all_x==pic.size())
		next_all_x=pic.size()-1;
		
	image.clear();
	image.push_back(new Image(Point{x_max()/2,y_max()/2},pic[next_all_x].get_filename()));		 
	
	tags_out.put(pic[next_all_x].tags());
	
	attach(image[0]);
	redraw();
	
	button_pushed = true;
}

//------------------------------------------------------------------------------
//Everything from here down is to put tags in the correct order.
void picture_window::add_Tags_List(string a, string b, string c, string d, string e)	
{
	Picture p(" ", " ", " ", " ", " ", " ");
	string familys=p.family(a,b,c,d,e);
	string friendss=p.friends(a,b,c,d,e);
	string aggies=p.aggie(a,b,c,d,e);
	string petss=p.pets(a,b,c,d,e);
	string vacations=p.vacation(a,b,c,d,e);
	Tags_Picture_List=tags.get_Pic_Vec_Mul(familys,friendss,aggies,petss,vacations);
}

void picture_window::check_tags_tags(string name, string a, string b, string c, string d, string e)	
{
	Picture p(" ", " ", " ", " ", " ", " ");
	string familys=p.family(a,b,c,d,e);
	string friendss=p.friends(a,b,c,d,e);
	string aggies=p.aggie(a,b,c,d,e);
	string petss=p.pets(a,b,c,d,e);
	string vacations=p.vacation(a,b,c,d,e);
	tags.check_tags(Picture(name, familys, friendss, aggies, petss, vacations));
}