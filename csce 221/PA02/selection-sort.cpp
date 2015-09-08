//============================================================================
// Name        : selection-sort.cpp
// Author      : Shaeeta Sharar
// Date        :
// Copyright   : 
// Description : Implementation of selection sort in C++
//============================================================================

#include "sort.h"
#include <iostream>

void SelectionSort::sort(int A[], int size)				// main entry point
{
  //loops through every element
  for (int i = 0; i < size-1; i++)
  {
	//sets index variable to current smallest element
	int index=i;
	
	//Runs through elements and checks for new smallest element
	for (int j = i+1; j < size; j++)
	{
		if (A[j] < A[index]) index = j;
		num_cmps++;
	}
	
	//Swaps larger element with smaller element
	int temp = A[i];
	A[i] = A[index];
	A[index] = temp;
  }
}
