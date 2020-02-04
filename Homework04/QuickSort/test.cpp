#include "gtest/gtest.h"
#include "QuickSort.h"
#include <vector>
#include <algorithm>

TEST(TestCaseName, TestQSortCallFunc01) {
	std::vector<int> v = { 73, 42, 12, 19 };
	std::vector<int> vExpected = { 12, 19, 42, 73 };

	auto vResult = quickSort(v);

	bool isSame = std::equal(vResult.begin(), vResult.end(), vExpected.begin());

	ASSERT_EQ(vResult.size(), vExpected.size());
	ASSERT_TRUE(isSame);
}

TEST(TestCaseName, TestQSortCallFunc02) {
	std::vector<int> v = { 1, 2, 3, 4, 9, 8, 7 };
	std::vector<int> vExpected = { 1, 2, 3, 4, 7, 8, 9 };

	auto vResult = quickSort(v);

	bool isSame = std::equal(vResult.begin(), vResult.end(), vExpected.begin());

	ASSERT_EQ(vResult.size(), vExpected.size());
	ASSERT_TRUE(isSame);
}

TEST(TestCaseName, TestQSortCallFunc03) {
	srand((size_t)0);
	int SIZE = 10'000;
	std::vector<int> v;
	v.reserve(SIZE);

	for (int i = 0; i < SIZE; ++i) {
		v.push_back(rand() % SIZE);
	}

	auto vResult = quickSort(v);

	bool isInOrder = true;
	for (int i = 0; i < vResult.size() - 1; ++i) {
		if (vResult[i] < vResult[i])
			isInOrder = false;
	}

	ASSERT_EQ(vResult.size(), v.size());
	ASSERT_TRUE(isInOrder);
}