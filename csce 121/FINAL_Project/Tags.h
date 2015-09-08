//Team 62
//CSCE 121 Section 508
//Due December 3rd, 2014
//Tags.h


#include <iostream>
#include "std_lib_facilities_4.h"
#include "Graph.h"
#include "picture_window.h"

using namespace std;
using namespace Pictures;
//------------------------------------------------------------------------------

namespace Tags {

//------------------------------------------------------------------------------

	class Tags 
	{
		public:
			class Invalid { };
			
			Tags();
			
			//Declares variables used in this class
			void check_tags(Picture pic);
			vector<Picture> get_Picture_Vector(string a);
			vector<Picture> get_Pic_Vec_Mul(string a, string b, string c, string d, string e/*, Picture pic*/);
			bool for_more_tags(string a , Picture p);
			bool for_more_tags_tags(vector<string> name , Picture p);
			vector<Picture> Family;
			vector<Picture> Friends;
			vector<Picture> Aggieland;
			vector<Picture> Pets;
			vector<Picture> Vacation;
			
			
			
	};
	

}

