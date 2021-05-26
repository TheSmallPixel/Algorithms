#include "MergeSort.h"
#include <limits>

void MergeSort::Sort(int* A, int start, int center, int end)
{
	int n1 = center - start + 1;	//+1 this array have the center
	int n2 = end - center;			//this not
	int* L = new int[n1+1];			//+1 for for the flag value
	int* R = new int[n2+1];

	for (int i = 0; i < n1; i++) 
		(L)[i] = A[start + i];
	
	for (int j = 0; j < n2; j++)
		(R)[j] = A[center + j + 1];
	
	L[n1] = R[n2] = INT_MAX;		//flag value

	for (int k = start, i = 0, j = 0; k <= end; k++) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else if(R[j] != INT_MAX){
			A[k] = R[j];
			j++;
		}
	}
}

void MergeSort::Merge_Sort(int* A, int start, int end)
{
	if (start < end) {
		int center = (start + end) / 2;
		Merge_Sort(A, start, center);
		Merge_Sort(A, center + 1, end);
		Sort(A, start, center, end);
	}
}

