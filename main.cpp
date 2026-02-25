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
#include "FriendClass.h"
#include "FriendFunction.h"
#include "Chapter15Quiz.h"
#include <vector>
#include "Vector.h"





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

    // A non-constexpr object calling a constexpr member function.
	// This works because constexpr member functions are "dual-use," meaning
	// they can be called by both constexpr and non-constexpr objects.
	ConstexprClass constexprClass2{ 6, 7 };
	std::cout << constexprClass2.getGreater() << "\n";

	// --- CHAPTER 14 QUIZ ---

	Point2d first{};
	Point2d second{ 3.0, 4.0 };

    // Point2d third{ 4.0 }; // Should error if uncommented (requires two arguments or default constructor).

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

    // Inside every member function, the keyword `this` is a pointer to the implicit object.

	// `this` points to the implicit object and `->` is used to access its members.

	// The compiler implicitly adds `this->` where needed.
	Simple simple{ 5 };
    // we explicitly add `this->` where needed
	Simple2 simple2{ 6 };
	// using this-> to disambiguate
	simple2.printData(5);

    // Returning `*this` from a member function enables chaining multiple calls on the same object.
	Chains chains{ 5 };
	chains.addX(10).addX(10).printX();

    // Using `*this` to reset an object to its default state
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
	// but this demonstrates separating a class declaration from its definitions.

    // -- inline member functions --

	// Functions are not ODR-exempt: if a non-inline function is defined in a header included by multiple .cpp files,
	// the linker will see multiple definitions and fail. Member functions defined inside a class are implicitly inline,
	// so they can be defined in headers safely.

    // When the compiler inlines a function, it may replace the call with the function body for performance.

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

	// Use a destructor to ensure resources are released or that cleanup actions run when an object goes out of scope,
	// for example closing a connection or freeing memory.

	// See `deconstructorExample.h` and `deconstructorExample.cpp` for an example.

		// (commented out since it was doing weird stuff with io output might fix later)
	// deconstructorExample deconstructorExample{ 5, 5 };
	
    // We can see in the output that `y` is 5 because our constructor initialized `y` to that value.
	// Before the object is destroyed we set `y` to 1 to satisfy a required condition.

    // -- Implicit destructor --

	// If no user-defined destructor is provided, the compiler will generate one implicitly.
	// Like the implicit default constructor, the implicit destructor is fine when no custom cleanup is required.

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

    // Now we can check whether each object has its own ID

	staticClass1.CheckObjectID();
	staticClass2.CheckObjectID();

    // This demonstrates a shared static member used to provide a unique ID for each object created.
	// Note: `auto` and CTAD behave differently for static members than for local variables.

    // -- 15.7 — Static member functions --

	// Inside a class body, a `friend` declaration grants access to private members to another class or function.

	// See `NonMemberFriend.h`.

	Stuff stuff{1};
	
    // Calling the non-member function `print`.
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
	
    // -- 15.9 — Friend classes and friend member functions --

	// See `FriendClass.h`.

	Data data{ 0,0 };

	data.setID(5);
	data.setValue(10);

	Display display{};

	display.displayID(data);
	display.displayValue(data);

    // Friendship is one-sided: even though `Display` is a friend of `Data` and can access its private members,
	// that does not mean `Data` is a friend of `Display`. `Data` cannot access `Display`'s members unless
	// `Display` explicitly grants friendship.
	// Class friendship is also not transitive: if class A is a friend of B, and B is a friend of C, that does not make A a friend of C.

    // Friend member functions

	// See `FriendFunction.h`.

    // I'll need to come back to this at some point. I hit a wall here and don't think the amount of boilerplate
	// code needed to make one or more member functions friends of another class is worth the minor improvement in
	// separation and data hiding. Unless I learn a good reason to do this, I'll friend the entire class.

	
    // --- Chapter 15 Quiz ---

	Monster skeleton{ Monster::skeleton, "Bones", "*rattle*", 4 };
	skeleton.print();

	Monster vampire{ Monster::vampire, "Nibblez", "*hiss*", 0 };
	vampire.print();

    // Did not finish the full implementation as the test requested, but I have more or less done this already in another project.

	// -- 16.1 — Introduction to containers and arrays -- (after 16 chapter we get onto arrays lol)


	// containers 

	// a container is a data type that provides storage of a large number of unnamed elements
	// a string is a container it with unnamed elements the chars

	// string message = "hello"  the name of the container is "message" and the unnamed elements are h,e,l,l,o

	// the length of a container is the number of elements in the container so the length of our message would be 5	

	// we can show this with string as it provides a length method to get the total number of elements

	std::string message = "Hello";
	std::cout << "lenth of the container message = " << message.length() << "\n";

	// size is also used when descripting the ammout of elements in a container but we will perfer to use length when refering to the
	// total number of elements inside of a container

	// like a carton of eggs in real life (a container) you can preform oporations on it like picking a certain egg
	// removing an egg, adding an egg ect
	// containers in c++ have similar functions we can use

	// containers inside of c++ are homogenous meaning the elements of a container are required to be the same type
	// containers are mostly implemented with class templates so we dont need to make a new container to have elements of a diffent type

	// arrays

	// an array	is a container that stores data contiguously meaning eatch element is placed beside one another in memory with no gaps
	// there are three types of arrys C sytle arrays, the standard array std::array, and std::vector

	// we still start with a std::vector array

	// std::vector is defined inside of the <vector> header so we will need to include it to make use of them 
	// vector is defined as a class templated so we will need to supply the templated type we would like to use

	std::vector<int> empty{};

	// type is vector<int> to an array of int elements name is empty{} and it contains no elements
	// we can init a vector with a list of values using list init inside of {}

	std::vector<int> myVector{ 1,2,3,4,5 };
	std::vector myOtherVector{ 'a','b','c' };

	// we have explicity made myVector hold elements of type int
	// and for myOtherVector we are using CTAD the complier will see its a list of char litreals and make it a char vector

	// containers have a special constructor called the list constructor that does 3 things 
		/*
			Ensures the container has enough storage to hold all the initialization values (if needed).
			Sets the length of the container to the number of elements in the initializer list (if needed).
			Initializes the elements to the values in the initializer list (in sequential order).
		
		*/

	// Accessing array elements using the subscript operator []

	// arrarys index starts at 0 so the int value 1, is at index [0]
	// when we access an element in this way it returns a refence to the element at that index
	// arrary's start the element count at index 0 

	// so element 1 is at index 0

	std::cout << "Element 1 value = " << myVector[0] << "\t" << "Index[0] = " << myVector[0] << "\n";
	std::cout << "Element 2 value = " << myVector[1] << "\t" << "Index[1] = " << myVector[1] << "\n";
	std::cout << "Element 3 value = " << myVector[2] << "\t" << "Index[2] = " << myVector[2] << "\n";
	std::cout << "Element 4 value = " << myVector[3] << "\t" << "Index[3] = " << myVector[3] << "\n";

	// when we access an arry we must access 0 to N-1 meaning we must access within the bounds of the array
	// the [] oporator does no bounds checking so if we try to access and index outside of the array it results in undefined behavior

	// lets test it

	std::vector testArry{ 1,2,3 };
	 // std::cout << testArry[3];

	// it asserts out 

	// arrays are placed beside one another in memory with no gaps between them
	// we can show this

	std::vector<int> memoryArray{ 1,2,3,4,5 }; 
	// we know that an int is 4 bytes so they will be 4 bytes apart

	std::cout << &memoryArray[0] << "\n";
	std::cout << &memoryArray[1] << "\n";
	std::cout << &memoryArray[2] << "\n";
	std::cout << &memoryArray[3] << "\n";
	std::cout << &memoryArray[4] << "\n";

	// Constructing a std::vector of a specific length

	// what if we wanted to make an array that holds 100 int elements
	// it would be really annoying and not practical to use an init list since we would need to type of 100 values
	
	// std::vector has an explicit constructor (explicit std::vector<T>(std::size_t)
	// T will be the type we define <int>, <double> ect, and std::size_t will be the length of the array

	std::vector<short> largeArry(100);
	
	// we need to take a moment to understand the diffrent types of initlzation

	// there are four core ways to initialize a variable this will cover all 4

	// Default Initialization
	// the value is undefined avoid it just holds a garbage value prone to error
	int x; 

	// Copy Initialization
	// the complier takes the value and copy's it into the variable, the 5 is then destroyed
	int x2 = 5;

	// Direct Initialization
	// permits explict converstion
	// removes the = sign
	// can narrow (data loss) double to int would drop the fraction 1.1 becomes 1
	int x3(10);

	// Direct List Initialization:
	// prevents narrowing
	// will init to 0 if left empty
	int x4{ 5 };

	// now for arrarys we need to understand some things

	// Non-empty initializer lists prefer list constructors
	// consider std::vector<int> vec{10}

    // Ambiguity: what does `std::vector<int> v{10};` mean?
	// - As a brace-initializer it prefers the initializer-list constructor, so `std::vector<int> v{10};`
	//   constructs a vector with one element whose value is 10.
	// - To construct a vector with 10 default-initialized elements (zeros for `int`) use the
	//   size constructor with parentheses: `std::vector<int> v(10);`.
	// 
	// Recommendation: write your intent explicitly — use braces for element lists and
	// parentheses for a size-based constructor.

	// so {value} = one element holding the value
	// if we wanted more elements in the list we can just add them {value, value2, value3} and so on
	// and (value) = value is the number of defualt-value init elements

	// side note direct init is not allowed for member defualt initzers so inside a class if we wanted to init a vector

	// if we were inside a class
	// std::vector<int> v{ std::vector<int>(8) };

	// creates a int arrary with a size of 8 of init v

	// --- std::vector can be made const --- 

	const std::vector<int> v{ 1,2,3 }; 
	// const vectors must be init when created, and there elements of a const vector can not be modified
	// vectors can not be made constexpr, so if we need an arrary to be constexpr, use std::array

	// will put the implementation of quiz inside of vector.h class


	getUserSum();




	return 0;
}
