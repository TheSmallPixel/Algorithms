#include "DivideEtImpera.h"

//generic implementation
//template <class T, class N>
//void DivideEtImpera<T,N>::Divide(N* array, int start, int end, int (T::*func)(N*, int, int) ) {
//	if (start < end) {
//		int q = (this->*func)(array, start, end);
//		this->Divide(array, start, q - 1, func);
//		this->Divide(array, q + 1, end, func);
//	}
//}