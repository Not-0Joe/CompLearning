#pragma once

/*
*Question #1

Write a class template named Triad that has 3 private data members 
with independent type template parameters. The class should have a constructor, 
access functions, and a print() member function that is defined outside the class.*/



/*
	Triad<int, int, int> t1{ 1, 2, 3 };
	t1.print();
	std::cout << '\n';
	std::cout << t1.first() << '\n';

	using namespace std::literals::string_literals;
	const Triad t2{ 1, 2.3, "Hello"s };
	t2.print();
	std::cout << '\n';*/

template <typename T, typename U, typename P>
class Triad
{
public:

	Triad(T x, U y, P z) : m_x {x}, m_y {y}, m_z {z} {}

	T first() const
	{
		return m_x;
	}

	void print() const;

private:
	T m_x{};
	U m_y{};
	P m_z{};

};

// defined outside of class as asked
template <typename T, typename U, typename P>
void Triad<T,U,P>::print() const
{
	std::cout << "[ " << m_x << ", " << m_y << ", " << m_z << " ]";
}