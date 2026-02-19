#pragma once

class NestedClass
{
public:

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