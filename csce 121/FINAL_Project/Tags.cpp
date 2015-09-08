#include "std_lib_facilities_4.h"
#include "Graph.h"
#include "Tags.h"

	
using namespace std;
using namespace Pictures;
namespace Tags {

//------------------------------------------------------------------------------
	Tags::Tags()
	{
		
	}
	
	vector<Picture> Tags::get_Picture_Vector(string a)//Return a vector of images of the tags
	{
		if(a=="Family")
			return Family;
		if(a=="Friends")
			return Friends;
		if(a=="Aggieland")
			return Aggieland;
		if(a=="Pets")
			return Pets;
		if(a=="Vacation")
			return Vacation;
	}	
	
//------------------------------------------------------------------------------
//This block is use to check for multiple tags
	bool Tags::for_more_tags_tags(vector<string> name, Picture p)
	{
		bool more;
		for(int x=0;x<name.size();x++)
		{
			if(for_more_tags(name[x],p))
				more=true;
			else 
			{
				more =false;
				break;
			}
		}
		return more;
	}

//Returns if certain tag is used	
	bool Tags::for_more_tags(string a, Picture p)
	{
		if(a=="Aggieland")
			return p.get_Aggieland_bool();
		else if(a=="Friends")
			return p.get_Friends_bool();
		else if(a=="Family")
			return p.get_Family_bool();
		else if(a=="Pets")
			return p.get_Pets_bool();
		else if(a=="Vacation")
			return p.get_Vacation_bool();
		else return false;
	}
//------------------------------------------------------------------------------

	vector<Picture> Tags::get_Pic_Vec_Mul(string a, string b, string c, string d, string e/*, Picture pic*/)
	{
		vector<Picture> out;
		vector<Picture> out_tags_plus;;
		vector<string> in;
		if(a!="")in.push_back(a);
		if(b!="")in.push_back(b);
		if(c!="")in.push_back(c);
		if(d!="")in.push_back(d);
		if(e!="")in.push_back(e);
		
		int var=0;//This is how many argument is entered.
		
		while(var<in.size())//Loop to put tags picture in out
		{		
			for(int x=0;x<get_Picture_Vector(in[var]).size();x++)
			{
				out.push_back(get_Picture_Vector(in[var])[x]);
			}
			var++;
		}
		
		if(in.size()>1)//if more then 1 tags
		{
			for(int x=0;x<out.size();x++)//this is to go through the pic vector of all tags
			{
				if(for_more_tags_tags(in,out[x]))
					out_tags_plus.push_back(out[x]);				
			}			
		}
		if(in.size()==1)
			return out;
		else return out_tags_plus;
	}	
	
	void Tags::check_tags(Picture pic)//use to push_back tags in to different vector
	{	
		if(pic.get_Family_bool())
			Family.push_back(pic);
		if(pic.get_Friends_bool())
			Friends.push_back(pic);
		if(pic.get_Aggieland_bool())
			Aggieland.push_back(pic);
		if(pic.get_Pets_bool())
			Pets.push_back(pic);
		if(pic.get_Vacation_bool())
			Vacation.push_back(pic);	
	}
	
	
	
}