#include "pch.h"
#include "CppUnitTest.h"
#include "../vectorDLL/Vector.h"
#include "../vectorDLL/pch.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			Vector vector1(2);
			Vector vector2(2);
			vector1[0] = 1;
			vector2[0] = 2;
			vector1[1] = 2;
			vector2[1] = 2;
			Vector sum = vector1 + vector2;
			Assert::IsTrue(sum[0] == 3 && sum[1] == 4);
		}

		TEST_METHOD(TestMethod2)
		{
			Vector vector1(1);
			Vector vector2(1);
			vector1[0] = 1;
			vector2[0] = 2;
			Vector diff = vector1 - vector2;
			Assert::IsTrue(diff[0] == -1);
		}

		TEST_METHOD(TestMethod3)
		{
			Vector vector(1);
			vector[0] = 1;
			Vector comp = vector * (double)3;
			Assert::IsTrue(comp[0] == (double)3);
		}

		TEST_METHOD(TestMethod4)
		{
			Vector vector(1);
			vector[0] = 1;
			Vector comp = (double)3 * vector;
			Assert::IsTrue(comp[0] == (double)3);
		}

		TEST_METHOD(TestMethod5)
		{
			Vector vector1(1);
			Vector vector2(1);
			vector1[0] = 1;
			vector2[0] = 1;
			Assert::IsTrue(vector1 == vector2);
		}

		TEST_METHOD(TestMethod6)
		{
			Vector vector1(1);
			Vector vector2(1);
			vector1[0] = 1;
			vector2[0] = 2;
			Assert::IsTrue(vector1 != vector2);
		}
		TEST_METHOD(TestMethod7)
		{
			Vector vector1(1);
			vector1[0] = 3;
			std::stringstream ss;
			ss << vector1;
			Assert::IsTrue(ss.str()._Equal("3"));
		}
		TEST_METHOD(TestMethod8)
		{
			Vector vector1(1);
			std::stringstream ss;
			ss << "4";
			ss >> vector1[0];
			Assert::IsTrue(vector1[0] == 4);
		}
	};
}
