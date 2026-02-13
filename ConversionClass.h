#pragma once
#include <iostream>
// show the use of a user-defined converting constructor

class Convert
{
public:

	Convert(int x) : m_x{ x }, m_y {0} 
	{
		std::cout << "Converting constructor called\n";
	}

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

// function prototype
void convertPrint(Convert c);