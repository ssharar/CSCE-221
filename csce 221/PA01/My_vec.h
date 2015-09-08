/*My_vec.h
Shaeeta Sharar
Header file for a vector data structure.
*/

#include <iostream>
#include <algorithm>

using namespace std;

class My_vec {
	
	//member variables
	
	//size= number of elements
	//capacity is current size of array
	//pointer is array storing elements
	int size; 
	int capacity;
	char *element;
	
public:	
	//member functions
	
	//constructor
	My_vec(int s): size(0), capacity(s), 
			  element(new char[capacity]) { for(int i = 0; i<s; ++i) element[i]=' '; }
	~My_vec() {delete[] element; }
	
	//copy constructor 
	My_vec(const My_vec& vec);
	
	//assignment operator
	My_vec& operator=(const My_vec& vec);
	
	//returns number of elements
	int get_size() const { return size; }
	//returns size
	int get_capacity() const { return capacity;}
	
	//bracket element accessors
	char& operator[](int i) const {
		if (i > capacity)	cerr << "ERROR: out of bounds" << endl;	
		return element[i];
	}
	
	char& operator[](int i) 
	{
		if (i > capacity)	cerr << "ERROR: out of bounds" << endl;
		return element[i];
	}
	
	//Returns true of empty
	bool is_empty() const { return size == 0;}
	
	//Actions
	char& elem_at_rank(int r) const;
	void overflow_check(int r);
	void insert_at_rank(int r, const char& elem);
	void replace_at_rank(int r, const char& elem);
	void remove_at_rank(int r);
	
};
	
	ostream& operator<<(ostream& out, const My_vec& vec);
	int find_max_index(const My_vec& v,int size);
	void sort_max(My_vec& vec);