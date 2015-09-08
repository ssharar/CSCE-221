
#include <iostream>
#include "Picture.h"
#include "std_lib_facilities_4.h"
#include "Graph.h"

namespace Pictures
{
	
//------------------------------------------------------------------------------

	Picture::Picture(string filename, string Family, string Friends, string Aggieland, string Pets, string Vacation)
		: filename(filename), Family(Family), Friends(Friends), Aggieland(Aggieland), Pets(Pets), Vacation(Vacation)
	{		
	}

//------------------------------------------------------------------------------
//This function is used to store our image files and their respective tags in a text based index file for later viewing
	void Picture::store(vector<Picture> picture)
	{
		//Declaring output stream variable
		ofstream output_file;
		
		//Opens new file
		output_file.open ("picture_index.txt");
		if(!output_file) error("can't open");
		
		//Runs through each element of vector and outputs the contents to the file
		for (int count = 0; count < picture.size(); ++count)
		{
			output_file << picture[count] << endl;
		}
		
		//Closes file
		output_file.close();
	}

//------------------------------------------------------------------------------	
//This vector reads in previously stored files to have a comprehensive database	
	vector<Picture> Picture::read()
	{
		//Declaring variables
		Vector<string> name;
		ifstream input_file;
		vector<Picture> picture;		
		int i=0;
		int k=0;
		
		//Opens picture index file 
		input_file.open ("picture_index.txt");
		if(!input_file) error("can't open");
		
		//Until the end of the file is reached, the function inputs each word parsing at the commas
		//It then erases additional parenthesis
		//Pushes back each word into a vector & increments for the loop
		while(!input_file.eof()) {
			String line;			
			if(i<5) getline(input_file, line, ',');
			if(i==0&&k==0) line.erase(line.begin(),line.begin()+1);
			if(i==0&&k!=0&&line.length()>1) line.erase(line.begin(),line.begin()+2);
			if (i==5) getline(input_file, line, ')');			

			name.push_back(line);
			++i;
			++k;
			if(i==6)	i=0;			
		}		
		
		//A new vector is made to push back the file name and tags of each individual picture as one element
		for (int count1 = 0;  (count1 + 5) < name.size(); count1 = count1+6) {
			Picture p(	name[count1], 
						family(name[count1+1],name[count1+2],name[count1+3],name[count1+4],name[count1+5]), 
						friends(name[count1+1],name[count1+2],name[count1+3],name[count1+4],name[count1+5]), 
						aggie(name[count1+1],name[count1+2],name[count1+3],name[count1+4],name[count1+5]), 
						pets(name[count1+1],name[count1+2],name[count1+3],name[count1+4],name[count1+5]), 
						vacation(name[count1+1],name[count1+2],name[count1+3],name[count1+4],name[count1+5]));
			picture.push_back(p);
		}		
		
		//Closes file and returns the vector
		input_file.close();
		return picture;
	}
	
//------------------------------------------------------------------------------
	string Picture::family(string a, string b, string c, string d, string e)
	{
		string family;
		if(a=="Family") family="Family"; 
		else if(b=="Family") family="Family"; 
		else if(c=="Family") family="Family"; 
		else if(d=="Family") family="Family"; 
		else if(e=="Family") family="Family"; 
		return family;
	}
	string Picture::friends(string a, string b, string c, string d, string e)
	{
		string friends;	
		if(a=="Friends") friends="Friends"; 
		else if(b=="Friends") friends="Friends"; 
		else if(c=="Friends") friends="Friends"; 
		else if(d=="Friends") friends="Friends"; 
		else if(e=="Friends") friends="Friends"; 
		return friends;
	}
	string Picture::aggie(string a, string b, string c, string d, string e)
	{
		string aggie;
		
		if(a=="Aggieland") aggie="Aggieland"; 
		else if(b=="Aggieland") aggie="Aggieland"; 
		else if(c=="Aggieland") aggie="Aggieland"; 
		else if(d=="Aggieland") aggie="Aggieland"; 
		else if(e=="Aggieland") aggie="Aggieland"; 
		return aggie;
	}
	string Picture::pets(string a, string b, string c, string d, string e)
	{
		string pets;
		if(a=="Pets") pets="Pets"; 
		else if(b=="Pets") pets="Pets"; 
		else if(c=="Pets") pets="Pets"; 
		else if(d=="Pets") pets="Pets"; 
		else if(e=="Pets") pets="Pets"; 
		return pets;
	}
	string Picture::vacation(string a, string b, string c, string d, string e)
	{
	string vacation;
	if(a=="Vacation") vacation="Vacation"; 
	else if(b=="Vacation") vacation="Vacation"; 
	else if(c=="Vacation") vacation="Vacation"; 
	else if(d=="Vacation") vacation="Vacation"; 
	else if(e=="Vacation") vacation="Vacation"; 
	return vacation;
}


//------------------------------------------------------------------------------
//This function takes in our Picture vector and takes the tags for each picture in as strings
//It then pushes back these tags into a new vector used to display tags under their respective images
	void Picture::store_for_display(vector<Picture> pic, vector<String>& display)
	{
		//Running through each element of picture vector
		//Taking out each tag and concatenating them into strings then pushing back the string formed into a vector
		for (int count = 0; count < pic.size(); ++count)
		{
			String concatenate;
			concatenate= pic[count].get_Family() + ", "+ pic[count].get_Friends() + ", " + pic[count].get_Aggieland() + ", "+ pic[count].get_Pets() + ", "+ pic[count].get_Vacation();
			display.push_back(concatenate);
		}
	}


//------------------------------------------------------------------------------

// cout for Picture class
// Overrides the "<<" operator so that we can output pictures
	ostream& operator<<(ostream& out_s, const Picture& p)
	{
		return out_s << '(' << p.get_filename() << ',' << p.get_Family() << ',' << p.get_Friends() << ',' << p.get_Aggieland() << ',' << p.get_Pets() << ',' << p.get_Vacation() << ')';
	}


//------------------------------------------------------------------------------

// cin for pictures
// Overrides the ">>" operator so that we can input pictures
	istream& operator>>(istream& in_s, Picture& pp)
	{
		//Declaring strings and chars
		string fl, fam, fri, agl, pet, vac;
		char ch, ch2, ch3, ch4, ch5, ch6, ch7;
		
		//Inputting the chars and strings
		in_s >> ch >> fl >> ch2 >> fam >> ch3 >> fri >> ch4 >> agl >> ch5 >> pet >> ch6 >> vac >> ch7;
		
		//Checking to make sure it is in the right format
		if (!in_s) 
		{
			return in_s;
		}
		
		if (ch!='(' || ch2!=',' || ch3!=',' || ch4!=',' || ch5!=',' || ch6!=',' || ch7!=')') 
		{
			in_s.clear(ios_base::failbit);
			return in_s;
		}
		
		//Setting the inputs to a picture
		pp = Picture(fl,fam,fri,agl,pet,vac);
		return in_s;
	}


//------------------------------------------------------------------------------

	
}
