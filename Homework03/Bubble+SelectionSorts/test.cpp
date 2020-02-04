#include "gtest/gtest.h"
#include <vector>
#include "sortFunctions.h"
#include <algorithm>

TEST(TestCaseName, TestBSsortCallFunc01) {
	std::vector<int> v = { 73, 42, 12, 19 };
	std::vector<int> vExpected = { 12, 19, 42, 73 };

	auto vResult = bsort(v);

	bool isSame = std::equal(vResult.begin(), vResult.end(), vExpected.begin());

	ASSERT_EQ(vResult.size(), vExpected.size());
	ASSERT_TRUE(isSame);
}

TEST(TestCaseName, TestBSsortCallFunc02) {
	std::vector<int> v = { 1, 2, 3, 4, 9, 8, 7 };
	std::vector<int> vExpected = { 1, 2, 3, 4, 7, 8, 9 };

	auto vResult = bsort(v);

	bool isSame = std::equal(vResult.begin(), vResult.end(), vExpected.begin());

	ASSERT_EQ(vResult.size(), vExpected.size());
	ASSERT_TRUE(isSame);
}

TEST(TestCaseName, TestSSsortCallFunc01) {
	std::vector<int> v = { 73, 42, 12, 19 };
	std::vector<int> vExpected = { 12, 19, 42, 73 };

	auto vResult = selectionSort(v);

	bool isSame = std::equal(vResult.begin(), vResult.end(), vExpected.begin());

	ASSERT_EQ(vResult.size(), vExpected.size());
	ASSERT_TRUE(isSame);
}

TEST(TestCaseName, TestSSsortCallFunc02) {
	std::vector<int> v = { 1, 2, 3, 4, 9, 8, 7 };
	std::vector<int> vExpected = { 1, 2, 3, 4, 7, 8, 9 };

	auto vResult = selectionSort(v);

	bool isSame = std::equal(vResult.begin(), vResult.end(), vExpected.begin());

	ASSERT_EQ(vResult.size(), vExpected.size());
	ASSERT_TRUE(isSame);
}