#include "pch.h"
#include "CppUnitTest.h"

#include "../QuadraticEquationProject/QuadraticEquation.h"

using namespace Microsoft::VisualStudiocode::CppUnitTestFramework;

namespace QuadraticEquationTests
{
    TEST_CLASS(QuadraticEquationTests)
    {
    public:

        // Test: No real roots
        TEST_METHOD(NoRealRootsTest)
        {
            QuadraticResult result =
                QuadraticEquation::Solve(1, 0, 1);

            Assert::AreEqual(0, result.numberOfRoots);
        }

        // Test: One real root
        TEST_METHOD(OneRealRootTest)
        {
            QuadraticResult result =
                QuadraticEquation::Solve(1, 2, 1);

            Assert::AreEqual(1, result.numberOfRoots);

            Assert::AreEqual(-1.0, result.x1, 0.0001);
        }

        // Test: Two real roots
        TEST_METHOD(TwoRealRootsTest)
        {
            QuadraticResult result =
                QuadraticEquation::Solve(1, -3, 2);

            Assert::AreEqual(2, result.numberOfRoots);

            Assert::AreEqual(1.0, result.x1, 0.0001);
            Assert::AreEqual(2.0, result.x2, 0.0001);
        }

        // Test invalid coefficient a = 0
        TEST_METHOD(InvalidCoefficientTest)
        {
            Assert::ExpectException<std::invalid_argument>(
                []()
                {
                    QuadraticEquation::Solve(0, 2, 1);
                });
        }
    };
}