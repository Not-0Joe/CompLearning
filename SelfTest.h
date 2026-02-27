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

// will do the chaper test below 

/*Question #1

Write a short program that prints the elements of the following vector to the screen using a loop:*/

//   std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };


template <typename T>
void  PrintVecQuiz(const std::vector<T> arr)
{

	std::size_t length = arr.size();
	for (std::size_t i{ 0 }; i < length; i++)
	{
		std::cout << arr[i] << ", ";
	}

	std::cout << "\n";
}


/*Question #3

Given the solution for quiz 2, do the following:

    Ask the user for a value between 1 and 9. If the user does not enter a value between 1 and 9, repeatedly ask for an integer value until they do. If the user enters a number followed by extraneous input, ignore the extraneous input.
    Print the array.
    Write a function template to search the array for the value that the user entered. If the value is in the array, return the index of that element. If the value is not in the array, return an appropriate value.
    If the value was found, print the value and index. If the value was not found, print the value and that it was not found.

We cover how to handle invalid input in lesson 9.5 -- std::cin and handling invalid input.

Here are two sample runs of this program:*/


/*Enter a number between 1 and 9: d
Enter a number between 1 and 9: 6
4 6 7 3 8 2 1 9
The number 6 has index 1

Enter a number between 1 and 9: 5
4 6 7 3 8 2 1 9
The number 5 was not found
*/


template <typename T>
void arrSort(const std::vector<T> arr)
{
	std:size_t usrInput{ 0 };
	
	while (true)
	{
		std::cout << "Enter a number between 1 and 9: ";

		if (!(std::cin >> usrInput)) // non-number input
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (usrInput < 1 || usrInput > 9) // out of range
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else // good input
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
	}

	// print the full array to screen

	std::size_t length = arr.size();
	for (std::size_t i{ 0 }; i < length; i++)
	{
		std::cout << arr[i] << ", ";
	}
	
	std::cout << "\n";

	// sort the arry for the value the user enterd and print its element 

	bool found = false;
	for (std::size_t index{ 0 }; index < length; index++)
	{
		// go to index check value against userinput
		// the current element we are would be = to the index, since index is used to accesss
		if (usrInput == arr[index])
		{
			std::cout << "the number " << usrInput << " is at index " << index << "\n";
			found = true;
		}

	}
	
	if (!found)
	{
		std::cout << "The number " << usrInput << " was not found in the array\n";
	}

}
