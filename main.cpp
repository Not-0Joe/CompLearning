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
#include "PassingVec.h"
#include "SelfTest.h"





int main()
{
    // Testing if passing an int to a function that takes a 'Convert' class 
	// will trigger the use of the user-defined converting constructor.
	std::cout << "\n===== Convert / Converting-constructor test =====\n";
	convertPrint(5);

    // `convertPrint` is called with an int argument. Since `convertPrint` expects a `Convert` object,
	// the compiler looks for user-defined converting constructors. It finds `Convert(int)`,
	// converts the int into a `Convert` object, and passes that object as the argument.

    // --- Testing the use of a class with the 'explicit' keyword ---
	std::cout << "\n===== Explicit constructor test =====\n";

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
	std::cout << "\n===== Constexpr class test =====\n";

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
	std::cout << "\n===== Chapter 14 quiz =====\n";

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
	std::cout << "\n===== This pointer & chaining (Chapter 15.1) =====\n";

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
	std::cout << "\n===== Classes and header files (Chapter 15.2) =====\n";

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
	std::cout << "\n===== Inline member functions =====\n";

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
	std::cout << "\n===== Triad quiz =====\n";
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
	std::cout << "\n===== Static member variables (Chapter 15.6) =====\n";

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
	std::cout << "\n===== Static member functions (Chapter 15.7) =====\n";

	// Inside a class body, a `friend` declaration grants access to private members to another class or function.

	// See `NonMemberFriend.h`.

    Stuff stuff{1};

	std::cout << "\n----- Non-member friend functions -----\n";
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
	std::cout << "\n===== Friend classes & member functions (Chapter 15.9) =====\n";

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
	std::cout << "\n----- Friend member functions -----\n";

	// See `FriendFunction.h`.

	// I'll need to come back to this at some point. I hit a wall here and don't think the amount of boilerplate
	// code needed to make one or more member functions friends of another class is worth the minor improvement in
	// separation and data hiding. Unless I learn a good reason to do this, I'll friend the entire class.

	
    // --- Chapter 15 Quiz ---
	std::cout << "\n===== Chapter 15 quiz =====\n";

	Monster skeleton{ Monster::skeleton, "Bones", "*rattle*", 4 };
	skeleton.print();

	Monster vampire{ Monster::vampire, "Nibblez", "*hiss*", 0 };
	vampire.print();

    // Did not finish the full implementation as the test requested, but I have more or less done this already in another project.

    // -- 16.1 — Introduction to containers and arrays -- (after 16 chapter we get onto arrays lol)
	std::cout << "\n===== Containers & arrays (Chapter 16.1) =====\n";

	// containers 

	// a container is a data type that provides storage of a large number of unnamed elements
	// a string is a container it with unnamed elements the chars

	// string message = "hello"  the name of the container is "message" and the unnamed elements are h,e,l,l,o

	// the length of a container is the number of elements in the container so the length of our message would be 5	

	// we can show this with string as it provides a length method to get the total number of elements

	std::string message = "Hello";
	std::cout << "length of the container 'message' = " << message.length() << "\n";

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

	std::cout << "\n----- Constructing vectors -----\n";

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

	// for quiz
	getUserSum();

	// -- 16.3 — std::vector and the unsigned length and subscript problem --

	/*Let’s start with an assertion: 
	the data type used for subscripting an array should match the data type used for storing the length of the array. This is so that all elements in the longest possible array can be indexed, and no more.
	As Bjarne Stroustrup recalls, when the container classes in the C++ standard library was being designed (circa 1997), the designers had to choose whether to make the length (and array subscripts) signed or unsigned. They chose to make them unsigned.
	The reasons given for this: the subscripts of the standard library array types can’t be negative, using an unsigned type allows arrays of greater length due to the extra bit (something that was important in the 16-bit days), and range-checking the subscript requires one conditional check instead of two (since no check was needed to ensure the index was less than 0).
	In retrospect, this is generally regarded as having been the wrong choice. We now understand that using unsigned values to try to enforce non-negativity doesn’t work due to the implicit conversion rules (since a negative signed integer will just implicitly convert to a large unsigned integer, producing a garbage result), the extra bit of range typically isn’t needed on 32-bit or 64-bit systems (since you probably aren’t creating arrays with more than 2 billion elements), and the commonly used operator[] doesn’t do range-checking anyway.
	In lesson 4.5 -- Unsigned integers, and why to avoid them, we discussed the reasons why we prefer to use signed values to hold quantities. We also noted that mixing signed and unsigned values is a recipe for unexpected behavior. So the fact that the standard library container classes use unsigned values for the length (and indices) is problematic, as it makes it impossible to avoid unsigned values when using these types.*/


    // -- A review: sign conversions are narrowing conversions, except when constexpr --
	std::cout << "\n----- Sign conversions & constexpr -----\n";

	// sign converstion is considerd narrowing,  since unsigned to signed would result in the loss of data
	// when such convertion is prefromed at runtime the complier will issue an error in contexts where narrowing is disallowed
	// like direct list init {}

	/*void foo(unsigned int) {}

    int s { 5 };

    [[maybe_unused]] unsigned int u { s }; // compile error: list initialization disallows narrowing conversion
    foo(s);                                // possible warning: copy initialization allows narrowing conversion*/

	// but if the sign converted is constexpr and can be converted to an equivalent value its not considerd narrowing since the complier
	// can garantee that it will be a safe converstion 

	// see ConstexprIntConvert.h for an example 

	//  -- The length and indices of std::vector have type size_type ---
	
	// std::size_t is a typedef for some large unsigned intergral type, unsigned long, or unsigned long long
	// eatch of the standard libs container class's defines a nested typedef member named size_type, size_type is an alias for the type used
	// for the length and indices of the container size_type is almost always an alias for std::size_t 

    // --- Getting the length of a std::vector using the size() member function or std::size() ---
	std::cout << "\n----- Vector size() examples -----\n";

	// we can use the size() member function to return the length of the arrary
	std::vector<int> v2{ 1,2,3 };
	std::cout << "length of v2 = " << v2.size() << "\n";

	// if we want to store the length of an array inside of a variable
	// it would result in a sign converstion simple way to not get an error would be to use static_cast

	int lengthOfV2 = static_cast<int>(v2.size());

	std::cout << lengthOfV2 << "\n";

    // accessing array elements using the at() member function does runtime bounds checking

	// should print 3
	std::cout << v2.at(2) << "\n";

    // while at() does bounds checking and is safer, it is slower than [] so [] is used most of the time

	// we can do indexing with a constexper singed int

	constexpr int index = 1;
	std::cout << v2[index]; // does implict convert to std::size_t not a narrowing since the constxper

	// indexing with non constexper value

	std::size_t index2 = 0;
	// since [] expects an index of type std::size_t no converstion is needed
	std::cout << v2[index2];

	// but we want to avoid using unsiged types to hold values when possible so this is not ideal

	// when our subscript type is a non-constexpr signed value we have problems

	int index3 = 1;
	std::cout << v2[index3] << "\n";



	// the complier considers this narrowing at runtime, even tho a non-negative int conveted to an unsigned int would safely convert
	// the complier can produce a warning, and if u end up indexing like this lot it can produce lots of warnings

	// we can use static_cast to cast the int into a std::size_t but that also clutters the code base so its more ideal to
	// make a the index variable of std::size_t and only use it for indexing to prevent warning

    // Doing quiz for 16.3 

	std::cout << "\n===== Vector quiz (Chapter 16.3) =====\n";

	/*Question #1

	Initialize a std::vector with the following values: ‘h’, ‘e’, ‘l’, ‘l’, ‘o’. Then print the length of the array (use std::size()). Finally, print the value of the element with index 1 using the subscript operator and the at() member function.	
	The program should output the following:*/

	/*The array has 5 elements.
	ee*/

    std::vector<char> vecQuiz{ 'h','e','l','l','0' };
	std::cout << "the array has " << vecQuiz.size() << " elements\n";
	std::cout << "vecQuiz[1] = " << vecQuiz[1] << "  vecQuiz.at(1) = " << vecQuiz.at(1) << "\n";

	/*Question #2

	a) What is size_type and what is it used for?*/

	// it is a type alias for std::stize_t used to store the length and indices

	/*b) What type does size_type default to? Is it signed or unsigned?*/

	// unsigned

	/*c) Which functions to get the length of a container return size_type?*/

	// size()


    // -- 16.4 — Passing std::vector -- 
	std::cout << "\n===== Passing vectors (Chapter 16.4) =====\n";

	// see PassingVec.h

	passMeVecT(chimp);
	passMeVecT(chimp2);

	// should output 1 and 1.5 


	std::cout << "\n===== Passing vectors (Chapter 16.4) QUIZ RESULTS  =====\n";

	std::vector PassQuiz{ 0, 1, 2, 3, 4 };
	printElement(PassQuiz, 2);
	printElement(PassQuiz, 5);

	std::vector PassQuiz2{ 1.1, 2.2, 3.3 };
	printElement(PassQuiz2, 0);
	printElement(PassQuiz2, -1);


	std::cout << "===== 16.5 — Returning std::vector, and an introduction to move semantics ==== \n";

	// holy molly a whole lot of technical yappin for that section

	// more or less the ownership of an object can be trasfered to another object
	// and vectors retrun by value, using move samantics trasfering the ownership and elements to a the new object
	// can trasfering ownership is faster than copying the whole vector

	// so when its possible the complier will use move samantics 

	// moving on if this is for some reason relevent later i will revist it but for that sake of time im moveing on

	std::cout << "===== 16.6 — Arrays and loops ==== \n";

	// we can use for loops to iterate over an array 
	
	// lets say we want the Cumulative Sum of 100 elements and we want to add the values to every element 0 = 1, 1 = 2 and so on
	std::vector<int> sumVec(100);
	std::size_t length = sumVec.size();

	int cumulativeSum{ 0 };

	// for (initialization; condition; update)
	for (std::size_t index{ 0 }; index < length; index++)
	{
		// 1. Set the value in the vector
		sumVec[index] = static_cast<int>(index);

		// 2. Immediately add that value to our running total
		cumulativeSum += sumVec[index];
	}

	std::cout << "Total Sum: " << cumulativeSum << "\n";
	
	 
	// doing a self test inside of SelfTest.h, and the test for 16.6 also

	std::vector<int> dimSum{ 5, 35, 56, 67 };
	std::vector <double> dimSumYum{ 4.3, 3.7, 77.5, 12.6 };

	std::cout << "Results of Self Test:\n";

	std::cout << "sum of dimSum = " << GetVectorSum(dimSum) << "\n";
	std::cout << "sum of dimSumYum = " << GetVectorSum(dimSumYum) << "\n";

	// chaper 16.6 quiz

	std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

	std::cout << "Result of Question #1 \n";
	PrintVecQuiz(arr);

	arrSort(arr);

	std::cout << "\n ===== RESULTS OF EXTRA CREDIT QUIZ =====\n";

	// make function able to handle other types like a double

	std::vector<double> dArray{ 5.3, 36.5, 6.4, 7.1, 4.6, 12.2 };

	arraySortv2(dArray);

	return 0;
}
