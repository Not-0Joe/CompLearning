#pragma once

// see deconstructorExample.cpp for the definition of the member functions of this class
// again for a simple class or just for the constructors and deconstructor we can define them inside the class definition
// i am just doing it this way to practice separating the declaration and definition of a class into a header file and a source file


class deconstructorExample
{
public:
	deconstructorExample() = default;

	deconstructorExample(int x, int y);

	deconstructorExample(int x);

	~deconstructorExample();

	// lets say that for some reason m_y must be set to 1 before the object is destroyed
	void setY();

	void checkY() const;

	



private:
	int m_x = 0;
	int m_y = 0;
};