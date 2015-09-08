#ifndef PICTURE_CLASS_GUARD
#define PICTURE_CLASS_GUARD

#include <iostream>
#include "std_lib_facilities_4.h"
#include "Graph.h"

using namespace Graph_lib;
using namespace std;

//------------------------------------------------------------------------------
	namespace Pictures
	{

	//------------------------------------------------------------------------------
	//This is our picture class
	//This file contains functions which are used in this class for our program
	//The picture class is used to declare our type "Picture" and use this type to add to the index file of our images and tags, to read in the image file for consecutive use, storing tags into a separate vector for display, overriding the cin and cout operators
	
		class Picture 
		{
			public:
				class Invalid { }; 
				Picture(String filename, string Family, string Friends, string Aggieland, string Pets, string Vacation);
				
				string tags() const{ return Family+ " ," +Friends+ " ,"+Aggieland+ " ,"+Pets+ " ,"+Vacation;}	
				string get_filename() const {return filename;}
				string get_Family() const {return Family;}
				string get_Friends() const {return Friends;}
				string get_Aggieland() const {return Aggieland;}
				string get_Pets() const {return Pets;}
				string get_Vacation() const {return Vacation;}
				
				bool get_Aggieland_bool() const 
				{
					if(Aggieland=="Aggieland") return true; 
					else return false;
				}
				bool get_Friends_bool() const 
				{
					if(Friends=="Friends") return true; 
					else return false;
				}
				bool get_Family_bool() const 
				{
					if(Family=="Family") return true; 
					else return false;
				}
				bool get_Pets_bool() const 
				{
					if(Pets=="Pets") return true; 
					else return false;
				}
				bool get_Vacation_bool() const 
				{
					if(Vacation=="Vacation") return true; 
					else return false;
				}
				
				void store(vector<Picture> picture);
				void store_for_display(vector<Picture> pic, vector<String>& display);
				vector<Picture> read();
				
				string family(string a, string b, string c, string d, string e);
				string friends(string a, string b, string c, string d, string e);
				string aggie(string a, string b, string c, string d, string e);
				string pets(string a, string b, string c, string d, string e);
				string vacation(string a, string b, string c, string d, string e);
				
			private:
				string filename;
				string Family;
				string Friends;
				string Aggieland;
				string Pets;
				string Vacation;
		};
		
		ostream& operator<<(ostream& out_s, const Picture& p);
		istream& operator>>(istream& in_s, Picture& pp);
	}
#endif //Picture