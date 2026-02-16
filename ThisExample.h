#pragma once
#include <iostream>

// we will define a small class to show how this is implicity added when we call a member function on an object.
// it is also added to when we access a member variable of an object.

// this-> implicity added when we call a member function on an object, and when we access a member variable of an object.
class Simple
{
public:

	Simple() = default;
	Simple(int x) : m_x{ x } {}

	void setX()
	{
		// complier implicitly adds 'this->' to the left of m_x, so "this" is the same as this->
		m_x = 5;
	}

private:
	int m_x = 0;
};

class Simple2
{
public:

	Simple2() = default;
	Simple2(int x) : m_x{ x } {}

	void setX()
	{
		// this is the same as m_x = 5; here we are explicitly adding the this-> pointer
		this->m_x = 5;
	}

	// we would normally avoid explicity addin this-> to every member variable access, but it can be useful in some cases, 
	// such as when we have a parameter with the same name as a member variable.

	void printData(int m_data) const
	{
		// here we have a parameter named m_data and a member variable named m_data so we can use this-> to disambiguate between the two.
		std::cout << "Parameter m_data: " << m_data << "\n";
		std::cout << "Member variable m_data: " << this->m_data << "\n";
	}

private:
	int m_x = 0;
	int m_data = 0;
};

class Chains
{
public:

	Chains() = default;
	Chains(int x) : m_x{ x } {}

	// returning *this allows us to chain member function calls together.
	// return type is a refence to the current object, and we return *this, *this means we are dereferencing
	// and this is a pointer to the current object, so we are returning a reference to the current object


	Chains& addX(int x)
	{
		m_x += x;
		return *this;
	}

	Chains& printX()
	{
		std::cout << "X: " << m_x << "\n";
		return *this;
	}

	Chains& resetObject()
	{
		// create a new default object and assign it to the current object, this will reset all member variables to their default values.
		return *this = {};
	}
	

private:
	int m_x = 0;
};