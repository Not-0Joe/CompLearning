#pragma once
#include <iostream>
// this header will be used to define the StaticClass to for examples on static variables and static member functions


// static member variables are shared between class objects meaning if we created two Static class's they would be able to access
// eatch other variable since its the same


// statics variables exist before and beyond the lifetime of the class the are like global variables inside the scope of the class
// like they were wrapped in a namespace

// since they exsist independently of any class object they can be accessed using the class name and scope ::
// static members defined inside a class are not subject to access controlls meaning even if its marked private
// it can still be accessed via the class name and ::

// for non-templated if the class is defined inside a header file (like this one) the static member is defined
// inside a related cpp file Static.cpp in this case, or made inline and placed below the class defintion

// do not place static member variables inside a header file (like gobal variables) if its included more than once you will get a linker error

// see StaticClass.cpp


class StaticClass
{
public:
	// forward dec more or less
	static int m_x;

private:
};

// i am going to make a second class to use how u might use a static member variable inside of a class

// we want to provide a id to every created class object of type StaticClass2
// may not be super relevant to my studys but good to know

class StaticClass2
{
public:

	StaticClass2() : thisObjectID{ ClassObjectID++ } {}

	void CheckObjectID() const
	{
		std::cout << "Current Object ID: " << thisObjectID << "\n";
	}



private:

	// bypass access controls but in this context it does not really matter
	static inline int ClassObjectID{0};
	int thisObjectID{0};


};
