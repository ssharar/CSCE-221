// template_main.cpp
//Tests all functionality of the My_vec class.

#include <iostream>
#include <stdexcept>
#include "My_vec_template.h"
#include <string>


int main(){
	try{
		cout << "CHAR CODE BLOCK 1: " << endl;
		// define an object v of My_vec type
		// insert 'B' at the rank 0 into the vector v
		// use the overloaded operator << to display vector elements
		// display the vector v size
		My_vec<char> v(2);
		v.insert_at_rank(0,'B');
		cout << "Vector v element at rank 0: " << v.elem_at_rank(0) << endl;
		cout << "Vector v size: " << v.get_size() << endl << endl;

		cout << "CHAR CODE BLOCK 2: " << endl;
		// insert 'A' at the rank 0 into the vector v
		// use the overloaded operator << to display vector elements
		// display the vector v size
		v.insert_at_rank(0,'A');
		cout << "Vector v element at rank 0: " << v[0] << endl;
		cout << "Vector v element at rank 0: " << v[1] << endl;
		cout << "Vector v size: " << v.get_size() << endl << endl;
		
		cout << "CHAR CODE BLOCK 3: " << endl;
		// insert 'D' at the rank 10 into the vector v
		// use the overloaded operator << to display vector elements
		// display the vector v size
		v.insert_at_rank(10,'D');
		for (int i = 0; i<v.get_capacity(); i++)
		{
			cout << "Vector v element at rank " << i << ": " << v.elem_at_rank(i) << endl;
		}
		cout << "Vector v size: " << v.get_size() << endl << endl;

		cout << "CHAR CODE BLOCK 4: " << endl;
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
		
		cout << "CHAR CODE BLOCK 5: " << endl;
		// replace a character at the rank 2 by the character 'E' 
		// use the overloaded operator << to display vector elements
		// display the vector v size
		v.replace_at_rank(2, 'E');
		for (int i = 0; i<v.get_capacity(); i++)
		{
			cout << "Vector v element at rank " << i << ": " << v[i] << endl;
		}
		cout << "Vector v size: " << v.get_size() << endl << endl;
		
		cout << "CHAR CODE BLOCK 6: " << endl;
		// create a copy v1 of the vector v using a copy constructor
		// use the overloaded operator << to display the vector v1
		// replace a character at the rank 2 of the vector v1 with the character 'Y'
		// use the overloaded operator << to display vector v1 elements
		My_vec<char> v1(v);
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
		
		cout << "CHAR CODE BLOCK 7: " << endl;
		// define an object v2 of My_vec type
		// insert 'K' at the rank 0 into the vector v2
		// use the overloaded operator << to display vector elements
		// display the vector v2 size
		My_vec<char> v2(3);
		v2.insert_at_rank(0,'K');
		for (int i = 0; i<v2.get_capacity(); i++)
		{
			cout << "Vector v2 element at rank " << i << ": " << v2[i] << endl;
		}
		cout << "Vector v2 size: " << v2.get_size() << endl << endl;

		cout << "CHAR CODE BLOCK 8: " << endl;
		// test the assignment operator and copy the vector v1 to v2 
		// use the overloaded operator << to display vector v2
		// display the vector v2 size
		v2 = v1;
		for (int i = 0; i<v2.get_capacity(); i++)
		{
			cout << "Vector v2 element at rank " << i << ": " << v2[i] << endl;
		}
		cout << "Vector v2 size: " << v2.get_size() << endl << endl;
		
		
		cout << "CHAR CODE BLOCK 9: " << endl;
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
		
		
		cout << "CHAR CODE BLOCK 10: " << endl;
		// replace in the vector v2 a character at the rank 14 with 'S'
		v2.replace_at_rank(14,'S');
		for (int i = 0; i<v2.get_capacity(); i++)
		{
			cout << "Vector v2 element at rank " << i << ": " << v2.elem_at_rank(i) << endl;
		}
		cout << endl << endl;
		
		cout << "INT CODE BLOCK 1: " << endl;
		// define an object v of My_vec type
		// insert 1 at the rank 0 into the vector v
		// use the overloaded operator << to display vector elements
		// display the vector v size
		My_vec<int> vi(2);
		
		vi.insert_at_rank(0,1);
		cout << "Vector vi element at rank 0: " << vi.elem_at_rank(0) << endl;
		cout << "Vector vi size: " << vi.get_size() << endl << endl;

		cout << "INT CODE BLOCK 2: " << endl;
		// insert 3 at the rank 0 into the vector v
		// use the overloaded operator << to display vector elements
		// display the vector v size
		vi.insert_at_rank(0,3);
		cout << "Vector vi element at rank 0: " << vi[0] << endl;
		cout << "Vector v element at rank 0: " << vi[1] << endl;
		cout << "Vector vi size: " << vi.get_size() << endl << endl;
		
		cout << "INT CODE BLOCK 3: " << endl;
		// insert 20 at the rank 10 into the vector v
		// use the overloaded operator << to display vector elements
		// display the vector v size
		vi.insert_at_rank(10,20);
		for (int i = 0; i<vi.get_capacity(); i++)
		{
			cout << "Vector vi element at rank " << i << ": " << vi.elem_at_rank(i) << endl;
		}
		cout << "Vector vi size: " << vi.get_size() << endl << endl;

		cout << "INT CODE BLOCK 4: " << endl;
		// remove a character at the rank 2 from the vector v
		// use the overloaded operator << to display vector elements
		// display the vector v size		
		
		//Inserting an element to prove that this test works. Size should be the same as CODE BLOCK 3. Any elements below rank 2 will be moved up one. This will prove that the remove_at_rank works.
		vi.insert_at_rank(2,2);
		vi.remove_at_rank(2);
		for (int i = 0; i<vi.get_capacity(); i++)
		{
			cout << "Vector vi element at rank " << i << ": " << vi[i] << endl;
		}
		cout << "Vector vi size: " << vi.get_size() << endl << endl;
		
		cout << "INT CODE BLOCK 5: " << endl;
		// replace a character at the rank 2 by the character 10 
		// use the overloaded operator << to display vector elements
		// display the vector v size
		vi.replace_at_rank(2, 10);
		for (int i = 0; i<vi.get_capacity(); i++)
		{
			cout << "Vector vi element at rank " << i << ": " << vi[i] << endl;
		}
		cout << "Vector vi size: " << vi.get_size() << endl << endl;
		
		cout << "INT CODE BLOCK 6: " << endl;
		// create a copy v1 of the vector v using a copy constructor
		// use the overloaded operator << to display the vector v1
		// replace a character at the rank 2 of the vector v1 with the character 3
		// use the overloaded operator << to display vector v1 elements
		My_vec<int> vi1(vi);
		for (int i = 0; i<vi1.get_capacity(); i++)
		{
			cout << "Vector vi1 element at rank " << i << ": " << vi1[i] << endl;
		}
		
		vi1.replace_at_rank(2, 3);
		cout << "After Replace, " << endl;
		for (int i = 0; i<vi1.get_capacity(); i++)
		{
			cout << "Vector vi1 element at rank " << i << ": " << vi1[i] << endl;
		}
		cout << endl;
		
		cout << "INT CODE BLOCK 7: " << endl;
		// define an object v2 of My_vec type
		// insert 23 at the rank 0 into the vector v2
		// use the overloaded operator << to display vector elements
		// display the vector v2 size
		My_vec<int> vi2(3);
		vi2.insert_at_rank(0,23);
		for (int i = 0; i<vi2.get_capacity(); i++)
		{
			cout << "Vector vi2 element at rank " << i << ": " << vi2[i] << endl;
		}
		cout << "Vector vi2 size: " << vi2.get_size() << endl << endl;

		cout << "INT CODE BLOCK 8: " << endl;
		// test the assignment operator and copy the vector v1 to v2 
		// use the overloaded operator << to display vector v2
		// display the vector v2 size
		vi2 = vi1;
		for (int i = 0; i<vi2.get_capacity(); i++)
		{
			cout << "Vector vi2 element at rank " << i << ": " << vi2[i] << endl;
		}
		cout << "Vector vi2 size: " << vi2.get_size() << endl << endl;
		
		
		cout << "INT CODE BLOCK 9: " << endl;
		// test the function find_max_index using v2
		// test the function sort_max using v2
		cout << "Max of vi2 at index: " << find_max_index(vi2, vi2.get_capacity()) << endl;
		cout << "Sorting vi2: " << endl;
		sort_max(vi2);
		for (int i = 0; i<vi2.get_capacity(); i++)
		{
			cout << "Vector vi2 sorted element at rank " << i << ": " << vi2.elem_at_rank(i) << endl;
		}
		cout << endl;
		
		
		cout << "INT CODE BLOCK 10: " << endl;
		// replace in the vector v2 a character at the rank 14 with 5
		vi2.replace_at_rank(14,5);
		for (int i = 0; i<vi2.get_capacity(); i++)
		{
			cout << "Vector vi2 element at rank " << i << ": " << vi2.elem_at_rank(i) << endl;
		}
		cout << endl << endl;

		
		
				cout << "DOUBLE CODE BLOCK 1: " << endl;
		// define an object v of My_vec type
		// insert 1 at the rank 0 into the vector v
		// use the overloaded operator << to display vector elements
		// display the vector v size
		My_vec<double> vs(2);
		vs.insert_at_rank(0,1.4);
		cout << "Vector vs element at rank 0: " << vs.elem_at_rank(0) << endl;
		cout << "Vector vs size: " << vs.get_size() << endl << endl;

		cout << "DOUBLE CODE BLOCK 2: " << endl;
		// insert 3 at the rank 0 into the vector v
		// use the overloaded operator << to display vector elements
		// display the vector v size
		vs.insert_at_rank(0,3.4443);
		cout << "Vector vs element at rank 0: " << vs[0] << endl;
		cout << "Vector v element at rank 0: " << vs[1] << endl;
		cout << "Vector vs size: " << vs.get_size() << endl << endl;
		
		cout << "DOUBLE CODE BLOCK 3: " << endl;
		// insert 20 at the rank 10 into the vector v
		// use the overloaded operator << to display vector elements
		// display the vector v size
		vs.insert_at_rank(10,200.0);
		for (int i = 0; i<vs.get_capacity(); i++)
		{
			cout << "Vector vs element at rank " << i << ": " << vs.elem_at_rank(i) << endl;
		}
		cout << "Vector vs size: " << vs.get_size() << endl << endl;

		cout << "DOUBLE CODE BLOCK 4: " << endl;
		// remove a character at the rank 2 from the vector v
		// use the overloaded operator << to display vector elements
		// display the vector v size		
		
		//Inserting an element to prove that this test works. Size should be the same as CODE BLOCK 3. Any elements below rank 2 will be moved up one. This will prove that the remove_at_rank works.
		vs.insert_at_rank(2,2);
		vs.remove_at_rank(2);
		for (int i = 0; i<vs.get_capacity(); i++)
		{
			cout << "Vector vs element at rank " << i << ": " << vs[i] << endl;
		}
		cout << "Vector vs size: " << vs.get_size() << endl << endl;
		
		cout << "DOUBLE CODE BLOCK 5: " << endl;
		// replace a character at the rank 2 by the character 10 
		// use the overloaded operator << to display vector elements
		// display the vector v size
		vs.replace_at_rank(2, 10.5);
		for (int i = 0; i<vs.get_capacity(); i++)
		{
			cout << "Vector vs element at rank " << i << ": " << vs[i] << endl;
		}
		cout << "Vector vs size: " << vs.get_size() << endl << endl;
		
		cout << "DOUBLE CODE BLOCK 6: " << endl;
		// create a copy v1 of the vector v using a copy constructor
		// use the overloaded operator << to display the vector v1
		// replace a character at the rank 2 of the vector v1 with the character 3
		// use the overloaded operator << to display vector v1 elements
		My_vec<double> vs1(vs);
		for (int i = 0; i<vs1.get_capacity(); i++)
		{
			cout << "Vector vs1 element at rank " << i << ": " << vs1[i] << endl;
		}
		
		vs1.replace_at_rank(2, 3);
		cout << "After Replace, " << endl;
		for (int i = 0; i<vs1.get_capacity(); i++)
		{
			cout << "Vector vs1 element at rank " << i << ": " << vs1[i] << endl;
		}
		cout << endl;
		
		cout << "DOUBLE CODE BLOCK 7: " << endl;
		// define an object v2 of My_vec type
		// insert 23 at the rank 0 into the vector v2
		// use the overloaded operator << to display vector elements
		// display the vector v2 size
		My_vec<double> vs2(3);
		vs2.insert_at_rank(0,23.990);
		for (int i = 0; i<vs2.get_capacity(); i++)
		{
			cout << "Vector vs2 element at rank " << i << ": " << vs2[i] << endl;
		}
		cout << "Vector vs2 size: " << vs2.get_size() << endl << endl;

		cout << "DOUBLE CODE BLOCK 8: " << endl;
		// test the assignment operator and copy the vector v1 to v2 
		// use the overloaded operator << to display vector v2
		// display the vector v2 size
		vs2 = vs1;
		for (int i = 0; i<vs2.get_capacity(); i++)
		{
			cout << "Vector vs2 element at rank " << i << ": " << vs2[i] << endl;
		}
		cout << "Vector vs2 size: " << vs2.get_size() << endl << endl;
		
		
		cout << "DOUBLE CODE BLOCK 9: " << endl;
		// test the function find_max_index using v2
		// test the function sort_max using v2
		cout << "Max of vs2 at index: " << find_max_index(vs2, vs2.get_capacity()) << endl;
		cout << "Sorting vs2: " << endl;
		sort_max(vs2);
		for (int i = 0; i<vs2.get_capacity(); i++)
		{
			cout << "Vector vs2 sorted element at rank " << i << ": " << vs2.elem_at_rank(i) << endl;
		}
		cout << endl;
		
		
		cout << "DOUBLE CODE BLOCK 10: " << endl;
		// replace in the vector v2 a character at the rank 14 with 5
		vs2.replace_at_rank(14,5);
		for (int i = 0; i<vs2.get_capacity(); i++)
		{
			cout << "Vector vs2 element at rank " << i << ": " << vs2.elem_at_rank(i) << endl;
		}
		
		
		
	}

	catch(exception &error){
		cerr << "Error: " << error.what() << endl;
	}
}
