#pragma once

class OrganizedClass
{
public:

	OrganizedClass() = default;

	// we will put the definition of this constructor in the .cpp file to show how we can separate the declaration and definition of a class.
	OrganizedClass(int x);
	// same with this member function, we will put the definition in the .cpp file.
	void printX() const;

private:
	int m_x = 0;
};