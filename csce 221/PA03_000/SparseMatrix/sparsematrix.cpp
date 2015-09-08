#include "sparsematrix.h"

SparseMatrix::SparseMatrix(int m, int n) {

	//Sets rows and columns to values of m and n
	nrows = m;
	ncols = n;
	
	//Runs thru number of rows
	//Pushes back a RowLinkedList for each row
	for (int i =0; i<m; i++)
	{
		rows.push_back(RowLinkedList());
	}
}

SparseMatrix::~SparseMatrix() {

}

double SparseMatrix::get_element_at(int i, int j) const {

	//Temporary node set to first value of the row i
  DListNode<Element>* temp_node;
  temp_node = rows[i].getFirst();
  
  //Runs through linked list
  //If the temporary node matches the column j (a parameter)
  //	returns the value at that part
  //If not, iterates by setting temporary node to next value in linked list
  while (temp_node != rows[i].getAfterLast())
  {
	if (temp_node->getElem().col == j)
	{
		return temp_node->getElem().val;
	}
	temp_node = temp_node->getNext();
  }	
  
  return 0.0;

}

void SparseMatrix::set_element_at(int i, int j, double val) {
 cout << "in set elem \n";
 DListNode<Element>* temp_node;
 temp_node = rows[i].getFirst();
  cout << "in set elem after rows [i] \n";
  
  while (temp_node != rows[i].getAfterLast())
  {
	if (temp_node->getElem().col == j)
	{
		temp_node->getElem().val = val;
		Element newElem;
		newElem.val = temp_node->getElem().val;
		newElem.col = temp_node->getElem().col;
	
		temp_node->setElement(newElem);
	}
	temp_node = temp_node->getNext();
  }

  temp_node = rows[i].getFirst();
  while (temp_node != rows[i].getAfterLast() && temp_node->getElem().col < j)
  {
	temp_node = temp_node->getNext();
  }	

  //GET THIS TO WORK!!!!!
  //temp_node->insert_before(val);

}

double& SparseMatrix::operator()(int i, int j) {
 //Temporary node set to first value of the row i
  DListNode<Element>* temp_node;
  temp_node = rows[i].getFirst();
  
  //Runs through linked list
  //If the temporary node matches the column j (a parameter)
  //	returns the value at that part
  //If not, iterates by setting temporary node to next value in linked list
  while (temp_node != rows[i].getAfterLast())
  {
	if (temp_node->getElem().col == j)
	{
		return temp_node->getElem().val;
	}
	temp_node = temp_node->getNext();
  }	
//GET THIS TO WORK!!!!!   
	//return 0.0;
}

double SparseMatrix::operator()(int i, int j) const {
	return get_element_at(i, j);
}

SparseMatrix SparseMatrix::operator+(const SparseMatrix&) const {
  // implement this function
  throw SparseMatrixException("Not implemented yet.");
}

SparseMatrix SparseMatrix::operator-(const SparseMatrix&) const {
  // implement this function
  throw SparseMatrixException("Not implemented yet.");
}

DenseVector SparseMatrix::operator*(const DenseVector&) const {
  // implement this function
  throw SparseMatrixException("Not implemented yet.");
}

SparseMatrix SparseMatrix::operator*(const SparseMatrix&) const {
  // implement this function
  throw SparseMatrixException("Not implemented yet.");
}

void SparseMatrix::transpose() {
  // implement this function
  throw SparseMatrixException("Not implemented yet.");
}

void SparseMatrix::consolidate() {  
  // implement this function
  throw SparseMatrixException("Not implemented yet.");
}

void SparseMatrix::print(const string &title) {

 	//Temporary node set to first value of the row i
 // DListNode<Element>* temp_node;
  
  //temp_node = rows[0].getFirst();
  
//rows[nrows-1].getAfterLast()
 // while (temp_node != NULL)
  //{
	
	for (int i = 0; i<nrows; i++)
	{
		for (int j = 0; j<ncols; j++)
		{
			cout << SparseMatrix::get_element_at(i, j) << " ";
		}
		cout << endl;
	}
	
	
  //}	
}