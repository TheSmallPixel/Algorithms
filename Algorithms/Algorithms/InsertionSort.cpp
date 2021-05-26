#include "InsertionSort.h"

void InsertionSort::Sort(int* A, int size) {
	for (int j = 2; j < size; j++) {
		int key = A[j];
		int i = j - 1;
		while (i > 0 && A[i] > key) {
			A[i + 1] = A[i];
			i = i - 1;
		}
		A[i + 1] = key;
	}
}

int InsertionSort::Complexity(int n)
{
	return n + (n - 1) + (n - 1) + ((n * (n + 1)) / 2 - 1) + 2 * ((n * (n - 1)) / 2) + (n - 1);
}
