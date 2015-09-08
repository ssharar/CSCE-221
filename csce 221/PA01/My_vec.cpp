#include "My_vec.h"

//Copy constructor
My_vec::My_vec(const My_vec& vec)
{
	//Copies capacity
	capacity = vec.get_capacity();
	
	//Adjusts size
	size = vec.get_size();
	
	//Allocates new vector
	element = new char[capacity];
	
	//Copies all of the contents of old vector into new vector
	for (int i = 0; i < capacity; i++)
	{
		element[i] = vec.element[i];
	}
	
}

//Assignment operator
My_vec& My_vec::operator=(const My_vec& vec)
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
		element = new char[capacity];
		for (int i =0; i < capacity; i++)
		{
			element[i] = vec.element[i];
		}
		
	}
	
	return *this;
}

//Finds the char that is in the space 'r' and returns its value
char& My_vec::elem_at_rank(int r) const 
{
	if (r > capacity)	cerr << "ERROR: out of bounds" << endl;	
	return element[r];
}

//Used to reserve 'r' spots in new vector
void My_vec::overflow_check(int r)
{
	//If the size is already big enough to hold 'r' elements, returns
	if (capacity >= r) return;
	
	//Else: allocates new vector of capacity 'r'
	//Copies every value of old vector to new vector
	char* element_new = new char[r];
	for (int i = 0; i<r; i++)
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
void My_vec::insert_at_rank(int r, const char& elem)
{
	//Checks for overflow
	//If so, doubles size of array
	if (r >= capacity)
	{
		overflow_check(max(1,2*r));
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
void My_vec::replace_at_rank(int r, const char& elem)
{
	//Checks if place 'r' is out of range
	//If so, doubles size of array
	if (r >= capacity)
	{
		overflow_check(max(1,2*r));
	}
	
	element[r] = elem;
} 

//Removes element at spot 'r'
void My_vec::remove_at_rank(int r)
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
ostream& operator<<(ostream& out, const My_vec& vec)
{
	for( int i = 0; i < vec.get_capacity(); i++ )
	{
		out << vec.elem_at_rank(i);
	}
	return (out);
}

//Finds the maximum value at a given index
int find_max_index(const My_vec& v,int size)
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
void sort_max(My_vec& vec)
{
	char p;
	int f = 0;
	
	for (int i = vec.get_capacity()-1; i > 0; i--) 
	{
		for(int j =1; j<=i; j++)
		{
			if (vec.elem_at_rank(j) > vec.elem_at_rank(f))
			{
				f = j;
			}
		}

		p = vec.elem_at_rank(f);
		vec.elem_at_rank(f) = vec.elem_at_rank(i);
		vec.elem_at_rank(i) = p;

	}

}