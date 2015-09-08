// main.cpp
//Tests all functionality of the My_vec class.

#include <iostream>
#include <stdexcept>
#include "My_vec.h"


int main(){
	try{

		cout << "CODE BLOCK 1: " << endl;
		// define an object v of My_vec type
		// insert 'B' at the rank 0 into the vector v
		// use the overloaded operator << to display vector elements
		// display the vector v size
		My_vec v(2);
		v.insert_at_rank(0,'B');
		cout << "Vector v element at rank 0: " << v.elem_at_rank(0) << endl;
		cout << "Vector v size: " << v.get_size() << endl << endl;

		cout << "CODE BLOCK 2: " << endl;
		// insert 'A' at the rank 0 into the vector v
		// use the overloaded operator << to display vector elements
		// display the vector v size
		v.insert_at_rank(0,'A');
		cout << "Vector v element at rank 0: " << v[0] << endl;
		cout << "Vector v element at rank 0: " << v[1] << endl;
		cout << "Vector v size: " << v.get_size() << endl << endl;
		
		cout << "CODE BLOCK 3: " << endl;
		// insert 'D' at the rank 10 into the vector v
		// use the overloaded operator << to display vector elements
		// display the vector v size
		v.insert_at_rank(10,'D');
		for (int i = 0; i<v.get_capacity(); i++)
		{
			cout << "Vector v element at rank " << i << ": " << v.elem_at_rank(i) << endl;
		}
		cout << "Vector v size: " << v.get_size() << endl << endl;

		cout << "CODE BLOCK 4: " << endl;
		// remove a character at the rank 2 from the vector v
		// use the overloaded operator << to display vector elements
		// display the vector v size		
		
		//Inserting an element to prove that this test works. Size should be the same as CODE BLOCK 3. Any elements below rank 2 will be moved up one. This will prove that the remove_at_rank works.
		v.insert_at_rank(2,'T');
		v.remove_at_rank(2);
		for (int i = 0; i<v.get_capacity(); i++)
		{
			cout << "Vector v element at rank " << i << ": " << v[i] << endl;
		}
		cout << "Vector v size: " << v.get_size() << endl << endl;
		
		cout << "CODE BLOCK 5: " << endl;
		// replace a character at the rank 2 by the character 'E' 
		// use the overloaded operator << to display vector elements
		// display the vector v size
		v.replace_at_rank(2, 'E');
		for (int i = 0; i<v.get_capacity(); i++)
		{
			cout << "Vector v element at rank " << i << ": " << v[i] << endl;
		}
		cout << "Vector v size: " << v.get_size() << endl << endl;
		
		cout << "CODE BLOCK 6: " << endl;
		// create a copy v1 of the vector v using a copy constructor
		// use the overloaded operator << to display the vector v1
		// replace a character at the rank 2 of the vector v1 with the character 'Y'
		// use the overloaded operator << to display vector v1 elements
		My_vec v1(v);
		for (int i = 0; i<v1.get_capacity(); i++)
		{
			cout << "Vector v1 element at rank " << i << ": " << v1[i] << endl;
		}
		
		v1.replace_at_rank(2, 'Y');
		cout << "After Replace, " << endl;
		for (int i = 0; i<v1.get_capacity(); i++)
		{
			cout << "Vector v1 element at rank " << i << ": " << v1[i] << endl;
		}
		cout << endl << endl;
		
		cout << "CODE BLOCK 7: " << endl;
		// define an object v2 of My_vec type
		// insert 'K' at the rank 0 into the vector v2
		// use the overloaded operator << to display vector elements
		// display the vector v2 size
		My_vec v2(3);
		v2.insert_at_rank(0,'K');
		for (int i = 0; i<v2.get_capacity(); i++)
		{
			cout << "Vector v2 element at rank " << i << ": " << v2[i] << endl;
		}
		cout << "Vector v2 size: " << v2.get_size() << endl << endl;

		cout << "CODE BLOCK 8: " << endl;
		// test the assignment operator and copy the vector v1 to v2 
		// use the overloaded operator << to display vector v2
		// display the vector v2 size
		v2 = v1;
		for (int i = 0; i<v2.get_capacity(); i++)
		{
			cout << "Vector v2 element at rank " << i << ": " << v2[i] << endl;
		}
		cout << "Vector v2 size: " << v2.get_size() << endl << endl;
		
		
		cout << "CODE BLOCK 9: " << endl;
		// test the function find_max_index using v2
		// test the function sort_max using v2
		cout << "Max of v2 at index: " << find_max_index(v2, v2.get_capacity()) << endl;
		cout << "Sorting v2: " << endl;
		sort_max(v2);
		for (int i = 0; i<v2.get_capacity(); i++)
		{
			cout << "Vector v2 sorted element at rank " << i << ": " << v2.elem_at_rank(i) << endl;
		}
		cout << endl;
		
		
		cout << "CODE BLOCK 10: " << endl;
		// replace in the vector v2 a character at the rank 14 with 'S'
		v2.replace_at_rank(14,'S');
		for (int i = 0; i<v2.get_capacity(); i++)
		{
			cout << "Vector v2 element at rank " << i << ": " << v2.elem_at_rank(i) << endl;
		}
		

	}

	catch(exception &error){
		cerr << "Error: " << error.what() << endl;
	}
}
