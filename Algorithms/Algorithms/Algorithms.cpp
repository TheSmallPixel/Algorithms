// Algorithms.cpp : Questo file contiene la funzione 'main', in cui inizia e termina l'esecuzione del programma.
//
#include "QuickSort.cpp"
#include "InsertionSort.h"
#include "MergeSort.cpp"
#include "HeapSort.h"
#include "Utils.h"
#include <iostream>

int main()
{   
    auto algorithms = new MergeSort<int>();
    int* A = new int[]{ 10, 5, 4, 7, 10, 2, 3, 9,-1};
    Utils::printArray(A, 8);
    algorithms->Sort(A,8);
    Utils::printArray(A, 8);
    std::cout << "Hello World!\n";
}


