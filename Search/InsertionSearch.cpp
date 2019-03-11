#include "InsertionSearch.h"
#include"Tool.h"
#include"QuickSort.h"
int InsertionSearch(int* nums, int n, int data)
{
	if (n <= 0) { return -1; }
	int min = 0, max = n - 1, mid;
	while (min <= max)
	{
		mid = min + (data - nums[min]) / (nums[max] - nums[min])*(max - min);
		if (nums[mid] == data) { return mid; }
		else if (nums[mid] > data) { max = mid - 1; }
		else { min = mid + 1; }
	}
	return -1;
}
void Test_InsertionSearch()
{
	int nums[9] = { 8,2,4,5,3,10,11,6,9 };
	int n = 9;
	int testNum1 = 20, testNum2 = 10;
	QuickSort(nums, n);

	PrintArray(nums, n);
	std::cout << "InsertionSearch:" << std::endl;
	std::cout << testNum1 << " is the " << InsertionSearch(nums, n, testNum1)
		<< "th num" << std::endl;
	std::cout << testNum2 << " is the " << InsertionSearch(nums, n, testNum2)
		<< "th num" << std::endl;
}
