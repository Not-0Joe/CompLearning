#pragma once
#include <iostream> 

// the explicit keword prevents the constructor from doing a converstion
// side note we would normaly not want a constructor printing anything

class Explicit
{
public:

	// defualt
	Explicit() = default;
	
	// use of explicit to prevent converstion
	explicit Explicit(int x) : m_x{ x }, m_y{ 0 }
	{
		std::cout << "explicit keyword constructor called\n";
	}

	// typical constructor to init member variables
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
