//============================================================================
// Name        : insertion-sort.cpp
// Author      : Amanda Weyer
// Date        :
// Copyright   : 
// Description : Implementation of insertion sort in C++
//============================================================================

#include "sort.h"

void InsertionSort::sort(int A[], int size){			// main entry point
 
	for (int k = 1; k < size; k++){
		int tmp = A[k];
		int j = k;
		for(; j > 0 && tmp < A[j-1]; j--)
			num_cmps++;
			A[j] = A[j-1];
		A[j] = tmp;
	}
}

