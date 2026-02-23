// main.cpp : This file contains the 'main' function. Program execution begins and ends here.
// This program contains my notes and examples of C++ features I have learned so far.
// Extensive comments are included to document my learning process.

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
#include "tempMemberFuncClass.h"
#include "TriadQuiz.h"
#include "StaticClass.h"
#include "NonMemberFriend.h"


int main()
{
	// Testing if passing an int to a function that takes a 'Convert' class 
	// will trigger the use of the user-defined converting constructor.
	convertPrint(5);

    // `convertPrint` is called with an int argument. Since `convertPrint` expects a `Convert` object,
	// the compiler looks for user-defined converting constructors. It finds `Convert(int)`,
	// converts the int into a `Convert` object, and passes that object as the argument.

    // --- Testing the use of a class with the 'explicit' keyword ---

	// Works like a normal constructor, initializing the members of `imExplicit`.
	Explicit imExplicit{ 5, 5 };

    // Attempting a function call that requires an implicit conversion.
	// convertExplictPrint(5); // Uncommenting this will cause a compilation error because the constructor is explicit.

	// To use an explicit constructor we must create the object explicitly.
	std::cout << "Calling explicit constructor with Explicit{5}\n";
	convertExplictPrint(Explicit{ 5 });

	// We can also use static_cast to explicitly cast the value into our desired object type.
	std::cout << "Calling explicit constructor with static_cast(7)\n";
	convertExplictPrint(static_cast<Explicit>(7));

    /* Best practice:
	   Make any constructor that accepts a single argument `explicit` by default.
	   If an implicit conversion is semantically appropriate and inexpensive,
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

    // Take some time to understand why this function returns a Fraction object
	// and what the result of calling `printFraction()` is.

	Fraction fraction1{ 5, 6 };
	Fraction fraction2{ 6, 7 };
	
	fraction1.multiply(fraction2).printFraction();
	std::cout << "\n";

    // --- 15.1 — The hidden `this` pointer and member function chaining ---

	// Inside every member function, the keyword `this` is a const pointer to the implicit object.

	// `this` points to the implicit object and `->` is used to access its members.

	// The compiler implicitly adds `this->` where needed.
	Simple simple{ 5 };
	// we explictly add this->3
	Simple2 simple2{ 6 };
	// using this-> to disambiguate
	simple2.printData(5);

    // Returning `*this` from a member function enables chaining multiple calls on the same object.
	Chains chains{ 5 };
	chains.addX(10).addX(10).printX();

	// using *this to reset an object to its default state
	chains.resetObject().printX();

    // `this` is a const pointer, so the pointer itself cannot be changed, but the object it points to can be modified.
	// Historically `this` is a pointer rather than a reference because references were not part of the language when it was added.
	// In languages like Java and C#, `this` behaves more like a reference.

    // -- 15.2 — Classes and header files --

	// As programs grow, we split code across multiple files. Place class declarations in headers and function definitions in .cpp files.
	// We can use the same approach for separating class declarations and member function definitions.

    // Create a header that contains the class definition and prototypes, and a .cpp with the definitions.
	// Use `::` to qualify member functions. Keep the header and source file names consistent to show they are related.

    // See the example in `organizedClass.h` and `organizedClass.cpp`.

	OrganizedClass organizedClass{ 5 };
	organizedClass.printX();

    // It might be better to make `print` a non-member function in its own .cpp file,
	// but this demonstrates separating a class declaration and its definitions.

    // -- inline member functions --

	// Functions are not ODR-exempt: if a non-inline function is defined in a header included by multiple .cpp files,
	// the linker will see multiple definitions and fail. Member functions defined inside a class are implicitly inline,
	// so they can be defined in headers safely.

	// When the compiler inlines a function it may replace the call with the function body for performance.

    // We saw how to split declarations and definitions. Member functions defined in a .cpp are not implicitly inline,
	// but that is fine because the header does not include the .cpp, so the function has a single definition.

	// If a non-member function is defined in a header included by multiple .cpp files, mark it `inline` to avoid ODR violations.
 
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

	// We can nest types inside a class when the type is closely related to the class.
	// Nested types must be declared before they are used in the class definition.
	// Outside the class, use `ClassName::NestedType` to access the nested type.

	// See `NestedClass.h` and `NestedClass.cpp` for an example.

	NestedClass nestedClass{};
	nestedClass.getColor();
	nestedClass.setColor(NestedClass::Red);
	nestedClass.getColor();
	nestedClass.printInfo();


    // We can access nested types with `ClassName::NestedType`.
	// Inside member functions we can use the nested names directly.

	// You can also have nested typedefs and type aliases. See `NestedClass2` for an example.

	NestedClass2 nestedClass2{ 5 };

    // -- 15.4 — Introduction to destructors --

	// Constructors initialize an object and its members.
	// A destructor performs cleanup before an object is destroyed.

	// Use a destructor to ensure resources are released or cleanup actions run when an object goes out of scope,
	// for example closing a connection or freeing memory.

	// See `deconstructorExample.h` and `deconstructorExample.cpp` for an example.

		// (commented out since it was doing weird stuff with io output might fix later)
	// deconstructorExample deconstructorExample{ 5, 5 };
	
	// we can see with the in the output that y is = 5 since whats what our constructor is provided to init y
	// then before the object is destroyed we set y to 1 as it must be set to one in this case to meet some condition

    // -- Implicit destructor --

	// If no user-defined destructor is provided, the compiler will generate one implicitly.
	// Similar to the implicit default constructor, the implicit destructor is fine when no custom cleanup is required.

    // -- 15.5 — Class templates with member functions --

	// Templates can be used for member variable types and for templated member functions.

	// See `tempMemberFuncClass.h`.

	TempFuncClass tempFuncClass{ 5,};

	tempFuncClass.setX(6);
	tempFuncClass.setX2(7);

	// Triad Quiz

	std::cout << "~~~~Triad Quiz~~~~\n";

	Triad<int, int, int> t1{ 1, 2, 3 };
	t1.print();
	std::cout << '\n';
	std::cout << t1.first() << '\n';

	using namespace std::literals::string_literals;
	const Triad t2{ 1, 2.3, "Hello"s };
	t2.print();
	std::cout << '\n';

    // A const `Triad` object must call a const member function. If `print` were not const, this would not compile.

    // -- 15.6 — Static member variables --

	// Static member variables are shared across all objects of a class.

	// Set or read them using the class name and `::`.
	StaticClass::m_x = 2;
	
	std::cout << "StaticClass's (static) member variable m_x = " << StaticClass::m_x << "\n";

    // Using a static member variable to assign IDs to class instances.

	StaticClass2 staticClass1{};
	StaticClass2 staticClass2{};

	// now we can check to see if there have there own ID

	staticClass1.CheckObjectID();
	staticClass2.CheckObjectID();

    // This demonstrates a shared static member used to provide a unique ID for each object created.
	// Note: `auto` and CTAD are not applicable to static members in the same way as for local variables.

	// -- 15.7 — Static member functions --


    // Inside a class body, a `friend` declaration grants access to private members to another class or function.

	// See `NonMemberFriend.h`.

	Stuff stuff{1};
	
	// calling non member function print
	print(stuff);

	int storeValue{};
	storeValue = getValue(stuff);

	std::cout << "StoreValue = " << storeValue;

    // We can see the non-member friend functions accessing the private member `m_value`.

	BeMyFriend beMyFriend{ 5 };
	BeMyFriend2 beMyFriend2{ 10 };

    // Using a non-member function that is a friend of both classes.
	// I needed to forward-declare `BeMyFriend2` so the friend declaration in `BeMyFriend` could reference the type.
	print(beMyFriend, beMyFriend2);

	// The `friend` keyword is useful, but prefer non-member functions when possible.
	// If a member function can be implemented as a non-member, prefer the non-member approach.
	


	return 0;
}
