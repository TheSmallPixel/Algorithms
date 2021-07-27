#pragma once
class HeapSortUnique
{
	typedef void(HeapSortUnique::* heapify_func)(int*, int, int);
	void Sort(int* A, int size, heapify_func func);
	void min_heapify(int*, int, int);
	void max_heapify(int*, int, int);
};

