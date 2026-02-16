#pragma once
#include <iostream>
#include <cmath>

/*Task 1

a) Write a class named Point2d. Point2d should contain two member variables of type double: m_x, and m_y, both defaulted to 0.0.

Provide a constructor and a print() function.*/

/*he following program should run:

   
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    // Point2d third{ 4.0 }; // should error if uncommented

    first.print();
    second.print();

*/

/*TASK 2 

b) Now add a member function named distanceTo() that takes another Point2d as a parameter, and calculates the distance between them. Given two points (x1, y1) and (x2, y2), the distance between them can be calculated using the formula
std::sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)). The std::sqrt function lives in header cmath.*/




class Point2d
{
public:

    Point2d() = default;

    Point2d(double x, double y) : m_x{ x }, m_y{ y } {}

    void print() const
    {
        std::cout << "M_X = " << m_x << " M_Y = " << m_y << "\n";
    }

    double distanceTo(const Point2d point) const 
    {
        return std::sqrt((m_x - point.m_x) * (m_x - point.m_x) + (m_y - point.m_y) * (m_y - point.m_y));
    }


private:
    
    double m_x = 0.0;
    double m_y = 0.0;


};

// convert a the fraction struct to a class, and all the functions it uses into a member functions

class Fraction
{
public:


    Fraction() = default;

    Fraction(int x, int y) : m_numerator{ x }, m_denmoninator{ y } {}

    explicit Fraction(int x) : m_numerator {x}, m_denmoninator {0} {}

    int Multiply(const Fraction f) const
    {
        return m_numerator * f.m_denmoninator, m_denmoninator* f.m_denmoninator;
    }

    void printFraction() const
    {
        std::cout << m_numerator << "/" << m_denmoninator << "\n";
    }
    

private:
    
    int m_numerator = 0;
    int m_denmoninator = 1;
};