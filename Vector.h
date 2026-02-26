#pragma once
#include <vector>
#include <iostream>

// this header will contain the quiz implementaion on 16.2 (yes the name of this header is bad)

/*Question #1

Define a std::vector using CTAD and initialize it with the first 5 positive square numbers (1, 4, 9, 16, and 25).*/

std::vector v1{ 1,4,9,16,25 };

/*Question #2

What’s the behavioral difference between these two definitions?

std::vector<int> v1 { 5 };
std::vector<int> v2 ( 5 );*/

// v1 will prefer the list and make a vector wiht a single element holding the value 5
// v2 will create a vector with 5 elements, that are empty value init

/*Question #3

Define a std::vector (using an explicit template type argument) to hold the high temperature (to the nearest tenth of a degree) 
for each day of a year (assume 365 days in a year).*/

std::vector<double> temp(365);

/*Question #4

Using a std::vector, write a program that asks the user to enter 3 integral values. Print the sum and product of those values.
The output should match the following:

Enter 3 integers: 3 4 5
The sum is: 12
The product is: 60*/

void getUserSum()
{
	std::cout << "Enter 3 integers: ";
	std::vector<int> v(3);

	std::cin >> v[0];
	std::cin >> v[1];
	std::cin >> v[2];

	std::cout << "the sum is: " << v[0] + v[1] + v[2] << "\n";
	std::cout << "the product is: " << v[0] * v[1] * v[2] << "\n";

}


// we make a empty list of int elements with a length of 3
// then use cin and use [] the access the element and the value = what index we are accessing


// we could have chained cin >> to one line the above