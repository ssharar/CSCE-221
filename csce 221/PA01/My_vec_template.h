/*My_vec.h
Shaeeta Sharar
Header file for a vector data structure.
*/

#include <iostream>
#include <algorithm>

using namespace std;

template <typename T> class My_vec {
	
	//member variables
	
	//size= number of elements
	//capacity is current size of array
	//pointer is array storing elements
	int size; 
	int capacity;
	T *element;
	
public:	
	//member functions
	
	//constructor
	My_vec(int s): size(0), capacity(s), 
			  element(new T[capacity]()) { /*for(int i = 0; i<s; ++i) element[i]=0;*/ }
	~My_vec() {delete[] element; }
	
	//copy constructor 
	My_vec(const My_vec<T>& vec);
	
	//assignment operator
	My_vec<T>& operator=(const My_vec<T>& vec);
	
	//returns number of elements
	int get_size() const { return size; }
	//returns size
	int get_capacity() const { return capacity;}
	
	//bracket element accessors
	T& operator[](int i) const {
		if (i > capacity)	cerr << "ERROR: out of bounds" << endl;	
	}
	
	T& operator[](int i) 
	{
		if (i > capacity)	cerr << "ERROR: out of bounds" << endl;
		return element[i];
	}
	
	//Returns true of empty
	bool is_empty() const { return size == 0;}
	
	//Actions
	T& elem_at_rank(int r) const;
	void overflow_check(int r);
	void insert_at_rank(int r, const T& elem);
	void replace_at_rank(int r, const T& elem);
	void remove_at_rank(int r);
	
};
	template <typename T>
	ostream& operator<<(ostream& out, const My_vec<T>& vec);
	template <typename T>
	int find_max_index(const My_vec<T>& v,int size);
	template <typename T>
	void sort_max(My_vec<T>& vec);
	
	
////////////////////////////////////////////////////////////////
	////////////// FUNCTION DEFINITIONS
///////////////////////////////////////////////////////////////


//Copy constructor
template <typename T>
My_vec<T>::My_vec(const My_vec<T>& vec)
{
	//Copies capacity
	capacity = vec.get_capacity();
	
	//Adjusts size
	size = vec.get_size();
	
	//Allocates new vector
	element = new T[capacity];
	
	//Copies all of the contents of old vector into new vector
	for (int i = 0; i < capacity; i++)
	{
		element[i] = vec.element[i];
	}
	
}

//Assignment operator
template <typename T>
My_vec<T>& My_vec<T>::operator=(const My_vec<T>& vec)
{
	//Test for self assignment
	if (this != &vec)
	{
		//Deletes old vector 
		delete[] element;
		
		//Selects new capacity
		capacity = vec.get_capacity();
		//Sets new size//Adjusts size
		size = vec.get_size();
		
		//Allocates new vector
		//Copies contents over
		element = new T[capacity];
		for (int i =0; i < capacity; i++)
		{
			element[i] = vec.element[i];
		}
		
	}
	
	return *this;
}

//Finds the char that is in the space 'r' and returns its value
template <typename T>
T& My_vec<T>::elem_at_rank(int r) const 
{
	if (r > capacity)	cerr << "ERROR: out of bounds" << endl;	
	return element[r];
}

//Used to reserve 'r' spots in new vector
template <typename T>
void My_vec<T>::overflow_check(int r)
{
	//If the size is already big enough to hold 'r' elements, returns
	if (capacity >= r) return;
	
	//Else: allocates new vector of capacity 'r'
	//Copies every value of old vector to new vector
	T* element_new = new T[r]();
	for (int i = 0; i<capacity; i++)
	{
		element_new[i] = element[i];
	}
	
	//Deletes old vector
	if (element != nullptr)
	{
		delete[] element;
	}
	
	//Sets new vector as main vector
	//Sets capacity as 'r'
	element = element_new;
	capacity = r;

}

//Used to insert a char 'elem' into vector at certain position 'r'
template <typename T>
void My_vec<T>::insert_at_rank(int r, const T& elem)
{
	//Checks for overflow
	//If so, doubles size of array
	if (r >= capacity)
	{
		overflow_check(2*r);
	}
	//Shifts elements up to make room
	for (int i = size-1; i >= r; i--)
	{
		element[i+1] = element[i];
	}
	
	//Puts new element in empty spot
	//Increments size to match
	element[r] = elem;
	size++;
}

//Changes value at place 'r' with char 'elem'
template <typename T>
void My_vec<T>::replace_at_rank(int r, const T& elem)
{
	//Checks if place 'r' is out of range
	//If so, doubles size of array
	if (r >= capacity)
	{
		overflow_check(2*r);
	}
	
	element[r] = elem;
} 

//Removes element at spot 'r'
template <typename T>
void My_vec<T>::remove_at_rank(int r)
{
	//Shits elements down
	for(int i = r+1; i <= capacity; i++)
	{
		element[i-1] = element[i];
	}
	//Decrements size
	size--;
}

//Output operator overload
template <typename T>
ostream& operator<<(ostream& out, const My_vec<T>& vec)
{
	for( int i = 0; i < vec.get_capacity(); i++ )
	{
		out << vec.elem_at_rank(i);
	}
	return (out);
}

//Finds the maximum value at a given index
template <typename T>
int find_max_index(const My_vec<T>& v,int size)
{
	//Variable will store place of max index
	int max_index = 0;
	char value;
	//char g;
	
	value = v.elem_at_rank(0);
	
	//Runs through vector at given size
	for (int i = 1; i<size; i++)
	{
		if (v.elem_at_rank(i) > value)
		{
			value = v.elem_at_rank(i);
			max_index = i;
		}
		
	}
	
	return max_index;
}

//Selection Sort
//Checks each value and sorts in order from smallest to largest
//#s --> CAPS --> lower case

template <typename T>
void sort_max(My_vec<T>& vec)
{
	T p;
	int pm = 0;
	
	for (int i = 0; i < vec.get_capacity()-1; i++) 
	{
		for(int j = i+1; j < vec.get_capacity(); j++)
		{
			if (vec.elem_at_rank(j) > vec.elem_at_rank(pm))
			{
				pm = j;
			}
		}
		
		if (pm != i)
		{
			p = vec.elem_at_rank(i);
			vec.elem_at_rank(i) = vec.elem_at_rank(pm);
			vec.elem_at_rank(pm) = p;
		}

	}

}