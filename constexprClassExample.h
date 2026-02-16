#pragma once

// Example of a class with constexpr member functions and a constexpr constructor.
// If we want to create a constexpr object, our constructors must also be marked constexpr.
// We can still create a non-constexpr object and call getGreater() because 
// constexpr functions are "dual-use" (they work at both compile-time and runtime).
class ConstexprClass
{
public:

	// Default constructor marked constexpr to allow compile-time default initialization.
	constexpr ConstexprClass() = default;

	// Constructor marked constexpr to allow compile-time initialization with values.
	constexpr ConstexprClass(int x, int y) : m_x{ x }, m_y{ y } {}

	// Member function that is constexpr and const.
	// This allows it to be evaluated at compile-time when called on constexpr objects.
	constexpr int getGreater() const
	{
		return (m_x > m_y) ? m_x : m_y;
	}

private:
	int m_x = 0;
	int m_y = 0;
};

// Usage in main:
// constexpr ConstexprClass constexprClass{ 5, 6 };
// std::cout << constexprClass.getGreater();