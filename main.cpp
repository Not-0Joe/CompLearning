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
#include "InlineClass.h"
#include "NestedClass.h"
#include "deconstructorExample.h"


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

	// -- inline member functions --

	// functions are not ODR exempt, meaning that if we define a function in a header file, and include that header file in multiple cpp files, 
	// we will get a linker error because the function is defined in multiple translation units violating the ORD rule

	// but since member functions defined inside a class definition are implicitly inline we are able to define them in a header file that is included into
	// multiple cpp files without getting a linker error

	// when the complier see a inlined function it replaces the call with the code of the function 

	// we just went over spliting the declaration and definition of a class into a header file and a source file,
	// but since our soruce file is outside of the class definition the member functions are not implicitly inline

	// but this is ok since if we include the header file it does not include the source file,
	// so we will not get a linker error because the function is only defined in one translation unit

	// but if we have non member functions defined in a header file that is included in multiple cpp files, 
	// we will get a linker error because the function is defined in multiple translation units violating the ORD rule

	// we can fix this just by marking the non member functions defined the class header file as inline
 
	InlineClass inlineClass{ 10 };

	std::cout << "InlineClass getX() result: " << inlineClass.getX() << "\n";

	// so the order of things would be:
	// if the class is small and simple we can define the member functions inside of the class definition
	// if the class is larger and has more complex member functions we should consider, if we can separate the member function into non member functions and pass by const ref to them
	// with a larger class we should separate the declaration and definition of the class into a header file and a source file with the same name
	// inside the source file we inclide the header and then use :: to specify that the function is a member of the class
	// put the public member functions at the top of the class definition and the private member variables at the bottom of the class definition

	// if we do make a member function into a non member function we need to mark it as inline to avoid linker errors incase we include that header file into multiple cpp files
	// if we know for cretain that a function will only be used in one cpp file, we can just define it in that cpp file and not mark it as inline

	// -- 15.3 — Nested types (member types) -- 

	// we can nest types inside of a class definition, we should do this if the type is related to the class like an atribute
	// we must place the type at the top of the class definition, nested types must be defined before they are used in the class definition
	// outside of the class definition we need to use the class name and :: to access the nested type and its members
	
	// see NestedClass.h and NestedClass.cpp for an example of this

	NestedClass nestedClass{};
	nestedClass.getColor();
	nestedClass.setColor(NestedClass::Red);
	nestedClass.getColor();
	nestedClass.printInfo();


	// as we can see we can access the nested type and its members using the class name and ::
	// but if you look inside of NestedClass.cpp, inside of the member functions we can just use the name of the enumrator without ::

	// you can also have nested typedefs and type aliases
	// see NestedClass2 in NestedClass.h for an example of this

	NestedClass2 nestedClass2{ 5 };

	// -- 15.4 — Introduction to destructors -- (YAY DESTRUCTORS)

	// constructors set up an object and initializes its members 
	// a deconstructor does clean up before an object is destroyed

	// think of a task where we must insure that some resource is released or some function must be ran before an object is destroyed
	// like closing a connection to unallocating memeory that is the perpouse of a deconstructor

	// see deconstructorExample.h and deconstructorExample.cpp for an example of this

	deconstructorExample deconstructorExample{ 5, 5 };

	// we can see with the output to the console setY() is called since the deconstructor is called before the object is destroyed
	deconstructorExample.checkY();




	return 0;
}
