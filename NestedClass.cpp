#include "NestedClass.h"
#include <iostream>

// NestedClass.h constructors and member functions

NestedClass::NestedClass(int x) : NestedClass(NoColor, x) {}

NestedClass::NestedClass(Color color) : NestedClass(color, 0) {}

NestedClass::NestedClass(Color color, int x) : m_color{ color }, m_x{ x } {}

void NestedClass::print() const
{
	std::cout << "TEST:\n";
}

void NestedClass::getColor() const
{
	std::cout << "Member m_color = " << m_color << "\n";
}

void NestedClass::setColor(Color color)
{
	m_color = color;
}

// not ideal would be better to have a function that takes an enum and returns its corresponding string name, 
// with a switch statement or something like that
void NestedClass::printInfo() const
{
	std::cout << "Colors :\n";
	std::cout << "NoColor = " << NoColor << "\n";
	std::cout << "Red = " << Red << "\n";
	std::cout << "Green = " << Green << "\n";
	std::cout << "Blue = " << Blue << "\n";

}