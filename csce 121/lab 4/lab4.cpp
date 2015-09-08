#include "std_lib_facilities_4.h"

struct Point
{
	
	double x;
	double y;

};

int main()
{
	//Error Check
	//Runs program until it's finished or error is found
	//Goes through catch to find source of error
	//If error is found tells user of error before quitting
	try {
		vector<Point> original_point;
		double x;
		double y; 
		
		ofstream output_file;
		ifstream input_file;
		
		//string l;
		Point a;
		vector<Point> processed_points;
		
		cout << "Please enter seven (x,y) pairs: " << endl;
		for(int c=0; c <= 6; c++)
		{
			cin >> x >> y;
			original_point.push_back(Point{x,y});
		}
		
		//output files
		output_file.open ("mydata.txt");
		
		cout << "\nThe contents you entered were: " << endl;
		for (int element = 0; element < original_point.size(); element++)	
		{
			cout << '(' << original_point[element].x << ',' << original_point[element].y << ')' << endl;
			output_file << original_point[element].x << ' ' << original_point[element].y << endl;
		}	
		
		output_file.close();
		
		
		input_file.open("mydata.txt");
		
		if (!input_file.is_open())
		{
			cout << "Couldn't open file.";
		}
		
		while(!input_file.eof())
		{
			input_file >> a.x >> a.y;
			processed_points.push_back(a);
		}
				
		cout << "\n\nThe contents you originally entered were: " << endl;
		for (int element2 = 0; element2 < original_point.size(); element2++)	
		{
			cout << '(' << original_point[element2].x << ',' << original_point[element2].y << ')' << endl;
		}
		cout << "The contents processed from mydata.txt are: " << endl;
		for (int element3 = 0; element3 < processed_points.size(); element3++)	
		{
			cout << "(" << processed_points[element3].x << "," << processed_points[element3].y << ")"  << endl;
		}
		
		for (int z = 0; z <=6; z++)
		{
			if ((processed_points[z].x&&processed_points[z].y) != (original_point[z].x&&original_point[z].y))
			{
				cout << "Something's wrong!" << endl;
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
