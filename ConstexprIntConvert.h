#pragma once


void someFunc(unsigned int a)
{

}

constexpr int sign = 5;

// sign is implicity converted from int to unsigned int since sign is constexpr, its not consider an narrowing
unsigned int unsign = sign;  