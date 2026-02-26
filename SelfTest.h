#pragma once
#include <vector>

// write a function that can take in a vector with any elemente type, int double ect
// it should be able to take in any length of arrary and then return the sum of the arrary passed in

template <typename T>
T GetVectorSum(const std::vector<T>& arr) 
{
	std::size_t length = arr.size();
	T sumOfElement{ 0 };
	
	for (std::size_t i{ 0 }; i < length; i++)
	{
	
		sumOfElement = sumOfElement + static_cast<T>(arr[i]);
	}

	return sumOfElement;
	
}

