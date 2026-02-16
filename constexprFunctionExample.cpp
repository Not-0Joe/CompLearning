#include <iostream>


// the constexpr keyword means that the function must be able to be evaluated at compile time
// this does not mean that the complier will evaluate it at complie time just that it must be possible

// for example if this function asked for an imput at runtime it would not complie

constexpr int grater(int x, int y)
{
	return x > y ? x : y;
}