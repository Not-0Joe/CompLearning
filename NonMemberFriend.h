#pragma once

// show the use of the friend keyword
#include <iostream>

// forward declare so friend declarations can reference the other class

class BeMyFriend2;

class Stuff
{
private:
	int m_value{};


public:

	Stuff() = default;

	Stuff(int x) : m_value{ x } {}

	friend void setValue(Stuff& s, int x);

	friend void print(const Stuff& s);

	// we can also define a non-member function inside the class 

	friend const int getValue(const Stuff& s)
	{
		std::cout << "Returning m_value to caller\n";
		return s.m_value;
	}

};

// set value is able to use m_value even tho its private since its a friend member function
void setValue(Stuff& s, int x)
{
	s.m_value = x;
}
// print value of private member 
void print(const Stuff& s)
{
	std::cout << "Value of m_value: " << s.m_value << "\n";
}

// a function can be a friend to more than one class at a time

// both of the class's are friends of print

class BeMyFriend
{
public:

	explicit BeMyFriend(int x) : m_x{x} {}

	friend void print(const BeMyFriend& b1, const BeMyFriend2& b2);

private:
	int m_x{0};
};

class BeMyFriend2
{
public:

	explicit BeMyFriend2(int x) : m_x{ x } {}

 friend void print(const BeMyFriend& b1, const BeMyFriend2& b2);

private:
	int m_x{0};
};

void print(const BeMyFriend& b1, const BeMyFriend2& b2)
{
  std::cout << "b1 = " << b1.m_x << ", b2 = " << b2.m_x << "\n";
}