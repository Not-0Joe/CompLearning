// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This program consists of my notes and different uses of C++ based on what I have learned so far.
// There are extensive comments to document my learning process.

#include <iostream>
#include "ExplictClass.h"
#include "ConversionClass.h"
#include "constexprClassExample.h"
#include "chaper14QuizClass.h"

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

	Fraction fraction1{ 5, 6 };
	Fraction fraction2{ 6, 7 };
	
	fraction1.multiply(fraction2).printFraction();
	std::cout << "\n";

	return 0;
}
