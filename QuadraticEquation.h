#pragma once
#include <string>

struct QuadraticResult
{
    int numberOfRoots;
    double x1;
    double x2;
};

class QuadraticEquation
{
public:
    static QuadraticResult Solve(double a, double b, double c);
};