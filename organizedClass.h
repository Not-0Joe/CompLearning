#pragma once

// used to show how we can separate the declaration and definition of a class into a header file and a source file. This is a common practice in C++ to improve code organization and compilation times.
class OrganizedClass
{
public:

    // normally its ok to put trival member functions and constructors inside the class definition

    OrganizedClass() = default;
    // we will put the definition of this constructor in the .cpp file to show how we can separate the declaration and definition of a class.
    OrganizedClass(int x);
    // same with this member function, we will put the definition in the .cpp file.
    void printX() const;

private:
    int m_x = 0;
};

// for a small class like this, it may seem unnecessary to separate the declaration and definition into a header and source file, 
// but for larger classes with more member functions, it can help keep the code organized and easier to navigate.

// i am going to try and keep doing this habit to get used to the separation of declaration and definition, even for small classes,
// because it is a good habit to get into and it will make it easier to work with larger classes in the future.