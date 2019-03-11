#include "SequentialSearch.h"
#include"Tool.h"
int SequentialSearch(int* nums, int n, int data)
{
	if (n == 0) { return -1; }
	for (int i = 0; i < n; ++i)
	{
		if (nums[i] == data) { return i; }
	}
	return -1;
}
void Test_SequentialSearch()
{
	int nums[9] = { 8,2,4,5,3,10,11,6,9 };
	int n = 9;
	int testNum1 = 20, testNum2 = 10;

	PrintArray(nums, n);
	std::cout << "SequentialSearch:" << std::endl;
	std::cout << testNum1 << " is the " << SequentialSearch(nums, n, testNum1)
		<< "th num" << std::endl;
	std::cout << testNum2 << " is the " << SequentialSearch(nums, n, testNum2)
		<< "th num" << std::endl;
}
