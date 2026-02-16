#include <iostream>

// The constexpr keyword means that the function must be able to be evaluated at compile time.
// This does not mean that the compiler will evaluate it at compile time, just that it 
// must be possible for it to do so.
// For example: if this function requested user input at runtime, it would not compile.

constexpr int greater(int x, int y)
{
    return (x > y) ? x : y;
}