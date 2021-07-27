#include "Utils.h"
#include <iostream>

void Utils::printArray(int* array, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << *(array + i) << "|";
	}
	std::cout << std::endl;
}

int Utils::GetIndex(int* A, int size, int key)
{
	for (int i = 0; i < size; i++) {
		if (A[i] == key)
			return i;
	}
	return -1;
}