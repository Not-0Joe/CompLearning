#pragma once
#include <iostream> 

// use to show how a member function defined inside a class is implicity inline and that a non member function defined in a header file should be marked inline


class InlineClass
{
public:

	InlineClass() = default;

	InlineClass(int x) : m_x{ x } {}

	// implicitly inline because it is defined inside the class definition
	int getX() const
	{
		return m_x;
	}

private:
	int m_x = 0;
};

// since this is a non member function that we defined in a header file we should mark it as inline to avoid a linker error
// as we might include this header file into multiple cpp files.
inline void printX(const InlineClass& c)
{
	std::cout << "m_x = " << c.getX() << "\n";
}