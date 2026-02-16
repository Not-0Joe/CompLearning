#pragma once

#include <iostream>

// Demonstrating the use of a user-defined converting constructor.
class Convert
{
public:

	// This is a converting constructor because it is not marked 'explicit'.
	// It allows the compiler to implicitly turn an int into a Convert object.
	Convert(int x) : m_x{ x }, m_y{ 0 }
	{
		std::cout << "Converting constructor called\n";
	}

	// Standard constructor to initialize both member variables.
	Convert(int x, int y) : m_x{ x }, m_y{ y } {}

	int getX() const
	{
		return m_x;
	}

	int getY() const
	{
		return m_y;
	}

private:
	int m_x = 0;
	int m_y = 0;
};

// Function prototype: takes a Convert object by value.
void convertPrint(Convert c);