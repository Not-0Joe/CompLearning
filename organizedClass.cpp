#include "organizedClass.h"
#include <iostream>

// we include the header file of the class of the class we want to define the member functions of, 
// and then we can define the member functions in this .cpp file. This is a common practice in C++ to separate the declaration and definition of a class into a header file and a source file.

// unlike a non member function we need to specify the class name with :: as we can see below

OrganizedClass::OrganizedClass(int x) : m_x{ x } {}

void OrganizedClass::printX() const
{
	std::cout << "m_x = " << m_x << "\n";
}