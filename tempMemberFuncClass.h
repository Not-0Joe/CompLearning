#pragma once
#include <iostream>

// this header will contain the class used to demonstrate the use of templated member functions

// T will be whatever type we pass in this case int,double,float,short ect 

template <typename T>
class TempFuncClass
{
public:

    TempFuncClass() = default;
	TempFuncClass(T x) : m_x {x} {}

	// when we define a templated member function we don't need to define typename T
	// as it implicity uses the templated defintion at the top of the class
	T getX() const
	{
		std::cout << "Getting Value For X\n";
		return m_x;
	}
	
	void setX(T x)
	{
        std::cout << "Setting Value Of X\n";
		m_x = x;
		std::cout << "New Value Of X: " << m_x << "\n";

	}

	void setX2(T x);

private:
	T m_x{};
};

// if we define a templated class member function outside of the class is should be directly below the class
// when we define a templated member function outside of a class defintion we need to resupply the
// template parameters and the return types that is T in this case

// so template def 
// return type
// the class with it template paramter T in this case
// scope :: function name const if it applys

template <typename T>
void TempFuncClass<T>::setX2(T x)
{
    std::cout << "Setting Value Of X\n";
	m_x = x;
	std::cout << "New Value Of X: " << m_x << "\n";
}

// injected class name

// more or less we write short hand on our templated member functions can constructors
// so just TempFuncClass(T x) : m_x {x} {}
// and not TempFuncClass<T>(T x) : m_x {x} {}

// works either way