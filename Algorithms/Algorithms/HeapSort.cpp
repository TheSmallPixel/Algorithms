#include "HeapSort.h"
#include <iostream>
#include <math.h>

	void HeapSort::Sort(int* A, int size, heapify_func heapify) {
		for (int i = size / 2 - 1; i >= 0; i--)
			(this->*heapify)(A, size, i);	// ok buy why half duah

		for (int i = size - 1; i > 0; i--) {// One by one extract an element from heap and removeit
			std::swap(A[0], A[i]);			// Remove current max
			(this->*heapify)(A, i, 0);		// Reorder new sub-tree
		}
	}

	void HeapSort::min_heapify(int* A, int size, int index)
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

	void HeapSort::max_heapify(int* A, int size, int index)
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

	int HeapSort::GetHeight(int* A, int size, int index) {

		if (index == -1) return -1;
		if (index == 0) return 0;

		int parentIndex = 0;
		if (index % 2)
			parentIndex = (index - 2) / 2;
		else
			parentIndex = (index - 1) / 2;

		return 1 + GetHeight(A, size, parentIndex);
	}

	int HeapSort::GetHeightV2(int index) {
		return (int)ceil(log2(index + 1)) - 1;
	}

