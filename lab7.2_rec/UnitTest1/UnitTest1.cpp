#include "pch.h"
#include "CppUnitTest.h"
#include "../lab7.2_rec/lab7.2_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 {
	TEST_CLASS(UnitTest1) {
public:
		TEST_METHOD(TestMethod1) {
			int arr[] = { 1,5,8,2,4 },
				index = IndexMax(arr, 5, arr[0], 0, 0);
			Assert::AreEqual(2, index);
		}
	};
}
