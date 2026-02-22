#include "deconstructorExample.h"
#include <iostream>


deconstructorExample::deconstructorExample(int x, int y) : m_x{ x }, m_y{ y } {}

deconstructorExample::deconstructorExample(int x) : deconstructorExample(x, 0) {}

// remember we talked about naming coventiions for member functions, 
// we should try to name them in a way that makes it clear what they do but as u can see this naming is a little bit confusing 
void deconstructorExample::setY()
{
	m_y = 1;
}

// we will use our deconstructor to call this function after setY
void deconstructorExample::checkY() const
{
  std::cout << "Checking m_y value: this should be 1 before the object is destroyed\n";
	std::cout << "m_y = " << m_y << "\n";
}

deconstructorExample::~deconstructorExample()
{
	std::cout << "Calling setY()...\n";
	setY();
	std::cout << "Calling checkY()...\n";
	checkY();
}

// now we can insure that the condition y = 1 will always be ture before the object is destroyed
// this is very important if we were dealing with memory without a deconstructor we could allocate memory and never
// unallocate it leading to the program slowly eating memory untill it crashes or undefined behavior 

