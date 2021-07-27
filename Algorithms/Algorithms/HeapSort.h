#pragma once

	class HeapSort
	{

	public:
		typedef void(HeapSort::* heapify_func)(int*, int, int);
		void Sort(int* A, int size, heapify_func func);
		int GetHeight(int* A, int size, int key);
		int GetHeightV2(int);
		void min_heapify(int*, int, int);
		void max_heapify(int*, int, int);

	};

