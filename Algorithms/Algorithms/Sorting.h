#pragma once
#include "Algorithm.h"

template <class T> class Sorting : public Algorithm
{
	virtual void Sort(T*, int) = 0;
};

