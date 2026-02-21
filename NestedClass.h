#pragma once

class NestedClass
{
public:

	// when we name a nested type we should try and avoid naming it the same as the class that encloses it
	// if we were to access it with a name like NestedClassColor it would look like this

	// NestedClass::NestedClassColor color = NestedClass::NestedClassColor::Red; which is a bit redundant and not very readable
	// this is much cleaner NestedClass::Color 

	enum Color
	{
		NoColor,
		Red,
		Green,
		Blue,
	};

	NestedClass() = default;

	NestedClass(Color color, int x);

	NestedClass(Color color);

	NestedClass(int x);

	void print() const;

	void getColor() const;

	void setColor(Color color);

	void printInfo() const;


private:
	Color m_color = NoColor;
	int m_x = 0;
};

// nested type alias

class NestedClass2
{
public:
	using coolINT = int;
	// yes i know this is cursed 
	NestedClass2(coolINT x) : m_coolInt{ x } {}

private:
	coolINT m_coolInt = 0;
};

// coolINT can be used in place of int 