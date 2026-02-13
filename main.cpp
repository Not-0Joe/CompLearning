// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

// this program will consist of my notes and diffrent uses of c++ and what i have learned so far
// there will be lots of comments to document my learning

#include <iostream>
#include "ExplictClass.h"
#include "ConversionClass.h"


int main()
{
	// seeing if we pass in an int to a function that takes a Convert class if it will use the
	// user-defined constructor

	convertPrint(5);

	// testing the use of a class using the explicit keyword

	// works like a normal constructor init the member variable of imExplicit
	Explicit imExplicit{ 5,5 };

	// lets try doing a print requiring a converstion

	// convertExplictPrint(5); // if we uncomment this line we get a compilation error since convertion is forbidden on the constructor this calls

	// what if we wanted to use an do a converstion on an explicit constructor we can do a work around by "explicitly" define the object ourselfs

	std::cout << "Calling explicit constructor with Explicit{5}\n";
	convertExplictPrint(Explicit{ 5 });

	// we can also use static_cast to cast into our desired object

	std::cout << "Calling explicit constructor with static_cast(7)\n";
	convertExplictPrint(static_cast<Explicit>(7));



}

// convertPrint is called with an int agument since convertPrint takes a Convert class type the complier looks to see if there
// are any user defined converting constructors and it see the Convert(int x) constructor it then converts the int into a Convert Object
// and returns it that Convert Object is now passed as an agument to ConvertPrint