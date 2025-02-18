#include "calc.h"

#include <iostream>

int Calc::Add(int a, int b)
{
    return a + b;
};

int Calc::Sub(int a, int b)
{
    return a - b;
};

int Calc::Multiply(int a, int b)
{
    return a * b;
};

int Calc::Divide(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;

    return a / b;
};
