#pragma once
#include "Sorting.h"
	template <class T> class QuickSort : public Sorting<T>
	{
	private:
		void DivideEtImpera(T* array, int start, int end);
		int Partition(T* array, int start, int end);
	public:
		void Sort(T* array, int size);
	};
