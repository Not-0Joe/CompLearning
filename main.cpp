// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This program consists of my notes and different uses of C++ based on what I have learned so far.
// There are extensive comments to document my learning process.

#include <iostream>
#include "ExplictClass.h"
#include "ConversionClass.h"
#include "constexprClassExample.h"
#include "chaper14QuizClass.h"
#include "ThisExample.h"
#include "organizedClass.h"


int main()
{
	// Testing if passing an int to a function that takes a 'Convert' class 
	// will trigger the use of the user-defined converting constructor.
	convertPrint(5);

	
	
	// convertPrint is called with an int argument. Since convertPrint expects a 'Convert' class type,
	// the compiler looks for any user-defined converting constructors. It finds 'Convert(int x)',
	// converts the int into a 'Convert' object, and passes that object as the argument.

	// --- Testing the use of a class using the 'explicit' keyword ---

	// Works like a normal constructor, initializing the member variables of 'imExplicit'.
	Explicit imExplicit{ 5, 5 };

	// Attempting a function call that requires an implicit conversion.
	// convertExplictPrint(5); // Uncommenting this results in a compilation error because conversion is forbidden by the 'explicit' keyword.

	// If we want to use an explicit constructor, we can bypass the restriction 
	// by "explicitly" creating the object ourselves.
	std::cout << "Calling explicit constructor with Explicit{5}\n";
	convertExplictPrint(Explicit{ 5 });

	// We can also use static_cast to explicitly cast the value into our desired object type.
	std::cout << "Calling explicit constructor with static_cast(7)\n";
	convertExplictPrint(static_cast<Explicit>(7));

	/*Best practice :
	Make any constructor that accepts a single argument 'explicit' by default.
	If an implicit conversion is semantically equivalent and performant,
	you may consider making it non-explicit. */


	// --- 14.17 — Constexpr classes ---

	// A constexpr class object.
	constexpr ConstexprClass constexprClass{ 5, 6 };

	// A constexpr member function can be called just like a normal function.
	std::cout << constexprClass.getGreater() << "\n";

	// A non-constexpr class object calling a constexpr member function.
	// This works because constexpr member functions are "dual-use," meaning 
	// they can be called by both constexpr and non-constexpr objects.
	ConstexprClass constexprClass2{ 6, 7 };
	std::cout << constexprClass2.getGreater() << "\n";

	// --- CHAPTER 14 QUIZ ---

	Point2d first{};
	Point2d second{ 3.0, 4.0 };

	// Point2d third{ 4.0 }; // Should error if uncommented (requires two arguments or default).

	first.print();
	second.print();

	std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

	// take some time to understand why this function returns a Fraction object
	// and the result of calling printFraction()

	Fraction fraction1{ 5, 6 };
	Fraction fraction2{ 6, 7 };
	
	fraction1.multiply(fraction2).printFraction();
	std::cout << "\n";

	// --- 15.1 — The hidden “this” pointer and member function chaining ---

	// Inside every member function, the keyword this is a const pointer that holds the address of the current implicit object.
	
	// this is a pointer to the implicit object and -> is used to access members of the implicit object.
	
	// complier adds this->
	Simple simple{ 5 };
	// we explictly add this->3
	Simple2 simple2{ 6 };
	// using this-> to disambiguate
	simple2.printData(5);

	// Returning *this from a member function allows for chaining multiple member function calls on the same object.
	Chains chains{ 5 };
	chains.addX(10).addX(10).printX();

	// using *this to reset an object to its default state
	chains.resetObject().printX();

	// this is a const pointer meaning it can not change what it is pointing to, but the data at the address can be modifyed
	// the reason is not a refrence is because when it was implmented into c++ refrences were not yet a feature of the language,
	// in other languages like java and c#, this is implemented as a reference

	// -- 15.2 — Classes and header files --

	// as our programs get larger and more complex, we will want to split our code into multiple files
	// as we have been doing putting our class definitions in header files and function definitions in cpp files, then including the header file 
	// we can do the same for class definitions and member function definitions

	// so we make a header file with the class definition and function prototypes
	// then we make a cpp with the function definitions we just need to use :: to specify that the function is a member of the class
	// we should also keep the name of the header file and the cpp file the same to make it clear that they are related

	// see example in organizedClass.h and organizedClass.cpp

	OrganizedClass organizedClass{ 5 };
	organizedClass.printX();

	// it may have been beter to just make print a non member funtion in its own cpp file, 
	// but this is just to show how we can separate the declaration and definition of a class into a header file and a source file



	

	return 0;
}
