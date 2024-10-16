#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <algorithm>
#include <sstream> // Для роботи з потоками
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    std::string get_permutations(int n) {
        std::vector<int> permutation(n);
        for (int i = 0; i < n; ++i) {
            permutation[i] = i + 1;
        }

        std::ostringstream result;
        do {
            for (int i = 0; i < n; ++i) {
                result << permutation[i] << " ";
            }
            result << "\n";
        } while (std::next_permutation(permutation.begin(), permutation.end()));

        return result.str();
    }

    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            std::string expected = "1 2 3 \n1 3 2 \n2 1 3 \n2 3 1 \n3 1 2 \n3 2 1 \n";
            std::string actual = get_permutations(3);
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(TestMethod2)
        {
            std::string expected = "1 2 \n2 1 \n";
            std::string actual = get_permutations(2);
            Assert::AreEqual(expected, actual);
        }
    };
}
