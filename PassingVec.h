#pragma once

#include <iostream>
#include <vector>

// code file used to learn about passing vectors / arrary

// passing a vector to a function require we include the emlement type in the parameters

void passMeVec(const std::vector<int>& v)
{
	std::cout << v[0] << "\n";
}

// we can not pass a vector with a diffent element type to the function

// results in narrowing so its not allowed
// passMeVec(d); complier error

// also remember CTAD does not work for function parameters

// to get around this limitation we can use templates to tempate the function paraters to have the complier
// instanate a vector with the element type we pass to it

template <typename T>
void passMeVecT(const std::vector<T>& arr)
{
	std::cout << arr[0] << "\n";
}


// now we can pass vectors to this function and not worry about the element type
// check main to see us pass 2 vectors with diffrent element types 

std::vector<int> chimp{ 1 };
std::vector<double> chimp2{ 1.5 };

// we can also use auto in c++ 20 to do the same thing

void passMeVecAuto(const auto& arr)
{
	std::cout << arr[0] << "\n";
}

// we need to be carful when passing our function above print out the element at index 0 going to be safe 99% of the time 
// but consider a function like this

template <typename U>
void PassMeVecU(const U& arr)
{
	std::cout << arr[10];
}

// function above will accept any object that [] can be used on
// but what if we passed in a vector that only had 5 elements?
// the program out crash since we are trying to access out of the bounds of the vector, and [] does no bounds checking

// we could do a runtime assert on the length of the array for a debug build, but we can use use runtime asserts since std::vector.size() is non-contexper
// it we need to do an complie time assert on the length of an array we should use std::array since it supports static_assert


/*Quiz time

Question #1

Write a function that takes two parameters: a std::vector and an index. If the index is out of bounds, print an error. If the index is in bounds, print the value of the element.

The following sample program should compile:*/

/*  std::vector v1 { 0, 1, 2, 3, 4 };
    printElement(v1, 2);
    printElement(v1, 5);

    std::vector v2 { 1.1, 2.2, 3.3 };
    printElement(v2, 0);
    printElement(v2, -1);

 
}

and produce the following result:

The element has value 2
Invalid index
The element has value 1.1
Invalid index
*/

template <typename V>
void printElement(const std::vector<V>& arr, int index)
{
    
    if (index > 4 || index < 0)
    {
        std::cout << "Invalid index\n";
        return;
    }

    std::cout << "The element has value " << arr[index] << "\n";

}

// i forgot to do casting into std::size_t and i could have writen the if check better here this is the soloution provided

//template <typename T>
//void printElement(const std::vector<T>& arr, int index)
//{
//    if (index < 0 || index >= static_cast<int>(arr.size())) // In C++20, could use std::ssize(arr) to avoid the cast
//        std::cout << "Invalid index\n";
//    else
//        std::cout << "The element has value " << arr[static_cast<std::size_t>(index)] << '\n';
//}

// this makes more sense sice we first check to see if if the index is less than 0 it should not be since we can't have an array with a negative index

// second it checks it the index is equal to or greater than the max size of the array, since if it was we would be out of bounds

// it checks it by first getting the size of the array with arr.size() then casts that std::size_t into an int and does the check
// the reason we are casting it back into an int and not just using the size_t to do the comparason is to avoid comparing an int to an unsigned int

// then at the end it makes it clear we are converting the int value used for the index, into a type std::size_t


// this has provided some useful insight to checking bounds and logical reasoning (lets hope i dont forget this, i will)
