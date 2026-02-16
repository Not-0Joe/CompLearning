#pragma once

// Example of a class with constexpr member functions and and a constexpr constructor

// if we want to make a constexpr object our constructors must also be marked constexpr
// we could make a non constexpr object and still call grather than as its duel use

class ConstexprClass
{
public:
	
	constexpr ConstexprClass() = default;

	constexpr ConstexprClass(int x, int y) : m_x{ x }, m_y{ y } {}

	// member function that is constexpr 
	constexpr int getGreater() const
	{
		return m_x > m_y ? m_x : m_y;
	}


private:
	int m_x = 0;
	int m_y = 0;
};

// inside of main write

// constexpr ConstexprClass constexprClass{ 5, 6 };
// std::cout << constexprClass.getGreater();
