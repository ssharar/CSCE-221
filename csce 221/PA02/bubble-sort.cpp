//============================================================================
// Name        : bubble-sort.cpp
// Author      : Matt Smith
// Date        :
// Copyright   : 
// Description : Implementation of bubble sort in C++
//============================================================================

#include "sort.h"

void BubbleSort::sort(int A[], int size)			// main entry point
{
	bool cont = true;
	while(cont)
	{
		for(int k=1; k < size; k++)
		{
			cont = false;
			for(int j=0; j < size-k; j++)
			{
				if(A[j+1] < A[j])
				{
					int tmp = A[j]; //swap A[j] and A[j+1]
					A[j] = A[j+1];
					A[j+1] = tmp;
					cont = true;
				}
				num_cmps++;
			}
		}
	}
}
