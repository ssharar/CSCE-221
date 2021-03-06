#pragma once

#include "../TemplateDoublyLinkedList/TemplateDoublyLinkedList.h"

#include <iostream>
#include <stdexcept>
#include <string>

#include <vector>


typedef std::vector<double> DenseVector;
using namespace std;

struct SparseMatrixException : public exception {
	SparseMatrixException(){}
	SparseMatrixException(const string &message){
		msg = "SparseMatrix exception:" + message;
	}
	const char* what() const noexcept{
		return msg.c_str();
	}
	
	string msg;
};

class SparseMatrix {
public:
  struct Element {
    unsigned int col;
    double val;

	//Constructor
	Element(unsigned int column, double value)
	{
		col = column;
		val = value;
	}

	Element(){};
  };
  typedef DoublyLinkedList<Element> RowLinkedList;

public:
  SparseMatrix():nrows(0), ncols(0){}                   // constructor of empty matrix
  SparseMatrix(int m, int n);                           // constructor for a m-by-n matrix
  ~SparseMatrix();                                      // destructor

  /*
  No need to implement the following constructors, because they will be
  generated by the compiler correctly if:
      1. The copy/assignment constructors of My_vec is implemented correctly
      2. The copy/assignment constructors of DoublyLinkedList is implemented correctly
  */
  /*
  SparseMatrix(const SparseMatrix&);                    // copy constructor
  SparseMatrix& operator=(const SparseMatrix&);         // assignment constructor
  */

  int get_rows() const { return nrows; }
  int get_cols() const { return ncols; }

  RowLinkedList& row(int i) {
    if( i <= 0 || i > nrows ) throw SparseMatrixException("Row index is out of range!");
    else return rows[i];
  }

  const RowLinkedList& row(int i) const {
    if( i <= 0 || i > nrows ) throw SparseMatrixException("Row index is out of range!");
    else return rows[i];
  }

  // Implement the following functions
  double get_element_at(int i, int j) const;
  void set_element_at(int i, int j, double val);
  double& operator()(int i, int j);                     // access element (i, j)
  double operator()(int i, int j) const;                // access element (i, j)

  SparseMatrix operator+(const SparseMatrix&) const;   // matrix addition A + B
  SparseMatrix operator-(const SparseMatrix&) const;   // matrix subtraction A + B
  DenseVector operator*(const DenseVector&) const;     // matrix-dense vector multiplication
  SparseMatrix operator*(const SparseMatrix&) const;   // matrix-matrix multiplication

  void transpose();                                     // matrix transposition
  void consolidate();                                   // remove all zeros
  void print(const string &title=string());             // display the matrix in human readable form

  friend std::ostream& operator<<(std::ostream &os, const SparseMatrix &A);
  friend std::istream& operator>>(std::istream &is, SparseMatrix &A);

private:
  int nrows, ncols;                                     // matrix dimension
  vector<RowLinkedList> rows;                           // row linked lists
};

inline std::ostream& operator<<(std::ostream &os, const SparseMatrix &A) {
  
	os << A.nrows << " " << A.ncols << endl;

	for (int i = 0; i<A.nrows; i++)
	{
		for (int j = 0; j<A.ncols; j++)
		{
			os << i << " " << j << " " << A.get_element_at(i, j) << " " << endl;
		}
	}


  return os;
}

inline std::istream& operator>>(std::istream &is, SparseMatrix &A) {
 
  int nrow, ncol;
  int rowi, coli;
  double val;

  is >> nrow >> ncol;
  A.nrows = nrow;
  A.ncols = ncol;

  A.rows.resize(nrow);

  while (is >> rowi >> coli >> val)
  {
	A.rows[rowi].insertLast(SparseMatrix::Element(coli, val));
  }

  return is;
}

#if USE_STL_VECTOR
inline std::ostream& operator<<(std::ostream &os, DenseVector &v) {
  // implement this function
  return os;
}
#endif
