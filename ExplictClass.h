#pragma once

#include <iostream> 

// The 'explicit' keyword prevents the compiler from performing an implicit conversion.
// Side note: We would normally not want a constructor printing anything to the console.
class Explicit
{
public:

	// Default constructor
	Explicit() = default;

	// Use of 'explicit' to prevent implicit type conversion
	explicit Explicit(int x) : m_x{ x }, m_y{ 0 }
	{
		std::cout << "Explicit keyword constructor called\n";
	}

	// Typical constructor to initialize member variables
	Explicit(int x, int y) : m_x{ x }, m_y{ y } {}

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

void convertExplictPrint(const Explicit& e);
