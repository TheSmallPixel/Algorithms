#pragma once
#include "Sorting.h"
	template <class T> class MergeSort : public Sorting<T>
	{
	public:
		void Sort(T*, int);
		void Sort(T*, int, int, int);
		void Merge_Sort(T*, int, int = 0);
		int RealComplexity(int n);
		std::string Complexity();
	};

