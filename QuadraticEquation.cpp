#include "QuadraticEquation.h"
#include <cmath>
#include <stdexcept>

QuadraticResult QuadraticEquation::Solve(double a, double b, double c)
{
    if (a == 0)
    {
        throw std::invalid_argument("Coefficient 'a' cannot be zero.");
    }

    double delta = (b * b) - (4 * a * c);

    QuadraticResult result;

    if (delta < 0)
    {
        result.numberOfRoots = 0;
        result.x1 = 0;
        result.x2 = 0;
    }
    else if (delta == 0)
    {
        result.numberOfRoots = 1;
        result.x1 = -b / (2 * a);
        result.x2 = result.x1;
    }
    else
    {
        result.numberOfRoots = 2;

        result.x1 = (-b - sqrt(delta)) / (2 * a);
        result.x2 = (-b + sqrt(delta)) / (2 * a);
    }

    return result;
}