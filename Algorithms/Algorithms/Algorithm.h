#pragma once
#include <string>
class Algorithm
{
public:
	virtual int RealComplexity(int n) = 0;
	virtual std::string Complexity() = 0;
};

