#include "QuickSort.h"
#include <iostream>
	template <class T>
	void QuickSort<T>::Sort(T* array, int size) {
		DivideEtImpera(array, 0, size);
	}

	template <class T>
	void QuickSort<T>::DivideEtImpera(T* array, int start, int end) {
		if (start < end) {
			int q = Partition(array, start, end);
			DivideEtImpera(array, start, q - 1);
			DivideEtImpera(array, q + 1, end);
		}
	}

	template <class T>
	int QuickSort<T>::Partition(T* array, int start, int end) {
		T x = array[end];
		int i = start - 1;
		for (int j = start; j < end - 1; j++) {
			if (array[j] <= x) {
				i++;
				std::swap(array[i], array[j]);
			}
		}
		std::swap(array[i + 1], array[end]);
		return i + 1;
	}

	
