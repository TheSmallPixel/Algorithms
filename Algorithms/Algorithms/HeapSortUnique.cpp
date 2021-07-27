#include "HeapSortUnique.h"
#include <iostream>
#include <math.h>
#include <limits>
void HeapSortUnique::Sort(int* A, int size, heapify_func heapfy)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		(this->*heapfy)(A, size, i);	// ok buy why half duah
	int prevValue = INT32_MAX;
	for (int i = size - 1; i > 0; i--) {// One by one extract an element from heap and removeit
		if (prevValue != INT32_MAX && prevValue == A[i + 1]) {
			A[0] = 
		}
		prevValue = A[i];
		std::swap(A[0], A[i]);			// Remove current max
		(this->*heapfy)(A, i, 0);		// Reorder new sub-tree

		
		
	}
}
void HeapSortUnique::min_heapify(int* A, int size, int index)
{
	int largest = index;				// largest = root
	int l = 2 * index + 1;				// left
	int r = 2 * index + 2;				// right

	if (l < size && A[l] < A[largest])	// If left child is larger than root
		largest = l;

	if (r < size && A[r] < A[largest])	// If right child is larger than largest so far
		largest = r;

	if (largest != index) {				// If largest is not root, swap and re-heapify
		std::swap(A[index], A[largest]);
		min_heapify(A, size, largest);	// Recursively heapify the affected sub-tree
	}
}

void HeapSortUnique::max_heapify(int* A, int size, int index)
{
	int largest = index;				// largest = root
	int l = 2 * index + 1;				// left
	int r = 2 * index + 2;				// right

	if (l < size && A[l] > A[largest])	// If left child is larger than root
		largest = l;

	if (r < size && A[r] > A[largest])	// If right child is larger than largest so far
		largest = r;

	if (largest != index) {				// If largest is not root, swap and re-heapify
		std::swap(A[index], A[largest]);
		max_heapify(A, size, largest);	// Recursively heapify the affected sub-tree
	}
}
