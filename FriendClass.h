#pragma once
#include <iostream>

// going to show the use of a friend class using 2 class's a class with data, and a class to display that data

class Data
{
public:

	Data() = default;
	Data(int id, int value) : m_dataID{ id }, m_dataValue{ value } {}

	// a friend declaration acts also acts as a forward declaration for the class being friended
	friend class Display;

	void setID(int id)
	{
		std::cout << "Setting ID:\n";
		m_dataID = id;
	}
	void setValue(int value)
	{
		std::cout << "Setting Value:\n";
		m_dataValue = value;
	}

private:
	int m_dataID = 0;
	int m_dataValue = 0;
};

// as we can see the above class has no member functions to display data we can let another class handle that
// data made display its friend so it can now use its private members

// considering how simple this class is it would be better to just make these non member functions
// but just doing this to showcase the use of a friend class

class Display
{
public:

	void displayID(const Data& d) const
	{
		std::cout << "Data Class m_dataID = " << d.m_dataID << "\n";
	}
	
	void displayValue(const Data& d) const
	{
		std::cout << "Data Class m_dataValue = " << d.m_dataValue << "\n";
	}
};